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

#ifndef _INCLUDE_IRAGDOLLPROP_H
#define _INCLUDE_IRAGDOLLPROP_H

#pragma once

#include <cstdint>

#include "IBaseAnimGraph.h"

#include "../enums/INavObstacle__NavObstacleType_t.h"
#include "ragdoll_t.h"

class CBaseEntity;
class CBasePlayerPawn;
class INavObstacle;

class IRagdollProp : public virtual IBaseAnimGraph
{
public:
    virtual ~IRagdollProp() = default;

    virtual ragdoll_t& Ragdoll() = 0;
    virtual void RagdollUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual CUtlVector<bool>& RagEnabled() = 0;
    virtual void RagEnabledUpdated() = 0;
    virtual CUtlVector<Vector>& RagPos() = 0;
    virtual void RagPosUpdated() = 0;
    virtual CUtlVector<QAngle>& RagAngles() = 0;
    virtual void RagAnglesUpdated() = 0;
    virtual uint32_t& LastUpdateTickCount() = 0;
    virtual void LastUpdateTickCountUpdated() = 0;
    virtual bool& AllAsleep() = 0;
    virtual void AllAsleepUpdated() = 0;
    virtual bool& FirstCollisionAfterLaunch() = 0;
    virtual void FirstCollisionAfterLaunchUpdated() = 0;
    virtual INavObstacle__NavObstacleType_t& NavObstacleType() = 0;
    virtual void NavObstacleTypeUpdated() = 0;
    virtual bool& UpdateNavWhenMoving() = 0;
    virtual void UpdateNavWhenMovingUpdated() = 0;
    virtual bool& ForceNavObstacleCut() = 0;
    virtual void ForceNavObstacleCutUpdated() = 0;
    virtual bool& AttachedToReferenceFrame() = 0;
    virtual void AttachedToReferenceFrameUpdated() = 0;
    virtual CHandle<CBaseEntity>& DamageEntity() = 0;
    virtual void DamageEntityUpdated() = 0;
    virtual CHandle<CBaseEntity>& Killer() = 0;
    virtual void KillerUpdated() = 0;
    virtual CHandle<CBasePlayerPawn>& PhysicsAttacker() = 0;
    virtual void PhysicsAttackerUpdated() = 0;
    virtual float& LastPhysicsInfluenceTime() = 0;
    virtual void LastPhysicsInfluenceTimeUpdated() = 0;
    virtual float& FadeOutStartTime() = 0;
    virtual void FadeOutStartTimeUpdated() = 0;
    virtual float& FadeTime() = 0;
    virtual void FadeTimeUpdated() = 0;
    virtual Vector& LastOrigin() = 0;
    virtual void LastOriginUpdated() = 0;
    virtual float& AwakeTime() = 0;
    virtual void AwakeTimeUpdated() = 0;
    virtual float& LastOriginChangeTime() = 0;
    virtual void LastOriginChangeTimeUpdated() = 0;
    virtual CUtlSymbolLarge& StrOriginClassName() = 0;
    virtual void StrOriginClassNameUpdated() = 0;
    virtual CUtlSymbolLarge& StrSourceClassName() = 0;
    virtual void StrSourceClassNameUpdated() = 0;
    virtual bool& HasBeenPhysgunned() = 0;
    virtual void HasBeenPhysgunnedUpdated() = 0;
    virtual bool& AllowStretch() = 0;
    virtual void AllowStretchUpdated() = 0;
    virtual float& BlendWeight() = 0;
    virtual void BlendWeightUpdated() = 0;
    virtual float& DefaultFadeScale() = 0;
    virtual void DefaultFadeScaleUpdated() = 0;
    virtual CUtlVector<Vector>& RagdollMins() = 0;
    virtual void RagdollMinsUpdated() = 0;
    virtual CUtlVector<Vector>& RagdollMaxs() = 0;
    virtual void RagdollMaxsUpdated() = 0;
    virtual bool& ShouldDeleteActivationRecord() = 0;
    virtual void ShouldDeleteActivationRecordUpdated() = 0;
    virtual CUtlVector<INavObstacle*>& NavObstacles() = 0;
    virtual void NavObstaclesUpdated() = 0;
};

#endif // _INCLUDE_IRAGDOLLPROP_H
