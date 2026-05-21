"""
Source2Toolkit
Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
AlliedModders LLC. All rights reserved.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 3.0, as published by the
Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
AlliedModders LLC give you permission to link the code of this program
(as well as its derivative works) to "Counter-Strike 2," "Source 2,"
"Steam," and any Game MODs or server software running on software by
Valve Corporation. You must obey the GNU General Public License in all
respects for all other code used.

Additionally, this exception applies to all derivative works unless
otherwise stated in LICENSE.txt.

Authors:
    - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
    - AlliedModders LLC

Project: Source2Toolkit

Schema generator – Python port of the C# schemagen tool.
Original: tools/schemagen/Program.cs (and related files)

Usage:
    python generator.py [output_path]

Default output_path: ../../public/source2toolkit/schema/entity
Reads server.json from the same directory as this script.
"""

from __future__ import annotations

import json
import os
import re
import sys
from collections import deque
from dataclasses import dataclass, field
from enum import Enum, auto
from typing import Optional

LICENSE_HEADER = """\
/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
 * AlliedModders LLC. All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
 * AlliedModders LLC give you permission to link the code of this program
 * (as well as its derivative works) to "Counter-Strike 2," "Source 2,"
 * "Steam," and any Game MODs or server software running on software by
 * Valve Corporation. You must obey the GNU General Public License in all
 * respects for all other code used.
 *
 * Additionally, this exception applies to all derivative works unless
 * otherwise stated in LICENSE.txt.
 *
 * Authors:
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

"""

# ---------------------------------------------------------------------------
# Enums
# ---------------------------------------------------------------------------

class SchemaTypeCategory(Enum):
    Builtin = 0
    Ptr = 1
    Bitfield = 2
    FixedArray = 3
    Atomic = 4
    DeclaredClass = 5
    DeclaredEnum = 6
    NoneType = 7

class SchemaAtomicCategory(Enum):
    Basic = 0
    T = 1
    Collection = 2
    TT = 3
    I = 4
    Unknown = 5
    NoneAtomic = 6

# ---------------------------------------------------------------------------
# JSON input model
# ---------------------------------------------------------------------------

@dataclass
class SchemaMetaTag:
    name: str
    value: Optional[str]

@dataclass
class SchemaBaseClass:
    offset: int
    ref_idx: int

@dataclass
class SchemaSubtype:
    type: str
    name: Optional[str]
    size: Optional[int]
    alignment: Optional[int]
    template: Optional[list[SchemaSubtype]]
    ref_idx: Optional[int]
    element_size: Optional[int]
    count: Optional[int]
    subtype: Optional[SchemaSubtype]

    @staticmethod
    def from_dict(d: dict) -> SchemaSubtype:
        template = [SchemaSubtype.from_dict(t) for t in d["template"]] if d.get("template") else None
        subtype = SchemaSubtype.from_dict(d["subtype"]) if d.get("subtype") else None
        return SchemaSubtype(
            type=d.get("type", ""),
            name=d.get("name"),
            size=d.get("size"),
            alignment=d.get("alignment"),
            template=template,
            ref_idx=d.get("ref_idx"),
            element_size=d.get("element_size"),
            count=d.get("count"),
            subtype=subtype,
        )

@dataclass
class MemberTraits:
    metatags: Optional[list[SchemaMetaTag]]
    subtype: Optional[SchemaSubtype]

@dataclass
class SchemaMember:
    name: str
    offset: int
    traits: Optional[MemberTraits]

@dataclass
class SchemaEnumField:
    name: str
    value: int

@dataclass
class SchemaTraits:
    baseclasses: Optional[list[SchemaBaseClass]]
    members: Optional[list[SchemaMember]]
    fields: Optional[list[SchemaEnumField]]

@dataclass
class SchemaDef:
    type: str
    name: str
    size: Optional[int]
    alignment: Optional[int]
    traits: Optional[SchemaTraits]

def _parse_schema_defs(raw_defs: list[dict]) -> list[SchemaDef]:
    result = []
    for d in raw_defs:
        traits = None
        if raw_traits := d.get("traits"):
            baseclasses = None
            if raw_bc := raw_traits.get("baseclasses"):
                baseclasses = [SchemaBaseClass(b["offset"], b["ref_idx"]) for b in raw_bc]
            members = None
            if raw_members := raw_traits.get("members"):
                members = []
                for m in raw_members:
                    mt = None
                    if raw_mt := m.get("traits"):
                        metatags = None
                        if raw_tags := raw_mt.get("metatags"):
                            metatags = [SchemaMetaTag(t["name"], t.get("value")) for t in raw_tags]
                        sub = SchemaSubtype.from_dict(raw_mt["subtype"]) if raw_mt.get("subtype") else None
                        mt = MemberTraits(metatags, sub)
                    members.append(SchemaMember(m["name"], m["offset"], mt))
            enum_fields = None
            if raw_fields := raw_traits.get("fields"):
                enum_fields = [SchemaEnumField(f["name"], f["value"]) for f in raw_fields]
            traits = SchemaTraits(baseclasses, members, enum_fields)
        result.append(SchemaDef(d["type"], d["name"], d.get("size"), d.get("alignment"), traits))
    return result

# ---------------------------------------------------------------------------
# Intermediate model
# ---------------------------------------------------------------------------

@dataclass
class SchemaEnumItem:
    name: str
    value: int

@dataclass
class SchemaEnum:
    align: int
    items: list[SchemaEnumItem]

