/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

/**

* @file IToolkitAddresses.h
* @brief Resolved engine-function accessors for Source2Toolkit.
*
* Exposes pre-resolved function pointers for common engine operations.
* Module inspection, pattern scanning, symbol lookup, and pointer
* arithmetic are available via IToolkitModule and IToolkitMemory.
  */

#ifndef _INCLUDE_ITOOLKIT_ADDRESSES_H
#define _INCLUDE_ITOOLKIT_ADDRESSES_H

#pragma once
#include "IToolkitPlugin.h"

#include "igameevents.h"
#include "eiface.h"
#include "utils/plat.h"

/* =========================
Forward declarations
========================= */

class CBaseEntity;
class CBasePlayerWeapon;
class CBaseModelEntity;
class CBasePlayerPawn;
class CBasePlayerController;
class CCSPlayer_WeaponServices;
class CCSPlayerController;
class CEntityInstance;
class CEntityIOOutput;
class CEntitySystem;
class CEntityKeyValues;
class CGameRules;
class CTakeDamageInfo;
class CTakeDamageResult;
class IEntityFindFilter;
class IGameEventListener2;
class CAttributeList;
class CCSPlayerPawn;
class CDecoyProjectile;
class CFlashbangProjectile;
class CHEGrenadeProjectile;
class CMolotovProjectile;
class CSmokeGrenadeProjectile;
class CCSPlayer_ItemServices;
class CCSPlayer_MovementServices;
class CCSPlayerLegacyJump;
class CCSPlayerModernJump;
class CEconItemView;
class CEntityIdentity;
class CGameTrace;
class CMoveData;
class CUserCmd;
class IGameEventManager2;

/* =========================
Function typedefs
========================= */

/**

* @brief Creates an entity by classname.
  */
using CBaseEntity_CreateEntityByName_t = CBaseEntity* (FASTCALL*)(const char*, int);

/**

* @brief Dispatches spawn on an entity.
  */
using CBaseEntity_DispatchSpawn_t = void (FASTCALL*)(CBaseEntity*, CEntityKeyValues*);

/**

* @brief Takes damage from entity..
  */
using CBaseEntity_TakeDamageOld_t = int64_t (FASTCALL*)(CBaseEntity* pThis, CTakeDamageInfo* pInfo,
                                                        CTakeDamageResult* pResult);

/**

* @brief Sets model on entity.
  */
using CBaseModelEntity_SetModel_t = void (FASTCALL*)(CBaseModelEntity*, const char*);

/**

* @brief Assigns pawn to player controller.
  */
using CBasePlayerController_SetPawn_t = void (FASTCALL*)(CBasePlayerController*, CBasePlayerPawn*, bool, bool, bool,
                                                         bool);

/**

* @brief Snaps a pawn's view angles, as the engine does on teleport.
*
* Unresolved on Windows -- no published signature -- so the getter can
* return null and callers must check.
  */
using CBasePlayerPawn_SnapViewAngles_t = void (FASTCALL*)(CBasePlayerPawn*, QAngle*);

/**

* @brief Terminates current round.
  */
/**
 * @brief CGameRules::TerminateRound
 *
 * The delay and the reason swap places between platforms, and the winning team
 * goes in as a pointer -- null when there is none, which is the ordinary case.
 * SwiftlyS2 splits it the same way; getting this wrong on Linux means the game
 * reads the reason as the delay.
 */
#ifdef _WIN32
using CGameRules_TerminateRound_t = void (FASTCALL*)(CGameRules* pThis, float flDelay,
                                                     uint32 nReason, uint32* pnTeamId);
#else
using CGameRules_TerminateRound_t = void (FASTCALL*)(CGameRules* pThis, uint32 nReason,
                                                     uint32* pnTeamId, float flDelay);
#endif

/**

* @brief Destroys weapon from player pawn.
  */
using CCSPlayer_WeaponServices_Destroy_t = void (FASTCALL*)(CCSPlayer_WeaponServices*, CBasePlayerWeapon*);

