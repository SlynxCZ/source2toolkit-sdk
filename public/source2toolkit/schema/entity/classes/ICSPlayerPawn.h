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

#ifndef _INCLUDE_ICSPLAYERPAWN_H
#define _INCLUDE_ICSPLAYERPAWN_H

#pragma once

#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitTypes.h"
#include "source2toolkit/schema/entityio.h"
#include <cstdint>

#include "ICSPlayerPawnBase.h"

#include "../enums/CSPlayerBlockingUseAction_t.h"
#include "../enums/loadout_slot_t.h"

class CBaseEntity;
class CCSBot;
class CCSPlayer_ActionTrackingServices;
class CCSPlayer_AimPunchServices;
class CCSPlayer_BulletServices;
class CCSPlayer_BuyServices;
class CCSPlayer_DamageReactServices;
class CCSPlayer_HostageServices;
class CCSPlayer_RadioServices;
class CEconItemView;
class EntitySpottedState_t;

class ICSPlayerPawn : public virtual ICSPlayerPawnBase
{
public:
    virtual ~ICSPlayerPawn() = default;

    virtual CCSPlayer_BulletServices*& BulletServices() = 0;
    virtual void BulletServicesUpdated() = 0;
    virtual CCSPlayer_HostageServices*& HostageServices() = 0;
    virtual void HostageServicesUpdated() = 0;
    virtual CCSPlayer_BuyServices*& BuyServices() = 0;
    virtual void BuyServicesUpdated() = 0;
    virtual CCSPlayer_ActionTrackingServices*& ActionTrackingServices() = 0;
    virtual void ActionTrackingServicesUpdated() = 0;
    virtual CCSPlayer_AimPunchServices*& AimPunchServices() = 0;
    virtual void AimPunchServicesUpdated() = 0;
    virtual CCSPlayer_RadioServices*& RadioServices() = 0;
    virtual void RadioServicesUpdated() = 0;
    virtual CCSPlayer_DamageReactServices*& DamageReactServices() = 0;
    virtual void DamageReactServicesUpdated() = 0;
    virtual uint16_t& CharacterDefIndex() = 0;
    virtual void CharacterDefIndexUpdated() = 0;
    virtual bool& HasFemaleVoice() = 0;
    virtual void HasFemaleVoiceUpdated() = 0;
    virtual CUtlString& StrVOPrefix() = 0;
    virtual void StrVOPrefixUpdated() = 0;
    virtual char* LastPlaceName() = 0;
    virtual bool& InHostageResetZone() = 0;
    virtual void InHostageResetZoneUpdated() = 0;
    virtual bool& InBuyZone() = 0;
    virtual void InBuyZoneUpdated() = 0;
    virtual CUtlVector<CHandle<CBaseEntity>>& TouchingBuyZones() = 0;
    virtual void TouchingBuyZonesUpdated() = 0;
    virtual bool& WasInBuyZone() = 0;
    virtual void WasInBuyZoneUpdated() = 0;
    virtual bool& InHostageRescueZone() = 0;
    virtual void InHostageRescueZoneUpdated() = 0;
    virtual bool& InBombZone() = 0;
    virtual void InBombZoneUpdated() = 0;
    virtual bool& WasInHostageRescueZone() = 0;
    virtual void WasInHostageRescueZoneUpdated() = 0;
    virtual int32_t& RetakesOffering() = 0;
    virtual void RetakesOfferingUpdated() = 0;
    virtual int32_t& RetakesOfferingCard() = 0;
    virtual void RetakesOfferingCardUpdated() = 0;
    virtual bool& RetakesHasDefuseKit() = 0;
    virtual void RetakesHasDefuseKitUpdated() = 0;
    virtual bool& RetakesMVPLastRound() = 0;
    virtual void RetakesMVPLastRoundUpdated() = 0;
    virtual int32_t& RetakesMVPBoostItem() = 0;
    virtual void RetakesMVPBoostItemUpdated() = 0;
    virtual loadout_slot_t& RetakesMVPBoostExtraUtility() = 0;
    virtual void RetakesMVPBoostExtraUtilityUpdated() = 0;
    virtual float& HealthShotBoostExpirationTime() = 0;
    virtual void HealthShotBoostExpirationTimeUpdated() = 0;
    virtual float& LandingTimeSeconds() = 0;
    virtual void LandingTimeSecondsUpdated() = 0;
    virtual bool& IsBuyMenuOpen() = 0;
    virtual void IsBuyMenuOpenUpdated() = 0;
    virtual float& LastLandTime() = 0;
    virtual void LastLandTimeUpdated() = 0;
    virtual bool& OnGroundLastTick() = 0;
    virtual void OnGroundLastTickUpdated() = 0;
    virtual int32_t& PlayerLocked() = 0;
    virtual void PlayerLockedUpdated() = 0;
    virtual float& TimeOfLastInjury() = 0;
    virtual void TimeOfLastInjuryUpdated() = 0;
    virtual float& NextSprayDecalTime() = 0;
    virtual void NextSprayDecalTimeUpdated() = 0;
    virtual bool& NextSprayDecalTimeExpedited() = 0;
    virtual void NextSprayDecalTimeExpeditedUpdated() = 0;
    virtual int32_t& RagdollDamageBone() = 0;
    virtual void RagdollDamageBoneUpdated() = 0;
    virtual Vector& RagdollDamageForce() = 0;
    virtual void RagdollDamageForceUpdated() = 0;
    virtual Vector& RagdollDamagePosition() = 0;
    virtual void RagdollDamagePositionUpdated() = 0;
    virtual char* RagdollDamageWeaponName() = 0;
    virtual bool& RagdollDamageHeadshot() = 0;
    virtual void RagdollDamageHeadshotUpdated() = 0;
    virtual Vector& RagdollServerOrigin() = 0;
    virtual void RagdollServerOriginUpdated() = 0;
    virtual CEconItemView& EconGloves() = 0;
    virtual void EconGlovesUpdated() = 0;
    virtual uint8_t& EconGlovesChanged() = 0;
    virtual void EconGlovesChangedUpdated() = 0;
    virtual QAngle& DeathEyeAngles() = 0;
    virtual void DeathEyeAnglesUpdated() = 0;
    virtual bool& LeftHanded() = 0;
    virtual void LeftHandedUpdated() = 0;
    virtual float& SwitchedHandednessTime() = 0;
    virtual void SwitchedHandednessTimeUpdated() = 0;
    virtual float& ViewmodelOffsetX() = 0;
    virtual void ViewmodelOffsetXUpdated() = 0;
    virtual float& ViewmodelOffsetY() = 0;
    virtual void ViewmodelOffsetYUpdated() = 0;
    virtual float& ViewmodelOffsetZ() = 0;
    virtual void ViewmodelOffsetZUpdated() = 0;
    virtual float& ViewmodelFOV() = 0;
    virtual void ViewmodelFOVUpdated() = 0;
    virtual bool& IsWalking() = 0;
    virtual void IsWalkingUpdated() = 0;
    virtual float& LastGivenDefuserTime() = 0;
    virtual void LastGivenDefuserTimeUpdated() = 0;
    virtual float& LastGivenBombTime() = 0;
    virtual void LastGivenBombTimeUpdated() = 0;
    virtual float& DealtDamageToEnemyMostRecentTimestamp() = 0;
    virtual void DealtDamageToEnemyMostRecentTimestampUpdated() = 0;
    virtual uint32_t& DisplayHistoryBits() = 0;
    virtual void DisplayHistoryBitsUpdated() = 0;
    virtual float& LastAttackedTeammate() = 0;
    virtual void LastAttackedTeammateUpdated() = 0;
    virtual float& AllowAutoFollowTime() = 0;
    virtual void AllowAutoFollowTimeUpdated() = 0;
    virtual bool& ResetArmorNextSpawn() = 0;
    virtual void ResetArmorNextSpawnUpdated() = 0;
    virtual CEntityIndex& LastKillerIndex() = 0;
    virtual void LastKillerIndexUpdated() = 0;
    virtual EntitySpottedState_t& EntitySpottedState() = 0;
    virtual void EntitySpottedStateUpdated() = 0;
    virtual int32_t& SpotRules() = 0;
    virtual void SpotRulesUpdated() = 0;
    virtual bool& IsScoped() = 0;
    virtual void IsScopedUpdated() = 0;
    virtual bool& ResumeZoom() = 0;
    virtual void ResumeZoomUpdated() = 0;
    virtual bool& IsDefusing() = 0;
    virtual void IsDefusingUpdated() = 0;
    virtual bool& IsGrabbingHostage() = 0;
    virtual void IsGrabbingHostageUpdated() = 0;
    virtual CSPlayerBlockingUseAction_t& BlockingUseActionInProgress() = 0;
    virtual void BlockingUseActionInProgressUpdated() = 0;
    virtual float& EmitSoundTime() = 0;
    virtual void EmitSoundTimeUpdated() = 0;
    virtual bool& InNoDefuseArea() = 0;
    virtual void InNoDefuseAreaUpdated() = 0;
    virtual CEntityIndex& BombSiteIndex() = 0;
    virtual void BombSiteIndexUpdated() = 0;
    virtual int32_t& WhichBombZone() = 0;
    virtual void WhichBombZoneUpdated() = 0;
    virtual bool& InBombZoneTrigger() = 0;
    virtual void InBombZoneTriggerUpdated() = 0;
    virtual bool& WasInBombZoneTrigger() = 0;
    virtual void WasInBombZoneTriggerUpdated() = 0;
    virtual int32_t& ShotsFired() = 0;
    virtual void ShotsFiredUpdated() = 0;
    virtual float& FlinchStack() = 0;
    virtual void FlinchStackUpdated() = 0;
    virtual float& VelocityModifier() = 0;
    virtual void VelocityModifierUpdated() = 0;
    virtual Vector& TotalBulletForce() = 0;
    virtual void TotalBulletForceUpdated() = 0;
    virtual bool& WaitForNoAttack() = 0;
    virtual void WaitForNoAttackUpdated() = 0;
    virtual float& IgnoreLadderJumpTime() = 0;
    virtual void IgnoreLadderJumpTimeUpdated() = 0;
    virtual bool& KilledByHeadshot() = 0;
    virtual void KilledByHeadshotUpdated() = 0;
    virtual int32_t& LastHitBox() = 0;
    virtual void LastHitBoxUpdated() = 0;
    virtual CCSBot*& Bot() = 0;
    virtual void BotUpdated() = 0;
    virtual bool& BotAllowActive() = 0;
    virtual void BotAllowActiveUpdated() = 0;
    virtual int32_t& LastPickupPriority() = 0;
    virtual void LastPickupPriorityUpdated() = 0;
    virtual float& LastPickupPriorityTime() = 0;
    virtual void LastPickupPriorityTimeUpdated() = 0;
    virtual int32_t& ArmorValue() = 0;
    virtual void ArmorValueUpdated() = 0;
    virtual uint16_t& CurrentEquipmentValue() = 0;
    virtual void CurrentEquipmentValueUpdated() = 0;
    virtual uint16_t& RoundStartEquipmentValue() = 0;
    virtual void RoundStartEquipmentValueUpdated() = 0;
    virtual uint16_t& FreezetimeEndEquipmentValue() = 0;
    virtual void FreezetimeEndEquipmentValueUpdated() = 0;
    virtual int32_t& LastWeaponFireUsercmd() = 0;
    virtual void LastWeaponFireUsercmdUpdated() = 0;
    virtual bool& IsSpawning() = 0;
    virtual void IsSpawningUpdated() = 0;
    virtual int32_t& DeathFlags() = 0;
    virtual void DeathFlagsUpdated() = 0;
    virtual bool& HasDeathInfo() = 0;
    virtual void HasDeathInfoUpdated() = 0;
    virtual float& DeathInfoTime() = 0;
    virtual void DeathInfoTimeUpdated() = 0;
    virtual Vector& DeathInfoOrigin() = 0;
    virtual void DeathInfoOriginUpdated() = 0;
    virtual uint32_t* PlayerPatchEconIndices() = 0;
    virtual Color& GunGameImmunityColor() = 0;
    virtual void GunGameImmunityColorUpdated() = 0;
    virtual float& GrenadeParameterStashTime() = 0;
    virtual void GrenadeParameterStashTimeUpdated() = 0;
    virtual bool& GrenadeParametersStashed() = 0;
    virtual void GrenadeParametersStashedUpdated() = 0;
    virtual QAngle& StashedShootAngles() = 0;
    virtual void StashedShootAnglesUpdated() = 0;
    virtual Vector& StashedGrenadeThrowPosition() = 0;
    virtual void StashedGrenadeThrowPositionUpdated() = 0;
    virtual Vector& StashedVelocity() = 0;
    virtual void StashedVelocityUpdated() = 0;
    virtual QAngle* ShootAngleHistory() = 0;
    virtual Vector* ThrowPositionHistory() = 0;
    virtual Vector* VelocityHistory() = 0;
    virtual bool& CommittingSuicideOnTeamChange() = 0;
    virtual void CommittingSuicideOnTeamChangeUpdated() = 0;
    virtual bool& WasNotKilledNaturally() = 0;
    virtual void WasNotKilledNaturallyUpdated() = 0;
    virtual float& ImmuneToGunGameDamageTime() = 0;
    virtual void ImmuneToGunGameDamageTimeUpdated() = 0;
    virtual bool& GunGameImmunity() = 0;
    virtual void GunGameImmunityUpdated() = 0;
    virtual float& MolotovDamageTime() = 0;
    virtual void MolotovDamageTimeUpdated() = 0;
    virtual QAngle& EyeAngles() = 0;
    virtual void EyeAnglesUpdated() = 0;
};

#endif // _INCLUDE_ICSPLAYERPAWN_H