@dataclass
class SchemaFieldType:
    name: str
    category: SchemaTypeCategory
    atomic: Optional[SchemaAtomicCategory]
    inner: Optional[SchemaFieldType]

    def __post_init__(self):
        # Type normalizations
        if self.name == "VectorWS":
            self.name = "Vector"

        if self.name == "CTransformWS":
            self.name = "CTransform"
        elif self.name == "CNetworkVarChainer":
            self.name = "CEntityInstance*"

        if self.name in ("GameTime_t", "CNetworkedQuantizedFloat"):
            self.category = SchemaTypeCategory.Builtin
            self.name = "float32"
        elif self.name in ("CPlayerSlot", "HSequence", "CSplitScreenSlot", "GameTick_t"):
            self.category = SchemaTypeCategory.Builtin
            self.name = "int32"
        elif self.name == "AmmoIndex_t":
            self.category = SchemaTypeCategory.Builtin
            self.name = "uint8"
        elif self.name == "CBitVec":
            self.name = "CBitVec<64>"
        elif self.name == "CTypedBitVec":
            self.name = "CTypedBitVec<64>"

    @property
    def is_string(self) -> bool:
        return (
            self.category in (SchemaTypeCategory.FixedArray, SchemaTypeCategory.Ptr)
            and self.inner is not None
            and self.inner.category == SchemaTypeCategory.Builtin
            and self.inner.name == "char"
        )

    @property
    def is_declared(self) -> bool:
        return self.category in (SchemaTypeCategory.DeclaredClass, SchemaTypeCategory.DeclaredEnum)

    @property
    def array_size(self) -> Optional[int]:
        if self.category == SchemaTypeCategory.FixedArray:
            m = re.search(r"\[(\d+)\]$", self.name)
            return int(m.group(1)) if m else None
        return None

    @staticmethod
    def _builtin_to_cpp(name: str) -> str:
        return {
            "float32": "float",
            "float64": "double",
            "int8": "int8_t",
            "int16": "int16_t",
            "int32": "int32_t",
            "int64": "int64_t",
            "uint8": "uint8_t",
            "uint16": "uint16_t",
            "uint32": "uint32_t",
            "uint64": "uint64_t",
            "bool": "bool",
            "char": "char",
        }.get(name, name)

    @staticmethod
    def _atomic_to_cpp(name: str, atomic: SchemaAtomicCategory, inner: Optional[SchemaFieldType]) -> str:
        if atomic == SchemaAtomicCategory.Basic:
            return name
        if atomic == SchemaAtomicCategory.T:
            base = name.split("<")[0]
            return f"{base}<{inner.cpp_type_name}>"
        if atomic == SchemaAtomicCategory.Collection:
            return f"CUtlVector<{inner.cpp_type_name}>"
        return name

    @property
    def cpp_type_name(self) -> str:
        cat = self.category
        if cat == SchemaTypeCategory.Builtin:
            return self._builtin_to_cpp(self.name)
        if cat in (SchemaTypeCategory.DeclaredClass, SchemaTypeCategory.DeclaredEnum):
            return self.name
        if cat == SchemaTypeCategory.Atomic:
            return self._atomic_to_cpp(self.name, self.atomic, self.inner)
        if cat == SchemaTypeCategory.FixedArray:
            return self.inner.cpp_type_name
        if cat == SchemaTypeCategory.Ptr:
            return self.inner.cpp_type_name + "*"
        return "void"

@dataclass
class SchemaField:
    name: str
    type: SchemaFieldType
    metadata: dict[str, str]

@dataclass
class SchemaClass:
    index: int
    name: str
    parent: Optional[str]
    fields: list[SchemaField]

# ---------------------------------------------------------------------------
# Configuration – lists copied verbatim from C# source
# ---------------------------------------------------------------------------

IGNORE_CLASSES: frozenset[str] = frozenset({
    "GameTime_t",
    "GameTick_t",
    "AttachmentHandle_t",
    "CGameSceneNodeHandle",
    "HSequence",
    "CAttributeManager::cached_attribute_float_t",
    "QuestProgress::Reason",
    "IChoreoServices::ScriptState_t",
    "IChoreoServices::ChoreoState_t",
    "SpawnPointCoopEnemy::BotDefaultBehavior_t",
    "CLogicBranchList::LogicBranchListenerLastState_t",
    "SimpleConstraintSoundProfile::SimpleConstraintsSoundProfileKeypoints_t",
    "MoodAnimationLayer_t",
    "SoundeventPathCornerPairNetworked_t",
    "AISound_t",
    "CAttachmentNameSymbolWithStorage",
    "CAnimGraph2ParamAutoResetOptionalRef",
})

IGNORE_CLASS_WILDCARDS: tuple[str, ...] = (
    "CResourceNameTyped",
    "CEntityOutputTemplate",
    "CVariantBase",
    "HSCRIPT",
    "KeyValues3",
    "Unknown",
    "CUtlOrderedMap",
    "CAnimGraph2ParamOptionalRef",
    "CUtlHashtable",
    "CSmartPtr",
)

HARD_SKIP_CLASSES: frozenset[str] = frozenset({
    "CEntityComponent",
    "CEntityIOOutput",
    "CEntityIdentity",
    "CEntityInstance",
})

HARD_SKIP_ENUMS: frozenset[str] = frozenset({
    "HitGroup_t",
    "MoveCollide_t",
    "MoveType_t",
    "RenderFx_t",
    "RenderMode_t",
    "SolidType_t",
})