/**

* @brief Retrieves legacy game event listener.
  */
using LegacyGameEventListener_t = IGameEventListener2* (FASTCALL*)(CPlayerSlot);

/**

* @brief Switches player team.
  */
using CCSPlayerController_SwitchTeam_t = void (FASTCALL*)(CCSPlayerController*, unsigned char);

/**

* @brief Accepts entity input.
  */
using CEntityInstance_AcceptInput_t = void (FASTCALL*)(CEntityInstance*, const char*, CEntityInstance*,
                                                       CEntityInstance*, const variant_t&);

/**

* @brief Fires entity output internally.
  */
using CEntityIOOutput_FireOutputInternal_t = void (FASTCALL*)(CEntityIOOutput*, CEntityInstance*, CEntityInstance*,
                                                              void*, float, void*, void*);

/**

* @brief Adds entity IO event.
  */
using CEntitySystem_AddEntityIOEvent_t = void (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*,
                                                          CEntityInstance*, CEntityInstance*, const variant_t&, float,
                                                          void*, void*);

/**

* @brief Finds entity by classname.
  */
using CGameEntitySystem_FindEntityByClassName_t = CBaseEntity* (FASTCALL*)(
    CEntitySystem*, CEntityInstance*, const char*);

/**

* @brief Finds entity by name.
  */
using CGameEntitySystem_FindEntityByName_t = CBaseEntity* (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*,
                                                                      CEntityInstance*, CEntityInstance*,
                                                                      CEntityInstance*, IEntityFindFilter*);

/**

* @brief Constructs CTakeDamageInfo with valid members.
  */
using CTakeDamageInfo_CTakeDamageInfo_t = void (FASTCALL*)(CTakeDamageInfo* pThis, CBaseEntity* pInflictor,
                                                           CBaseEntity* pAttacker, CBaseEntity* pAbility,
                                                           const Vector* vecDamageForce,
                                                           const Vector* vecDamagePosition, float flDamage,
                                                           int bitsDamageType, int iCustomDamage, void* a10);

using INetworkMessageProcessingPreFilter_FilterMessage_t = bool (THISCALL*)(INetworkMessageProcessingPreFilter* pThis,
                                                                            const CNetMessage* pData,
                                                                            INetChannel* pChannel);


/* =========================
SwiftlyS2-derived typedefs

The prototypes below are ported from swiftly-solution/swiftlys2
(managed/src/SwiftlyS2.Core/Modules/GameHooks/Hooks), which is also where the
matching signatures come from. Their gamedata name is given with each one so a
prototype can be traced back to the pattern it belongs to.
========================= */

/** @brief CEntityIdentity::AcceptInput -- the identity-side entry point. */
using CEntityIdentity_AcceptInput_t = void (FASTCALL*)(CEntityIdentity* pThis, const char* pszInputName,
                                                       CEntityInstance* pActivator, CEntityInstance* pCaller,
                                                       variant_t* pValue, void* a6, void* a7);

/** @brief CCSPlayer_ItemServices::CanAcquire -- returns an AcquireResult. */
using CCSPlayer_ItemServices_CanAcquire_t = int64_t (FASTCALL*)(CCSPlayer_ItemServices* pThis, CEconItemView* pItem,
                                                                int nAcquireMethod, void* a4);

/** @brief CCSPlayerPawn::CanMove -- false while frozen, defusing, etc. */
using CCSPlayerPawn_CanMove_t = bool (FASTCALL*)(CCSPlayerPawn* pThis);

/** @brief CCSPlayerController::ProcessUserCmd */
using CCSPlayerController_ProcessUserCmd_t = void* (FASTCALL*)(CCSPlayerController* pThis, void* pUserCmds,
                                                               int nNumCmds, bool bPaused, float flMargin);

