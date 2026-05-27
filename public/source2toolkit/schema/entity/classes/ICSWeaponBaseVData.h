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

#ifndef _INCLUDE_ICSWEAPONBASEVDATA_H
#define _INCLUDE_ICSWEAPONBASEVDATA_H

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

#include "IBasePlayerWeaponVData.h"

#include "../enums/CSWeaponCategory.h"
#include "../enums/CSWeaponSilencerType.h"
#include "../enums/CSWeaponType.h"
#include "../enums/gear_slot_t.h"
#include "../enums/loadout_slot_t.h"

class CFiringModeFloat;
class CFiringModeInt;

class ICSWeaponBaseVData : public virtual IBasePlayerWeaponVData
{
public:
    virtual ~ICSWeaponBaseVData() = default;

    virtual CSWeaponType& WeaponType() = 0;
    virtual void WeaponTypeUpdated() = 0;
    virtual CSWeaponCategory& WeaponCategory() = 0;
    virtual void WeaponCategoryUpdated() = 0;
    virtual Vector& MuzzlePos0() = 0;
    virtual void MuzzlePos0Updated() = 0;
    virtual Vector& MuzzlePos1() = 0;
    virtual void MuzzlePos1Updated() = 0;
    virtual gear_slot_t& GearSlot() = 0;
    virtual void GearSlotUpdated() = 0;
    virtual int32_t& GearSlotPosition() = 0;
    virtual void GearSlotPositionUpdated() = 0;
    virtual loadout_slot_t& DefaultLoadoutSlot() = 0;
    virtual void DefaultLoadoutSlotUpdated() = 0;
    virtual int32_t& Price() = 0;
    virtual void PriceUpdated() = 0;
    virtual int32_t& KillAward() = 0;
    virtual void KillAwardUpdated() = 0;
    virtual int32_t& PrimaryReserveAmmoMax() = 0;
    virtual void PrimaryReserveAmmoMaxUpdated() = 0;
    virtual int32_t& SecondaryReserveAmmoMax() = 0;
    virtual void SecondaryReserveAmmoMaxUpdated() = 0;
    virtual bool& MeleeWeapon() = 0;
    virtual void MeleeWeaponUpdated() = 0;
    virtual bool& HasBurstMode() = 0;
    virtual void HasBurstModeUpdated() = 0;
    virtual bool& IsRevolver() = 0;
    virtual void IsRevolverUpdated() = 0;
    virtual bool& CannotShootUnderwater() = 0;
    virtual void CannotShootUnderwaterUpdated() = 0;
    virtual CGlobalSymbol& Name() = 0;
    virtual void NameUpdated() = 0;
    virtual CSWeaponSilencerType& SilencerType() = 0;
    virtual void SilencerTypeUpdated() = 0;
    virtual int32_t& CrosshairMinDistance() = 0;
    virtual void CrosshairMinDistanceUpdated() = 0;
    virtual int32_t& CrosshairDeltaDistance() = 0;
    virtual void CrosshairDeltaDistanceUpdated() = 0;
    virtual bool& IsFullAuto() = 0;
    virtual void IsFullAutoUpdated() = 0;
    virtual int32_t& NumBullets() = 0;
    virtual void NumBulletsUpdated() = 0;
    virtual bool& ReloadsSingleShells() = 0;
    virtual void ReloadsSingleShellsUpdated() = 0;
    virtual CFiringModeFloat& CycleTime() = 0;
    virtual void CycleTimeUpdated() = 0;
    virtual float& CycleTimeWhenInBurstMode() = 0;
    virtual void CycleTimeWhenInBurstModeUpdated() = 0;
    virtual float& TimeBetweenBurstShots() = 0;
    virtual void TimeBetweenBurstShotsUpdated() = 0;
    virtual CFiringModeFloat& MaxSpeed() = 0;
    virtual void MaxSpeedUpdated() = 0;
    virtual CFiringModeFloat& Spread() = 0;
    virtual void SpreadUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyCrouch() = 0;
    virtual void InaccuracyCrouchUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyStand() = 0;
    virtual void InaccuracyStandUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyJump() = 0;
    virtual void InaccuracyJumpUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyLand() = 0;
    virtual void InaccuracyLandUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyLadder() = 0;
    virtual void InaccuracyLadderUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyFire() = 0;
    virtual void InaccuracyFireUpdated() = 0;
    virtual CFiringModeFloat& InaccuracyMove() = 0;
    virtual void InaccuracyMoveUpdated() = 0;
    virtual CFiringModeFloat& RecoilAngle() = 0;
    virtual void RecoilAngleUpdated() = 0;
    virtual CFiringModeFloat& RecoilAngleVariance() = 0;
    virtual void RecoilAngleVarianceUpdated() = 0;
    virtual CFiringModeFloat& RecoilMagnitude() = 0;
    virtual void RecoilMagnitudeUpdated() = 0;
    virtual CFiringModeFloat& RecoilMagnitudeVariance() = 0;
    virtual void RecoilMagnitudeVarianceUpdated() = 0;
    virtual CFiringModeInt& TracerFrequency() = 0;
    virtual void TracerFrequencyUpdated() = 0;
    virtual float& InaccuracyJumpInitial() = 0;
    virtual void InaccuracyJumpInitialUpdated() = 0;
    virtual float& InaccuracyJumpApex() = 0;
    virtual void InaccuracyJumpApexUpdated() = 0;
    virtual float& InaccuracyReload() = 0;
    virtual void InaccuracyReloadUpdated() = 0;
    virtual float& DeployDuration() = 0;
    virtual void DeployDurationUpdated() = 0;
    virtual float& DisallowAttackAfterReloadStartDuration() = 0;
    virtual void DisallowAttackAfterReloadStartDurationUpdated() = 0;
    virtual int32_t& BurstShotCount() = 0;
    virtual void BurstShotCountUpdated() = 0;
    virtual bool& AllowBurstHolster() = 0;
    virtual void AllowBurstHolsterUpdated() = 0;
    virtual int32_t& RecoilSeed() = 0;
    virtual void RecoilSeedUpdated() = 0;
    virtual int32_t& SpreadSeed() = 0;
    virtual void SpreadSeedUpdated() = 0;
    virtual float& AttackMovespeedFactor() = 0;
    virtual void AttackMovespeedFactorUpdated() = 0;
    virtual float& InaccuracyPitchShift() = 0;
    virtual void InaccuracyPitchShiftUpdated() = 0;
    virtual float& InaccuracyAltSoundThreshold() = 0;
    virtual void InaccuracyAltSoundThresholdUpdated() = 0;
    virtual CUtlString& UseRadioSubtitle() = 0;
    virtual void UseRadioSubtitleUpdated() = 0;
    virtual bool& UnzoomsAfterShot() = 0;
    virtual void UnzoomsAfterShotUpdated() = 0;
    virtual bool& HideViewModelWhenZoomed() = 0;
    virtual void HideViewModelWhenZoomedUpdated() = 0;
    virtual int32_t& ZoomLevels() = 0;
    virtual void ZoomLevelsUpdated() = 0;
    virtual int32_t& ZoomFOV1() = 0;
    virtual void ZoomFOV1Updated() = 0;
    virtual int32_t& ZoomFOV2() = 0;
    virtual void ZoomFOV2Updated() = 0;
    virtual float& ZoomTime0() = 0;
    virtual void ZoomTime0Updated() = 0;
    virtual float& ZoomTime1() = 0;
    virtual void ZoomTime1Updated() = 0;
    virtual float& ZoomTime2() = 0;
    virtual void ZoomTime2Updated() = 0;
    virtual float& IronSightPullUpSpeed() = 0;
    virtual void IronSightPullUpSpeedUpdated() = 0;
    virtual float& IronSightPutDownSpeed() = 0;
    virtual void IronSightPutDownSpeedUpdated() = 0;
    virtual float& IronSightFOV() = 0;
    virtual void IronSightFOVUpdated() = 0;
    virtual float& IronSightPivotForward() = 0;
    virtual void IronSightPivotForwardUpdated() = 0;
    virtual float& IronSightLooseness() = 0;
    virtual void IronSightLoosenessUpdated() = 0;
    virtual int32_t& Damage() = 0;
    virtual void DamageUpdated() = 0;
    virtual float& HeadshotMultiplier() = 0;
    virtual void HeadshotMultiplierUpdated() = 0;
    virtual float& ArmorRatio() = 0;
    virtual void ArmorRatioUpdated() = 0;
    virtual float& Penetration() = 0;
    virtual void PenetrationUpdated() = 0;
    virtual float& Range() = 0;
    virtual void RangeUpdated() = 0;
    virtual float& RangeModifier() = 0;
    virtual void RangeModifierUpdated() = 0;
    virtual float& FlinchVelocityModifierLarge() = 0;
    virtual void FlinchVelocityModifierLargeUpdated() = 0;
    virtual float& FlinchVelocityModifierSmall() = 0;
    virtual void FlinchVelocityModifierSmallUpdated() = 0;
    virtual float& RecoveryTimeCrouch() = 0;
    virtual void RecoveryTimeCrouchUpdated() = 0;
    virtual float& RecoveryTimeStand() = 0;
    virtual void RecoveryTimeStandUpdated() = 0;
    virtual float& RecoveryTimeCrouchFinal() = 0;
    virtual void RecoveryTimeCrouchFinalUpdated() = 0;
    virtual float& RecoveryTimeStandFinal() = 0;
    virtual void RecoveryTimeStandFinalUpdated() = 0;
    virtual int32_t& RecoveryTransitionStartBullet() = 0;
    virtual void RecoveryTransitionStartBulletUpdated() = 0;
    virtual int32_t& RecoveryTransitionEndBullet() = 0;
    virtual void RecoveryTransitionEndBulletUpdated() = 0;
    virtual float& ThrowVelocity() = 0;
    virtual void ThrowVelocityUpdated() = 0;
    virtual Vector& SmokeColor() = 0;
    virtual void SmokeColorUpdated() = 0;
    virtual CGlobalSymbol& AnimClass() = 0;
    virtual void AnimClassUpdated() = 0;
};

#endif // _INCLUDE_ICSWEAPONBASEVDATA_H