NETWORK_CLASSES: list[str] = [
    "CAK47", "CBarnLight", "CBaseAnimGraph", "CBaseButton", "CBaseClientUIEntity",
    "CBaseCombatCharacter", "CBaseCSGrenade", "CBaseCSGrenadeProjectile", "CBaseDoor",
    "CBaseEntity", "CBaseFlex", "CBaseGrenade", "CBaseModelEntity", "CBasePlayerController",
    "CBasePlayerPawn", "CBasePlayerWeapon", "CBasePropDoor", "CBaseToggle", "CBaseTrigger",
    "CBeam", "CBombTarget", "CBreakable", "CBreakableProp", "CC4", "CChicken",
    "CColorCorrection", "CColorCorrectionVolume", "CCSGameRulesProxy",
    "CCSGO_TeamIntroCharacterPosition", "CCSGO_TeamIntroCounterTerroristPosition",
    "CCSGO_TeamIntroTerroristPosition", "CCSGO_TeamPreviewCharacterPosition",
    "CCSGO_TeamSelectCharacterPosition", "CCSGO_TeamSelectCounterTerroristPosition",
    "CCSGO_TeamSelectTerroristPosition", "CCSGO_WingmanIntroCharacterPosition",
    "CCSGO_WingmanIntroCounterTerroristPosition", "CCSGO_WingmanIntroTerroristPosition",
    "CCSMinimapBoundary", "CCSObserverPawn", "CCSPlayerController", "CCSPlayerPawn",
    "CCSPlayerPawnBase", "CCSPlayerResource", "CCSTeam", "CCSWeaponBase", "CCSWeaponBaseGun",
    "CDEagle", "CDecoyGrenade", "CDecoyProjectile", "CDynamicLight", "CDynamicProp",
    "CEconEntity", "CEconWearable", "CEntityDissolve", "CEntityFlame",
    "CEnvCombinedLightProbeVolume", "CEnvCubemap", "CEnvCubemapBox", "CEnvCubemapFog",
    "CEnvDecal", "CEnvDetailController", "CEnvLightProbeVolume", "CEnvParticleGlow",
    "CEnvSky", "CEnvVolumetricFogController", "CEnvVolumetricFogVolume", "CEnvWind",
    "CFireCrackerBlast", "CFish", "CFlashbang", "CFogController", "CFootstepControl",
    "CFuncBrush", "CFuncConveyor", "CFuncElectrifiedVolume", "CFuncLadder", "CFuncMonitor",
    "CFuncMoveLinear", "CFuncRotating", "CFuncTrackTrain", "CFuncWater", "CGameRulesProxy",
    "CGradientFog", "CHandleTest", "CHEGrenade", "CHostage", "CHostageCarriableProp",
    "CHostageRescueZone", "CIncendiaryGrenade", "CInferno",
    "CInfoInstructorHintHostageRescueZone", "CInfoLadderDismount",
    "CInfoOffscreenPanoramaTexture", "CInfoVisibilityBox", "CInfoWorldLayer",
    "CItem_Healthshot", "CItemDogtags", "CKnife", "CLightDirectionalEntity", "CLightEntity",
    "CLightEnvironmentEntity", "CLightOrthoEntity", "CLightSpotEntity",
    "CMapVetoPickController", "CModelPointEntity", "CMolotovGrenade", "CMolotovProjectile",
    "COmniLight", "CParticleSystem", "CPathParticleRope", "CPhysBox", "CPhysicsProp",
    "CPhysicsPropMultiplayer", "CPhysMagnet", "CPlantedC4", "CPlayerPing",
    "CPlayerSprayDecal", "CPlayerVisibility", "CPointCamera", "CPointClientUIDialog",
    "CPointClientUIWorldPanel", "CPointClientUIWorldTextPanel", "CPointCommentaryNode",
    "CPointEntity", "CPointValueRemapper", "CPointWorldText", "CPostProcessingVolume",
    "CPrecipitation", "CPrecipitationBlocker", "CRagdollManager", "CRagdollProp",
    "CRagdollPropAttached", "CRectLight", "CRopeKeyframe", "CSceneEntity",
    "CShatterGlassShardPhysics", "CSkyCamera", "CSmokeGrenade", "CSmokeGrenadeProjectile",
    "CSoundAreaEntityBase", "CSoundAreaEntityOrientedBox", "CSoundAreaEntitySphere",
    "CSoundOpvarSetAABBEntity", "CSoundOpvarSetOBBEntity", "CSoundOpvarSetOBBWindEntity",
    "CSoundOpvarSetPathCornerEntity", "CSoundOpvarSetPointBase", "CSoundOpvarSetPointEntity",
    "CSpotlightEnd", "CSprite", "CSpriteOriented", "CTeam", "CTextureBasedAnimatable",
    "CTonemapController2", "CTriggerBuoyancy", "CTriggerVolume", "CVoteController",
    "CWaterBullet", "CWeaponAug", "CWeaponAWP", "CWeaponBaseItem", "CWeaponBizon",
    "CWeaponElite", "CWeaponFamas", "CWeaponFiveSeven", "CWeaponG3SG1", "CWeaponGalilAR",
    "CWeaponGlock", "CWeaponHKP2000", "CWeaponM249", "CWeaponM4A1", "CWeaponMAC10",
    "CWeaponMag7", "CWeaponMP7", "CWeaponMP9", "CWeaponNegev", "CWeaponNOVA",
    "CWeaponP250", "CWeaponP90", "CWeaponSawedoff", "CWeaponSCAR20", "CWeaponSG556",
    "CWeaponSSG08", "CWeaponTaser", "CWeaponTec9", "CWeaponUMP45", "CWeaponXM1014",
    "CWorld",
]