/** @brief CBasePlayerController::OnSimulateUserCommands */
using CBasePlayerController_OnSimulateUserCommands_t = void (FASTCALL*)(CBasePlayerController* pThis);

/* --- CCSPlayer_MovementServices --- */

using CCSPlayer_MovementServices_AirAccelerate_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                    CMoveData* pMove, Vector* pWishDirection,
                                                                    float flWishSpeed, float flAcceleration);
using CCSPlayer_MovementServices_AirMove_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_CanUnduck_t = bool (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_CategorizePosition_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                         CMoveData* pMove, bool bStayOnGround);
using CCSPlayer_MovementServices_CheckFalling_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_CheckParameters_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                      CMoveData* pMove);
using CCSPlayer_MovementServices_CheckVelocity_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                    CMoveData* pMove, void* a3);
using CCSPlayer_MovementServices_CheckWater_t = bool (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_Duck_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_Friction_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_FullWalkMove_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove,
                                                                   bool bGround);
using CCSPlayer_MovementServices_LadderMove_t = bool (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_MoveInit_t = bool (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_PlayerMove_t = bool (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_ProcessMovement_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                      CMoveData* pMove);
using CCSPlayer_MovementServices_SetupMove_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CUserCmd* pCmd,
                                                                CMoveData* pMove);
using CCSPlayer_MovementServices_TryPlayerMove_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                    CMoveData* pMove, Vector* pFirstDest,
                                                                    CGameTrace* pFirstTrace, bool* pbIsSurfing);
using CCSPlayer_MovementServices_WalkMove_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_WaterMove_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis, CMoveData* pMove);

/**
 * @brief CCSPlayer_MovementServices::GroundAccelerate
 *
 * The wish direction and the frame time swap places between platforms.
 */
#ifdef _WIN32
using CCSPlayer_MovementServices_GroundAccelerate_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                       CMoveData* pMove, float flFrameTime,
                                                                       Vector* pWishDirection, float flWishSpeed,
                                                                       float flAcceleration);
#else
using CCSPlayer_MovementServices_GroundAccelerate_t = void (FASTCALL*)(CCSPlayer_MovementServices* pThis,
                                                                       CMoveData* pMove, Vector* pWishDirection,
                                                                       float flFrameTime, float flWishSpeed,
                                                                       float flAcceleration);
#endif

/**
 * @brief The jump handlers take the jump object, not the movement services.
 *
 * Which pair is live depends on the sv_jump_impulse-era cvars; the modern and
 * legacy paths are separate functions in the binary.
 */
