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

#ifndef _INCLUDE_IPHYSICSPROP_H
#define _INCLUDE_IPHYSICSPROP_H

#pragma once

#include <cstdint>

#include "IBreakableProp.h"

#include "../enums/CPhysicsProp__CrateType_t.h"
#include "../enums/DynamicContinuousContactBehavior_t.h"
#include "../enums/INavObstacle__NavObstacleType_t.h"

class IPhysicsProp : public virtual IBreakableProp
{
public:
    virtual ~IPhysicsProp() = default;

    virtual CEntityIOOutput& MotionEnabled() = 0;
    virtual void MotionEnabledUpdated() = 0;
    virtual CEntityIOOutput& OnAwakened() = 0;
    virtual void OnAwakenedUpdated() = 0;
    virtual CEntityIOOutput& OnAwake() = 0;
    virtual void OnAwakeUpdated() = 0;
    virtual CEntityIOOutput& OnAsleep() = 0;
    virtual void OnAsleepUpdated() = 0;
    virtual CEntityIOOutput& OnPlayerUse() = 0;
    virtual void OnPlayerUseUpdated() = 0;
    virtual CEntityIOOutput& OnOutOfWorld() = 0;
    virtual void OnOutOfWorldUpdated() = 0;
    virtual CEntityIOOutput& OnPlayerPickup() = 0;
    virtual void OnPlayerPickupUpdated() = 0;
    virtual bool& ForceNavIgnore() = 0;
    virtual void ForceNavIgnoreUpdated() = 0;
    virtual bool& NoNavmeshBlocker() = 0;
    virtual void NoNavmeshBlockerUpdated() = 0;
    virtual bool& ForceNpcExclude() = 0;
    virtual void ForceNpcExcludeUpdated() = 0;
    virtual float& MassScale() = 0;
    virtual void MassScaleUpdated() = 0;
    virtual float& BuoyancyScale() = 0;
    virtual void BuoyancyScaleUpdated() = 0;
    virtual int32_t& DamageType() = 0;
    virtual void DamageTypeUpdated() = 0;
    virtual int32_t& DamageToEnableMotion() = 0;
    virtual void DamageToEnableMotionUpdated() = 0;
    virtual float& ForceToEnableMotion() = 0;
    virtual void ForceToEnableMotionUpdated() = 0;
    virtual bool& ThrownByPlayer() = 0;
    virtual void ThrownByPlayerUpdated() = 0;
    virtual bool& DroppedByPlayer() = 0;
    virtual void DroppedByPlayerUpdated() = 0;
    virtual bool& TouchedByPlayer() = 0;
    virtual void TouchedByPlayerUpdated() = 0;
    virtual bool& FirstCollisionAfterLaunch() = 0;
    virtual void FirstCollisionAfterLaunchUpdated() = 0;
    virtual bool& HasBeenAwakened() = 0;
    virtual void HasBeenAwakenedUpdated() = 0;
    virtual bool& IsOverrideProp() = 0;
    virtual void IsOverridePropUpdated() = 0;
    virtual float& LastBurn() = 0;
    virtual void LastBurnUpdated() = 0;
    virtual DynamicContinuousContactBehavior_t& DynamicContinuousContactBehavior() = 0;
    virtual void DynamicContinuousContactBehaviorUpdated() = 0;
    virtual float& NextCheckDisableMotionContactsTime() = 0;
    virtual void NextCheckDisableMotionContactsTimeUpdated() = 0;
    virtual int32_t& InitialGlowState() = 0;
    virtual void InitialGlowStateUpdated() = 0;
    virtual int32_t& GlowRange() = 0;
    virtual void GlowRangeUpdated() = 0;
    virtual int32_t& GlowRangeMin() = 0;
    virtual void GlowRangeMinUpdated() = 0;
    virtual Color& GlowColor() = 0;
    virtual void GlowColorUpdated() = 0;
    virtual bool& ShouldAutoConvertBackFromDebris() = 0;
    virtual void ShouldAutoConvertBackFromDebrisUpdated() = 0;
    virtual bool& MuteImpactEffects() = 0;
    virtual void MuteImpactEffectsUpdated() = 0;
    virtual INavObstacle__NavObstacleType_t& NavObstacleType() = 0;
    virtual void NavObstacleTypeUpdated() = 0;
    virtual bool& UpdateNavWhenMoving() = 0;
    virtual void UpdateNavWhenMovingUpdated() = 0;
    virtual bool& ForceNavObstacleCut() = 0;
    virtual void ForceNavObstacleCutUpdated() = 0;
    virtual bool& AllowObstacleConvexHullMerging() = 0;
    virtual void AllowObstacleConvexHullMergingUpdated() = 0;
    virtual bool& AcceptDamageFromHeldObjects() = 0;
    virtual void AcceptDamageFromHeldObjectsUpdated() = 0;
    virtual bool& EnableUseOutput() = 0;
    virtual void EnableUseOutputUpdated() = 0;
    virtual CPhysicsProp__CrateType_t& CrateType() = 0;
    virtual void CrateTypeUpdated() = 0;
    virtual CUtlSymbolLarge* StrItemClass() = 0;
    virtual int32_t* ItemCount() = 0;
    virtual bool& RemovableForAmmoBalancing() = 0;
    virtual void RemovableForAmmoBalancingUpdated() = 0;
    virtual bool& Awake() = 0;
    virtual void AwakeUpdated() = 0;
    virtual bool& AttachedToReferenceFrame() = 0;
    virtual void AttachedToReferenceFrameUpdated() = 0;
};

#endif // _INCLUDE_IPHYSICSPROP_H