MANUAL_METHODS: dict[str, list[str]] = {
    "CBaseEntity": [
        "/// <summary>Creates entity by classname.</summary>",
        "static CBaseEntity* CreateEntityByName(const char* pszClassName);",
        "/// <summary>Create entity by classname.</summary>",
        "template<typename T>\n    static T* New(const char* pszClassName)\n    {    \n        return reinterpret_cast<T*>(CreateEntityByName(pszClassName));\n    }",
        "/// <summary>Get entity by index.</summary>",
        "template<typename T>\n    static T* FromIndex(int iIndex)\n    {    \n        return reinterpret_cast<T*>(GetEntitySystem()->GetEntityInstance(CEntityIndex(iIndex)));\n    }",
        "/// <summary>Get entity by entity index.</summary>",
        "template<typename T>\n    static T* FromIndex(CEntityIndex index)\n    {    \n        return FromIndex<T>(index.Get());\n    }",
        "/// <summary>Accepts entity input.</summary>",
        'void AcceptInput(const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = "");',
        "/// <summary>Add delayed entity IO event.</summary>",
        'void AddEntityIOEvent(const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = "", float flDelay = 0.0f);',
        "/// <summary>Add signle entity IO listener.</summary>",
        "CEntityIOListenerHandle* AddSingleEntityIOListener(const char* pszOutput, std::function<Action(const char*,CEntityInstance*, CEntityInstance*, float, Mode)> callback, Mode mode);",
        "/// <summary>Get absolute origin.</summary>",
        "Vector GetAbsOrigin();",
        "/// <summary>Get local rotation.</summary>",
        "QAngle GetAngRotation();",
        "/// <summary>Get absolute rotation.</summary>",
        "QAngle GetAbsRotation();",
        "/// <summary>Get absolute velocity.</summary>",
        "Vector GetAbsVelocity();",
        "/// <summary>Set absolute origin.</summary>",
        "void SetAbsOrigin(Vector vecOrigin);",
        "/// <summary>Set absolute rotation.</summary>",
        "void SetAbsRotation(QAngle angAbsRotation);",
        "/// <summary>Set local rotation.</summary>",
        "void SetAngRotation(QAngle angRotation);",
        "/// <summary>Set absolute velocity.</summary>",
        "void SetAbsVelocity(Vector vecVelocity);",
        "/// <summary>Set base velocity.</summary>",
        "void SetBaseVelocity(Vector vecVelocity);",
        "/// <summary>Get entity VData.</summary>",
        "CEntitySubclassVDataBase* GetVData();",
        "/// <summary>Spawn entity.</summary>",
        "void DispatchSpawn(CEntityKeyValues* pEntityKeyValues = nullptr);",
        "/// <summary>Teleport entity.</summary>",
        "void Teleport(const Vector* pPosition, const QAngle* pAngles, const Vector* pVelocity);",
        "/// <summary>Set move type.</summary>",
        "void SetMoveType(MoveType_t nMoveType);",
        "/// <summary>Get collision group.</summary>",
        "uint8 GetCollisionGroup();",
        "/// <summary>Set collision group.</summary>",
        "void SetCollisionGroup(uint8 nCollisionGroup);",
        "/// <summary>Notify collision rules changed.</summary>",
        "void CollisionRulesChanged();",
        "/// <summary>Get entity index.</summary>",
        "int GetIndex();",
        "/// <summary>Get entity handle.</summary>",
        "CHandle<CBaseEntity> GetHandle();",
        "/// <summary>Get entity name.</summary>",
        "const char* GetName() const;",
    ],
    "CBaseModelEntity": [
        "/// <summary>Get model name.</summary>",
        "CUtlSymbolLarge GetModelName();",
        "/// <summary>Get eye position.</summary>",
        "Vector GetEyePosition();",
        "/// <summary>Set entity model.</summary>",
        "void SetModel(const char* pszModel);",
    ],
    "CBasePlayerController": [
        "/// <summary>Set pawn for controller.</summary>",
        "void SetPawn(CBasePlayerPawn* pPawn);",
    ],
    "CBasePlayerPawn": [
        "/// <summary>Force suicide.</summary>",
        "void CommitSuicide(bool bExplode, bool bForce);",
        "/// <summary>Remove weapon from player.</summary>",
        "void RemovePlayerItem(CBasePlayerWeapon* pWeapon);",
    ],
    "CBasePlayerWeapon": [
        "/// <summary>Get weapon VData.</summary>",
        "CCSWeaponBaseVData* GetWeaponVData();",
        "/// <summary>Get weapon classname.</summary>",
        "const char* GetWeaponClassname();",
    ],
    "CCSGameRules": [
        "/// <summary>Terminate round.</summary>",
        "void TerminateRound(float flDelay, int32_t eRoundEndReason);",
        "/// <summary>Find entity player is aiming at.</summary>",
        "CBaseEntity* FindPickerEntity(CBasePlayerController* pPlayer);",
        "/// <summary>Get aim target.</summary>",
        "CCSPlayerController* GetClientAimTarget(CCSPlayerController* pPlayer);",
    ],
    "CCSPlayerController": [
        "/// <summary>Get controller from pawn.</summary>",
        "static CCSPlayerController* FromPawn(CCSPlayerPawn* pPawn);",
        "/// <summary>Get controller from slot.</summary>",
        "static CCSPlayerController* FromSlot(int iSlot);",
        "/// <summary>Get controller from slot.</summary>",
        "static CCSPlayerController* FromSlot(CPlayerSlot slot);",
        "/// <summary>Get controller from user id.</summary>",
        "static CCSPlayerController* FromUserId(int iUserId);",
        "/// <summary>Get controller from user id.</summary>",
        "static CCSPlayerController* FromUserId(CPlayerUserId userId);",
        "/// <summary>Get controller from steam id.</summary>",
        "static CCSPlayerController* FromSteamId(uint64 uSteamId);",
        "/// <summary>Get controller from steam id.</summary>",
        "static CCSPlayerController* FromSteamId(CSteamID steamId);",
        "/// <summary>Print to console.</summary>",
        "void PrintToConsole(const char* pszMessage);",
        "/// <summary>Print to chat.</summary>",
        "void PrintToChat(const char* pszMessage);",
        "/// <summary>Print to center.</summary>",
        "void PrintToCenter(const char* pszMessage);",
        "/// <summary>Print alert.</summary>",
        "void PrintToCenterAlert(const char* pszMessage);",
        "/// <summary>Print to center in HTML.</summary>",
        "void PrintToCenterHtml(const char* pszMessage, int iDuration = 5);",
        "/// <summary>Take damage from player</summary>",
        "void TakeDamage(CCSPlayerController* pAttacker, int iDamage, DamageTypes_t bitsDamageType);",
        "/// <summary>Respawn player.</summary>",
        "void Respawn();",
        "/// <summary>Switch team without killing.</summary>",
        "void SwitchTeam(int nTeam);",
        "/// <summary>Change team like jointeam.</summary>",
        "void ChangeTeam(int nTeam);",
        "/// <summary>Is bot.</summary>",
        "bool IsBot();",
        "/// <summary>Disconnect player.</summary>",
        "void Disconnect(ENetworkDisconnectionReason eReason);",
        "/// <summary>Execute client command.</summary>",
        "void ExecuteClientCommand(const char* pszCommand);",
        "/// <summary>Execute command from server.</summary>",
        "void ExecuteClientCommandFromServer(const char* pszCommand);",
        "/// <summary>Get pawn.</summary>",
        "CCSPlayerPawn* GetPawn();",
        "/// <summary>Get player pawn.</summary>",
        "CCSPlayerPawn* GetPlayerPawn();",
        "/// <summary>Get observer pawn.</summary>",
        "CCSObserverPawn* GetObserverPawn();",
        "/// <summary>Get player index.</summary>",
        "CEntityIndex GetPlayerIndex();",
        "/// <summary>Get slot.</summary>",
        "int GetSlot();",
        "/// <summary>Get player slot.</summary>",
        "CPlayerSlot GetPlayerSlot();",
        "/// <summary>Get steamid.</summary>",
        "int GetUserID();",
        "/// <summary>Get player userid.</summary>",
        "CPlayerUserId GetPlayerUserID();",
        "/// <summary>Get steamid.</summary>",
        "uint64 GetSteamID();",
        "/// <summary>Get player steamid.</summary>",
        "CSteamID GetPlayerSteamID();",
        "/// <summary>Get player name.</summary>",
        "const char* GetPlayerName();",
        "/// <summary>Get IP address.</summary>",
        "CUtlString GetIpAddress();",
        "/// <summary>Replicate convar.</summary>",
        "void ReplicateConVar(const char* pszConVar, const char* pszValue);",
        "/// <summary>Fires gameEvent to client's legacy listener.</summary>",
        "void FireEventToClient(IGameEvent* pEvent);",
    ],
    "CCSPlayerPawn": [
        "/// <summary>Get controller.</summary>",
        "CCSPlayerController* GetController();",
        "/// <summary>Get default controller.</summary>",
        "CCSPlayerController* GetDefaultController();",
        "/// <summary>Get original controller.</summary>",
        "CCSPlayerController* GetOriginalController();",
    ],
    "CCSPlayer_ItemServices": [
        "/// <summary>Drop active weapon, recommended to use DropWeapon instead (parameter is ignored here)</summary>",
        "void DropActivePlayerWeapon(CBasePlayerWeapon* pActiveWeapon);",
        "/// <summary>Remove all weapons.</summary>",
        "void RemoveWeapons();",
        "/// <summary>Give item.</summary>",
        "CBasePlayerWeapon* GiveNamedItem(const char* pszItem);",
    ],
    "CCSPlayer_WeaponServices": [
        "/// <summary>Drop weapon.</summary>",
        "void DropWeapon(CBasePlayerWeapon *pWeapon, Vector *pVecTarget = nullptr, Vector *pVelocity = nullptr);",
        "/// <summary>Select weapon.</summary>",
        "void SelectWeapon(CBasePlayerWeapon *pWeapon, int unk1 = 0);"
    ],
    "CPlayerControllerComponent": [
        "/// <summary>Get player controller.</summary>",
        "CCSPlayerController* GetPlayerController();",
    ],
    "CPlayerPawnComponent": [
        "/// <summary>Get player pawn.</summary>",
        "CCSPlayerPawn* GetPlayerPawn();",
    ],
    "CTakeDamageInfo": [
        "/// <summary>Construct info with default members.</summary>",
        "CTakeDamageInfo();",
        "/// <summary>Construct info with correctly set members.</summary>",
        "CTakeDamageInfo(CBaseEntity* pInflictor, CBaseEntity* pAttacker, CBaseEntity* pAbility, float flDamage, DamageTypes_t bitsDamageType);",
        "/// <summary>Get actual hitgroup.</summary>",
        "HitGroup_t GetHitGroup() const;",
    ],
}