using CCSPlayer_MovementServices_OnJumpLegacy_t = void (FASTCALL*)(CCSPlayerLegacyJump* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_OnJumpModern_t = void (FASTCALL*)(CCSPlayerModernJump* pThis, CMoveData* pMove);
using CCSPlayer_MovementServices_CheckJumpButtonLegacy_t = void (FASTCALL*)(CCSPlayerLegacyJump* pThis,
                                                                            CMoveData* pMove);
using CCSPlayer_MovementServices_CheckJumpButtonModern_t = void (FASTCALL*)(CCSPlayerModernJump* pThis,
                                                                            CMoveData* pMove);


/** @brief CAttributeList::SetOrAddAttributeValueByName */
using CAttributeList_SetOrAddAttributeValueByName_t = void (FASTCALL*)(CAttributeList* pThis,
                                                                      const char* pszAttributeName, float flValue);

/**
 * @brief C<Type>Projectile::EmitGrenade -- spawns a live grenade.
 *
 * The fourth argument is a second velocity the game reads as the angular one;
 * swiftly passes the same vector twice. Smoke takes one extra int the others
 * do not have.
 */
using CDecoyProjectile_EmitGrenade_t = CDecoyProjectile* (FASTCALL*)(Vector* pPosition, QAngle* pAngle,
                                                                     Vector* pVelocity, Vector* pAngVelocity,
                                                                     CBaseEntity* pOwner, uint32_t nItemDefIndex);
using CFlashbangProjectile_EmitGrenade_t = CFlashbangProjectile* (FASTCALL*)(Vector* pPosition, QAngle* pAngle,
                                                                             Vector* pVelocity, Vector* pAngVelocity,
                                                                             CBaseEntity* pOwner,
                                                                             uint32_t nItemDefIndex);
using CHEGrenadeProjectile_EmitGrenade_t = CHEGrenadeProjectile* (FASTCALL*)(Vector* pPosition, QAngle* pAngle,
                                                                             Vector* pVelocity, Vector* pAngVelocity,
                                                                             CBaseEntity* pOwner,
                                                                             uint32_t nItemDefIndex);
using CMolotovProjectile_EmitGrenade_t = CMolotovProjectile* (FASTCALL*)(Vector* pPosition, QAngle* pAngle,
                                                                         Vector* pVelocity, Vector* pAngVelocity,
                                                                         CBaseEntity* pOwner, uint32_t nItemDefIndex);
using CSmokeGrenadeProjectile_EmitGrenade_t = CSmokeGrenadeProjectile* (FASTCALL*)(Vector* pPosition, QAngle* pAngle,
                                                                                   Vector* pVelocity,
                                                                                   Vector* pAngVelocity,
                                                                                   CBaseEntity* pOwner,
                                                                                   uint32_t nItemDefIndex, int a7);

/* =========================
Core Toolkit Addresses
========================= */

/**

* @brief Provides access to pre-resolved engine function pointers.
*
* For module inspection, pattern scanning, and pointer arithmetic use
* IToolkitModule and IToolkitMemory instead.
  */
#define TOOLKIT_ADDRESSES_INTERFACE "IToolkitAddresses001"

class IToolkitAddresses
{
public:
    virtual ~IToolkitAddresses() = default;

    /* =========================
    Resolved engine functions
    ========================= */

    virtual CBaseEntity_CreateEntityByName_t CBaseEntity_CreateEntityByName() = 0;
    virtual CBaseEntity_DispatchSpawn_t CBaseEntity_DispatchSpawn() = 0;
    virtual CBaseEntity_TakeDamageOld_t CBaseEntity_TakeDamageOld() = 0;
    virtual CBaseModelEntity_SetModel_t CBaseModelEntity_SetModel() = 0;
    virtual CBasePlayerController_SetPawn_t CBasePlayerController_SetPawn() = 0;
    virtual CBasePlayerPawn_SnapViewAngles_t CBasePlayerPawn_SnapViewAngles() = 0;
    virtual CGameRules_TerminateRound_t CGameRules_TerminateRound() = 0;
    virtual CCSPlayer_WeaponServices_Destroy_t CCSPlayer_WeaponServices_Destroy() = 0;
    virtual LegacyGameEventListener_t LegacyGameEventListener() = 0;
    virtual CCSPlayerController_SwitchTeam_t CCSPlayerController_SwitchTeam() = 0;
    virtual CEntityInstance_AcceptInput_t CEntityInstance_AcceptInput() = 0;
    virtual CEntityIOOutput_FireOutputInternal_t CEntityIOOutput_FireOutputInternal() = 0;
    virtual CEntitySystem_AddEntityIOEvent_t CEntitySystem_AddEntityIOEvent() = 0;
    virtual CGameEntitySystem_FindEntityByClassName_t CGameEntitySystem_FindEntityByClassName() = 0;
    virtual CGameEntitySystem_FindEntityByName_t CGameEntitySystem_FindEntityByName() = 0;
    virtual CTakeDamageInfo_CTakeDamageInfo_t CTakeDamageInfo_CTakeDamageInfo() = 0;
    virtual INetworkMessageProcessingPreFilter_FilterMessage_t INetworkMessageProcessingPreFilter_FilterMessage() = 0;

    // Ported from SwiftlyS2; appended so the indices above stay put.
    virtual CEntityIdentity_AcceptInput_t CEntityIdentity_AcceptInput() = 0;
    virtual CCSPlayer_ItemServices_CanAcquire_t CCSPlayer_ItemServices_CanAcquire() = 0;
    virtual CCSPlayerPawn_CanMove_t CCSPlayerPawn_CanMove() = 0;
    virtual CCSPlayerController_ProcessUserCmd_t CCSPlayerController_ProcessUserCmd() = 0;
    virtual CBasePlayerController_OnSimulateUserCommands_t CBasePlayerController_OnSimulateUserCommands() = 0;
    virtual CCSPlayer_MovementServices_AirAccelerate_t CCSPlayer_MovementServices_AirAccelerate() = 0;
    virtual CCSPlayer_MovementServices_AirMove_t CCSPlayer_MovementServices_AirMove() = 0;
    virtual CCSPlayer_MovementServices_CanUnduck_t CCSPlayer_MovementServices_CanUnduck() = 0;
    virtual CCSPlayer_MovementServices_CategorizePosition_t CCSPlayer_MovementServices_CategorizePosition() = 0;
    virtual CCSPlayer_MovementServices_CheckFalling_t CCSPlayer_MovementServices_CheckFalling() = 0;
    virtual CCSPlayer_MovementServices_CheckParameters_t CCSPlayer_MovementServices_CheckParameters() = 0;
    virtual CCSPlayer_MovementServices_CheckVelocity_t CCSPlayer_MovementServices_CheckVelocity() = 0;
    virtual CCSPlayer_MovementServices_CheckWater_t CCSPlayer_MovementServices_CheckWater() = 0;
    virtual CCSPlayer_MovementServices_Duck_t CCSPlayer_MovementServices_Duck() = 0;
    virtual CCSPlayer_MovementServices_Friction_t CCSPlayer_MovementServices_Friction() = 0;
    virtual CCSPlayer_MovementServices_FullWalkMove_t CCSPlayer_MovementServices_FullWalkMove() = 0;
    virtual CCSPlayer_MovementServices_GroundAccelerate_t CCSPlayer_MovementServices_GroundAccelerate() = 0;
    virtual CCSPlayer_MovementServices_LadderMove_t CCSPlayer_MovementServices_LadderMove() = 0;
    virtual CCSPlayer_MovementServices_MoveInit_t CCSPlayer_MovementServices_MoveInit() = 0;
    virtual CCSPlayer_MovementServices_PlayerMove_t CCSPlayer_MovementServices_PlayerMove() = 0;
    virtual CCSPlayer_MovementServices_ProcessMovement_t CCSPlayer_MovementServices_ProcessMovement() = 0;
    virtual CCSPlayer_MovementServices_SetupMove_t CCSPlayer_MovementServices_SetupMove() = 0;
    virtual CCSPlayer_MovementServices_TryPlayerMove_t CCSPlayer_MovementServices_TryPlayerMove() = 0;
    virtual CCSPlayer_MovementServices_WalkMove_t CCSPlayer_MovementServices_WalkMove() = 0;
    virtual CCSPlayer_MovementServices_WaterMove_t CCSPlayer_MovementServices_WaterMove() = 0;
    virtual CCSPlayer_MovementServices_OnJumpLegacy_t CCSPlayer_MovementServices_OnJumpLegacy() = 0;
    virtual CCSPlayer_MovementServices_OnJumpModern_t CCSPlayer_MovementServices_OnJumpModern() = 0;
    virtual CCSPlayer_MovementServices_CheckJumpButtonLegacy_t CCSPlayer_MovementServices_CheckJumpButtonLegacy() = 0;
    virtual CCSPlayer_MovementServices_CheckJumpButtonModern_t CCSPlayer_MovementServices_CheckJumpButtonModern() = 0;
    virtual CAttributeList_SetOrAddAttributeValueByName_t CAttributeList_SetOrAddAttributeValueByName() = 0;
    virtual CDecoyProjectile_EmitGrenade_t CDecoyProjectile_EmitGrenade() = 0;
    virtual CFlashbangProjectile_EmitGrenade_t CFlashbangProjectile_EmitGrenade() = 0;
    virtual CHEGrenadeProjectile_EmitGrenade_t CHEGrenadeProjectile_EmitGrenade() = 0;
    virtual CMolotovProjectile_EmitGrenade_t CMolotovProjectile_EmitGrenade() = 0;
    virtual CSmokeGrenadeProjectile_EmitGrenade_t CSmokeGrenadeProjectile_EmitGrenade() = 0;
};

#define ADDR_CREATE_ENTITY_BY_NAME()                g_pToolkitAddresses->CBaseEntity_CreateEntityByName()
#define ADDR_DISPATCH_SPAWN()                       g_pToolkitAddresses->CBaseEntity_DispatchSpawn()
#define ADDR_TAKE_DAMAGE_OLD()                      g_pToolkitAddresses->CBaseEntity_TakeDamageOld()
#define ADDR_SET_MODEL()                            g_pToolkitAddresses->CBaseModelEntity_SetModel()
#define ADDR_SET_PAWN()                             g_pToolkitAddresses->CBasePlayerController_SetPawn()
#define ADDR_SNAP_VIEW_ANGLES()                     g_pToolkitAddresses->CBasePlayerPawn_SnapViewAngles()
#define ADDR_TERMINATE_ROUND()                      g_pToolkitAddresses->CGameRules_TerminateRound()
#define ADDR_WEAPON_SERVICES_DESTROY()              g_pToolkitAddresses->CCSPlayer_WeaponServices_Destroy()
#define ADDR_LEGACY_GAME_EVENT_LISTENER()           g_pToolkitAddresses->LegacyGameEventListener()
#define ADDR_SWITCH_TEAM()                          g_pToolkitAddresses->CCSPlayerController_SwitchTeam()
#define ADDR_ACCEPT_INPUT()                         g_pToolkitAddresses->CEntityInstance_AcceptInput()
#define ADDR_FIRE_OUTPUT_INTERNAL()                 g_pToolkitAddresses->CEntityIOOutput_FireOutputInternal()
#define ADDR_ADD_ENTITY_IO_EVENT()                  g_pToolkitAddresses->CEntitySystem_AddEntityIOEvent()
#define ADDR_FIND_ENTITY_BY_CLASSNAME()             g_pToolkitAddresses->CGameEntitySystem_FindEntityByClassName()
#define ADDR_FIND_ENTITY_BY_NAME()                  g_pToolkitAddresses->CGameEntitySystem_FindEntityByName()
#define ADDR_TAKE_DAMAGE_INFO()                     g_pToolkitAddresses->CTakeDamageInfo_CTakeDamageInfo()
#define ADDR_FILTER_MESSAGE()                       g_pToolkitAddresses->INetworkMessageProcessingPreFilter_FilterMessage()

#define ADDR_IDENTITY_ACCEPT_INPUT()                g_pToolkitAddresses->CEntityIdentity_AcceptInput()
#define ADDR_CAN_ACQUIRE()                          g_pToolkitAddresses->CCSPlayer_ItemServices_CanAcquire()
#define ADDR_CAN_MOVE()                             g_pToolkitAddresses->CCSPlayerPawn_CanMove()
#define ADDR_PROCESS_USER_CMD()                     g_pToolkitAddresses->CCSPlayerController_ProcessUserCmd()
#define ADDR_ON_SIMULATE_USER_COMMANDS()            g_pToolkitAddresses->CBasePlayerController_OnSimulateUserCommands()
#define ADDR_AIR_ACCELERATE()                       g_pToolkitAddresses->CCSPlayer_MovementServices_AirAccelerate()
#define ADDR_AIR_MOVE()                             g_pToolkitAddresses->CCSPlayer_MovementServices_AirMove()
#define ADDR_CAN_UNDUCK()                           g_pToolkitAddresses->CCSPlayer_MovementServices_CanUnduck()
#define ADDR_CATEGORIZE_POSITION()                  g_pToolkitAddresses->CCSPlayer_MovementServices_CategorizePosition()
#define ADDR_CHECK_FALLING()                        g_pToolkitAddresses->CCSPlayer_MovementServices_CheckFalling()
#define ADDR_CHECK_PARAMETERS()                     g_pToolkitAddresses->CCSPlayer_MovementServices_CheckParameters()
#define ADDR_CHECK_VELOCITY()                       g_pToolkitAddresses->CCSPlayer_MovementServices_CheckVelocity()
#define ADDR_CHECK_WATER()                          g_pToolkitAddresses->CCSPlayer_MovementServices_CheckWater()
#define ADDR_DUCK()                                 g_pToolkitAddresses->CCSPlayer_MovementServices_Duck()
#define ADDR_FRICTION()                             g_pToolkitAddresses->CCSPlayer_MovementServices_Friction()
#define ADDR_FULL_WALK_MOVE()                       g_pToolkitAddresses->CCSPlayer_MovementServices_FullWalkMove()
#define ADDR_GROUND_ACCELERATE()                    g_pToolkitAddresses->CCSPlayer_MovementServices_GroundAccelerate()
#define ADDR_LADDER_MOVE()                          g_pToolkitAddresses->CCSPlayer_MovementServices_LadderMove()
#define ADDR_MOVE_INIT()                            g_pToolkitAddresses->CCSPlayer_MovementServices_MoveInit()
#define ADDR_PLAYER_MOVE()                          g_pToolkitAddresses->CCSPlayer_MovementServices_PlayerMove()
#define ADDR_PROCESS_MOVEMENT()                     g_pToolkitAddresses->CCSPlayer_MovementServices_ProcessMovement()
#define ADDR_SETUP_MOVE()                           g_pToolkitAddresses->CCSPlayer_MovementServices_SetupMove()
#define ADDR_TRY_PLAYER_MOVE()                      g_pToolkitAddresses->CCSPlayer_MovementServices_TryPlayerMove()
#define ADDR_WALK_MOVE()                            g_pToolkitAddresses->CCSPlayer_MovementServices_WalkMove()
#define ADDR_WATER_MOVE()                           g_pToolkitAddresses->CCSPlayer_MovementServices_WaterMove()
#define ADDR_ON_JUMP_LEGACY()                       g_pToolkitAddresses->CCSPlayer_MovementServices_OnJumpLegacy()
#define ADDR_ON_JUMP_MODERN()                       g_pToolkitAddresses->CCSPlayer_MovementServices_OnJumpModern()
#define ADDR_CHECK_JUMP_BUTTON_LEGACY()             g_pToolkitAddresses->CCSPlayer_MovementServices_CheckJumpButtonLegacy()
#define ADDR_CHECK_JUMP_BUTTON_MODERN()             g_pToolkitAddresses->CCSPlayer_MovementServices_CheckJumpButtonModern()
#define ADDR_SET_OR_ADD_ATTRIBUTE()                 g_pToolkitAddresses->CAttributeList_SetOrAddAttributeValueByName()
#define ADDR_EMIT_DECOY()                           g_pToolkitAddresses->CDecoyProjectile_EmitGrenade()
#define ADDR_EMIT_FLASHBANG()                       g_pToolkitAddresses->CFlashbangProjectile_EmitGrenade()
#define ADDR_EMIT_HEGRENADE()                       g_pToolkitAddresses->CHEGrenadeProjectile_EmitGrenade()
#define ADDR_EMIT_MOLOTOV()                         g_pToolkitAddresses->CMolotovProjectile_EmitGrenade()
#define ADDR_EMIT_SMOKE()                           g_pToolkitAddresses->CSmokeGrenadeProjectile_EmitGrenade()

#endif //_INCLUDE_ITOOLKIT_ADDRESSES_H