# Classes manually whitelisted after BFS
EXTRA_WHITELIST: frozenset[str] = frozenset({
    "CTakeDamageInfo",
    "CTakeDamageResult",
    "CEntitySubclassVDataBase",
    "CFiringModeFloat",
    "CFiringModeInt",
    "CSkillFloat",
    "CSkillInt",
    "CRangeFloat",
    "CNavLinkAnimgraphVar",
    "DecalGroupOption_t",
    "DestructibleHitGroupToDestroy_t",
})

# ---------------------------------------------------------------------------
# Helper functions
# ---------------------------------------------------------------------------

def sanitise_type_name(name: str) -> str:
    return name.replace(":", "").replace("< ", "<").replace(" >", ">")

def contains_ignored_type(t: SchemaFieldType) -> bool:
    if t.name in IGNORE_CLASSES:
        return True
    if t.inner is not None:
        return contains_ignored_type(t.inner)
    return False

def _field_has_ignored_wildcard(t: SchemaFieldType) -> bool:
    return any(w in t.name for w in IGNORE_CLASS_WILDCARDS)

# ---------------------------------------------------------------------------
# Schema conversion
# ---------------------------------------------------------------------------

def convert_subtype_to_field_type(
    subtype: SchemaSubtype,
    def_lookup: dict[int, SchemaDef],
) -> SchemaFieldType:
    if subtype.type == "ref" and subtype.ref_idx is not None:
        ref_def = def_lookup.get(subtype.ref_idx)
        if ref_def is not None:
            resolved_type = (
                "declared_class" if ref_def.type == "class"
                else ("declared_enum" if ref_def.type == "enum" else ref_def.type)
            )
            return convert_subtype_to_field_type(
                SchemaSubtype(
                    type=resolved_type,
                    name=ref_def.name,
                    size=ref_def.size,
                    alignment=ref_def.alignment,
                    template=None,
                    ref_idx=None,
                    element_size=None,
                    count=None,
                    subtype=None,
                ),
                def_lookup,
            )

    category = {
        "builtin": SchemaTypeCategory.Builtin,
        "atomic": SchemaTypeCategory.Atomic,
        "ptr": SchemaTypeCategory.Ptr,
        "fixed_array": SchemaTypeCategory.FixedArray,
        "declared_class": SchemaTypeCategory.DeclaredClass,
        "declared_enum": SchemaTypeCategory.DeclaredEnum,
        "bitfield": SchemaTypeCategory.Bitfield,
    }.get(subtype.type, SchemaTypeCategory.NoneType)

    atomic: Optional[SchemaAtomicCategory] = None
    if subtype.type == "atomic" and subtype.name:
        name = subtype.name
        if "CUtlVector" in name or "CNetworkUtlVectorBase" in name:
            atomic = SchemaAtomicCategory.Collection
        elif "CHandle" in name or "CWeakHandle" in name or "CStrongHandle" in name:
            atomic = SchemaAtomicCategory.T
        else:
            atomic = SchemaAtomicCategory.Basic

    inner: Optional[SchemaFieldType] = None
    if subtype.template:
        inner = convert_subtype_to_field_type(subtype.template[0], def_lookup)
    elif subtype.subtype is not None:
        inner = convert_subtype_to_field_type(subtype.subtype, def_lookup)

    type_name = subtype.name or "unknown"
    if category == SchemaTypeCategory.FixedArray and subtype.count is not None and inner is not None:
        type_name = f"{inner.name}[{subtype.count}]"

    return SchemaFieldType(type_name, category, atomic, inner)

def convert_new_schema_to_old(
    defs: list[SchemaDef],
) -> tuple[dict[str, SchemaEnum], dict[str, SchemaClass]]:
    enums: dict[str, SchemaEnum] = {}
    classes: dict[str, SchemaClass] = {}
    def_lookup: dict[int, SchemaDef] = {i: d for i, d in enumerate(defs)}

    for def_ in defs:
        if def_.type == "enum" and def_.traits and def_.traits.fields:
            items = [SchemaEnumItem(f.name, f.value) for f in def_.traits.fields]
            enums[def_.name] = SchemaEnum(def_.alignment or 4, items)

    for i, def_ in enumerate(defs):
        if def_.type == "class" and def_.traits is not None:
            parent_name: Optional[str] = None
            if def_.traits.baseclasses:
                parent_idx = def_.traits.baseclasses[0].ref_idx
                parent_def = def_lookup.get(parent_idx)
                if parent_def:
                    parent_name = parent_def.name

            fields: list[SchemaField] = []
            if def_.traits.members:
                for member in def_.traits.members:
                    if member.traits and member.traits.subtype:
                        ft = convert_subtype_to_field_type(member.traits.subtype, def_lookup)
                        metadata = (
                            {t.name: t.value or "" for t in member.traits.metatags}
                            if member.traits.metatags else {}
                        )
                        fields.append(SchemaField(member.name, ft, metadata))

            classes[def_.name] = SchemaClass(i, def_.name, parent_name, fields)

    return enums, classes

# ---------------------------------------------------------------------------
# Graph / BFS
# ---------------------------------------------------------------------------

def build_graph_and_bfs(
    all_classes: dict[str, SchemaClass],
) -> set[str]:
    # adjacency list: class -> set of reachable names
    graph: dict[str, set[str]] = {}

    def add_edge(src: str, dst: str) -> None:
        graph.setdefault(src, set()).add(dst)

    parent_to_children: dict[str, list[str]] = {}
    for name, cls in all_classes.items():
        if cls.parent:
            parent_to_children.setdefault(cls.parent, []).append(name)

    for class_name, cls in all_classes.items():
        if cls.parent:
            add_edge(class_name, cls.parent)

        for f in cls.fields:
            cur = f.type
            while cur is not None:
                if cur.is_declared:
                    add_edge(class_name, cur.name)
                cur = cur.inner

            if f.type.category == SchemaTypeCategory.Ptr and f.type.inner:
                ptr_target = f.type.inner.name
                queue: deque[tuple[str, str]] = deque(
                    (class_name, child)
                    for child in parent_to_children.get(ptr_target, [])
                )
                while queue:
                    parent, child = queue.popleft()
                    add_edge(parent, child)
                    for grandchild in parent_to_children.get(child, []):
                        queue.append((child, grandchild))

    # BFS from each NetworkClass
    visited: set[str] = set()

    def bfs(start: str) -> None:
        if start not in graph:
            return
        q: deque[str] = deque([start])
        while q:
            node = q.popleft()
            if node in visited:
                continue
            visited.add(node)
            for neighbor in graph.get(node, ()):
                if neighbor not in visited:
                    q.append(neighbor)

    for nc in NETWORK_CLASSES:
        bfs(nc)

    return visited

# ---------------------------------------------------------------------------
# Code generation helpers
# ---------------------------------------------------------------------------

def make_header_guard(name: str) -> str:
    safe = sanitise_type_name(name).replace("<", "").replace(">", "").replace(" ", "_")
    return f"_INCLUDE_{safe.upper()}_H"

def _enum_type_cpp(align: int, items: list[SchemaEnumItem]) -> str:
    is_signed = any(it.value < 0 for it in items)
    table = {
        (1, True): "int8_t",
        (1, False): "uint8_t",
        (2, True): "int16_t",
        (2, False): "uint16_t",
        (4, True): "int32_t",
        (4, False): "uint32_t",
        (8, True): "int64_t",
        (8, False): "uint64_t",
    }
    return table.get((align, is_signed), "int32_t")

def write_enum(enum_name: str, schema_enum: SchemaEnum) -> str:
    underlying = _enum_type_cpp(schema_enum.align, schema_enum.items)
    guard = make_header_guard(enum_name)
    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#pragma once",
        "",
        "#include <cstdint>",
        "",
        f"enum class {enum_name} : {underlying}",
        "{",
    ]
    for item in schema_enum.items:
        lines.append(f"    {item.name} = {item.value},")
    lines.append("};")
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")
    return LICENSE_HEADER + "\r\n".join(lines)

def collect_referenced_types(
    t: SchemaFieldType,
    includes: set[str],
    forwards: set[str],
    is_pointer_context: bool,
) -> None:
    if t.category == SchemaTypeCategory.DeclaredEnum and t.name in HARD_SKIP_ENUMS:
        return

    is_handle_template = t.atomic == SchemaAtomicCategory.T

    if t.is_declared and t.name not in HARD_SKIP_CLASSES:
        if is_pointer_context or is_handle_template:
            forwards.add(t.name)
        else:
            includes.add(t.name)

    if t.inner is not None:
        inner_is_pointer = t.category == SchemaTypeCategory.Ptr or is_handle_template
        collect_referenced_types(t.inner, includes, forwards, inner_is_pointer)

def collect_types_from_methods(
    methods: list[str],
    all_enums: dict[str, SchemaEnum],
    all_classes: dict[str, SchemaClass],
    includes: set[str],
    forwards: set[str],
) -> None:
    for method in methods:
        for cls_name in all_classes:
            if cls_name in method:
                if cls_name not in includes:
                    forwards.add(cls_name)
        for enum_name in all_enums:
            if enum_name in method:
                includes.add(enum_name)

def inherits_from_base_entity(
    class_name: str,
    all_classes: dict[str, SchemaClass],
) -> bool:
    while True:
        cls = all_classes.get(class_name)
        if cls is None or cls.parent is None:
            return False
        if cls.parent == "CBaseEntity":
            return True
        class_name = cls.parent

def write_class(
    class_name: str,
    schema_class: SchemaClass,
    all_enums: dict[str, SchemaEnum],
    all_classes: dict[str, SchemaClass],
) -> str:
    includes: set[str] = set()
    forwards: set[str] = set()

    if schema_class.parent and schema_class.parent not in HARD_SKIP_CLASSES:
        includes.add(schema_class.parent)

    for f in schema_class.fields:
        if f.type.category == SchemaTypeCategory.Bitfield:
            continue
        if _field_has_ignored_wildcard(f.type):
            continue
        if contains_ignored_type(f.type):
            continue
        collect_referenced_types(
            f.type,
            includes,
            forwards,
            f.type.category == SchemaTypeCategory.Ptr,
        )

    if class_name in MANUAL_METHODS:
        collect_types_from_methods(
            MANUAL_METHODS[class_name], all_enums, all_classes, includes, forwards
        )

    includes.discard(class_name)
    forwards.discard(class_name)
    forwards -= includes

    inherits = class_name == "CBaseEntity" or inherits_from_base_entity(class_name, all_classes)

    guard = make_header_guard(class_name)
    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#pragma once",
        "",
    ]

    if inherits and class_name != "CBaseEntity":
        lines.append('#include "CBaseEntity.h"')

    lines += [
        '#include "igameevents.h"',
        '#include "ehandle.h"',
        '#include "entityhandle.h"',
        '#include "vector.h"',
        '#include "utlsymbol.h"',
        '#include "utlsymbollarge.h"',
        '#include "utlstring.h"',
        '#include "utlstringtoken.h"',
        '#include "source2toolkit/IToolkitTypes.h"',
        '#include "source2toolkit/schema/entityio.h"',
        '#include "source2toolkit/schema/schema.h"',
        "#include <cstdint>",
        "",
    ]

    for inc in sorted(includes):
        if inc in all_enums and inc not in HARD_SKIP_ENUMS:
            lines.append(f'#include "../enums/{sanitise_type_name(inc)}.h"')
        elif inc in all_classes:
            lines.append(f'#include "{sanitise_type_name(inc)}.h"')

    if includes:
        lines.append("")

    for fwd in sorted(forwards):
        lines.append(f"class {fwd};")

    if forwards:
        lines.append("")

    # Class declaration line
    if class_name == "CBaseEntity":
        parent_part = f" : public {schema_class.parent}" if schema_class.parent else ""
        lines.append(f"class {class_name}{parent_part}")
    elif schema_class.parent:
        lines.append(f"class {class_name} : public {schema_class.parent}")
    else:
        if inherits:
            lines.append(f"class {class_name} : public CBaseEntity::Factory<{class_name}>")
        else:
            lines.append(f"class {class_name}")

    lines += ["{", "public:", f"    DECLARE_SCHEMA_CLASS({class_name});", ""]

    for f in schema_class.fields:
        if f.type.category == SchemaTypeCategory.Bitfield:
            continue
        if _field_has_ignored_wildcard(f.type):
            continue
        if contains_ignored_type(f.type):
            continue

        if f.type.category == SchemaTypeCategory.FixedArray or f.type.name == "CUtlStringToken":
            lines.append(f"    SCHEMA_FIELD_POINTER({f.type.cpp_type_name}, {f.name});")
        else:
            lines.append(f"    SCHEMA_FIELD({f.type.cpp_type_name}, {f.name});")

    if class_name in MANUAL_METHODS:
        lines += ["", "public:"]
        for method in MANUAL_METHODS[class_name]:
            lines.append(f"    {method}")

    if inherits and class_name != "CBaseEntity":
        lines += [
            "",
            "public:",
            f"    static {class_name}* New(const char* className)",
            "    {",
            f"        return CBaseEntity::New<{class_name}>(className);",
            "    }",
            "",
            f"    static {class_name}* FromIndex(int iIndex)",
            "    {",
            f"        return CBaseEntity::FromIndex<{class_name}>(iIndex);",
            "    }",
            "",
            f"    static {class_name}* FromIndex(CEntityIndex index)",
            "    {",
            "        return FromIndex(index.Get());",
            "    }",
        ]

    lines.append("};")
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")
    return LICENSE_HEADER + "\r\n".join(lines)

# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main() -> None:
    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        script_dir, "../../public/source2toolkit/schema/entity"
    )

    schema_path = os.path.join(script_dir, "server.json")
    with open(schema_path, encoding="utf-8") as fh:
        raw = json.load(fh)

    defs = _parse_schema_defs(raw["defs"])
    enums, classes = convert_new_schema_to_old(defs)

    all_enums: dict[str, SchemaEnum] = {
        k: v for k, v in sorted(enums.items()) if k not in IGNORE_CLASSES
    }
    all_classes: dict[str, SchemaClass] = {
        k: v for k, v in sorted(classes.items()) if k not in IGNORE_CLASSES
    }

    visited = build_graph_and_bfs(all_classes)
    visited |= EXTRA_WHITELIST

    # Clear existing .h files
    if os.path.isdir(output_path):
        for root, _, files in os.walk(output_path):
            for fname in files:
                if fname.endswith(".h"):
                    os.remove(os.path.join(root, fname))

    enums_dir = os.path.join(output_path, "enums")
    classes_dir = os.path.join(output_path, "classes")
    os.makedirs(enums_dir, exist_ok=True)
    os.makedirs(classes_dir, exist_ok=True)

    for enum_name, schema_enum in all_enums.items():
        if enum_name in HARD_SKIP_ENUMS:
            continue
        content = write_enum(enum_name, schema_enum)
        out_file = os.path.join(enums_dir, f"{sanitise_type_name(enum_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)

    for class_name, schema_class in all_classes.items():
        if class_name in HARD_SKIP_CLASSES:
            continue
        if class_name not in visited and "VData" not in class_name:
            continue
        content = write_class(class_name, schema_class, all_enums, all_classes)
        out_file = os.path.join(classes_dir, f"{sanitise_type_name(class_name)}.h")
        with open(out_file, "w", encoding="utf-8", newline="") as fh:
            fh.write(content)

    print(f"Done. Classes: {len(all_classes)}, Enums: {len(all_enums)}, Classes written to {output_path}")

if __name__ == "__main__":
    main()
