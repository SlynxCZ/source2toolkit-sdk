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

#ifndef _INCLUDE_ICHICKEN_H
#define _INCLUDE_ICHICKEN_H

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
#include "source2toolkit/schema/schema.h"
#include <cstdint>

#include "IDynamicProp.h"

#include "../enums/ChickenActivity.h"

class CAttributeContainer;
class CBaseEntity;
class CCSPlayerPawn;
class CChicken;
class CountdownTimer;

class IChicken : public virtual IDynamicProp
{
public:
    virtual ~IChicken() = default;
    CChicken* GetOriginal() { return reinterpret_cast<CChicken*>(IEntityInstance::GetOriginal()); }

    virtual ::CAttributeContainer& AttributeManager() = 0;
    virtual void AttributeManagerUpdated() = 0;
    virtual ::CountdownTimer& UpdateTimer() = 0;
    virtual void UpdateTimerUpdated() = 0;
    virtual Vector& StuckAnchor() = 0;
    virtual void StuckAnchorUpdated() = 0;
    virtual ::CountdownTimer& StuckTimer() = 0;
    virtual void StuckTimerUpdated() = 0;
    virtual ::CountdownTimer& CollisionStuckTimer() = 0;
    virtual void CollisionStuckTimerUpdated() = 0;
    virtual bool& IsOnGround() = 0;
    virtual void IsOnGroundUpdated() = 0;
    virtual Vector& FallVelocity() = 0;
    virtual void FallVelocityUpdated() = 0;
    virtual ::ChickenActivity& DesiredActivity() = 0;
    virtual void DesiredActivityUpdated() = 0;
    virtual ::ChickenActivity& CurrentActivity() = 0;
    virtual void CurrentActivityUpdated() = 0;
    virtual ::CountdownTimer& ActivityTimer() = 0;
    virtual void ActivityTimerUpdated() = 0;
    virtual float& TurnRate() = 0;
    virtual void TurnRateUpdated() = 0;
    virtual CHandle<CBaseEntity>& FleeFrom() = 0;
    virtual void FleeFromUpdated() = 0;
    virtual ::CountdownTimer& MoveRateThrottleTimer() = 0;
    virtual void MoveRateThrottleTimerUpdated() = 0;
    virtual ::CountdownTimer& StartleTimer() = 0;
    virtual void StartleTimerUpdated() = 0;
    virtual ::CountdownTimer& VocalizeTimer() = 0;
    virtual void VocalizeTimerUpdated() = 0;
    virtual float& WhenZombified() = 0;
    virtual void WhenZombifiedUpdated() = 0;
    virtual bool& JumpedThisFrame() = 0;
    virtual void JumpedThisFrameUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& Leader() = 0;
    virtual void LeaderUpdated() = 0;
    virtual ::CountdownTimer& ReuseTimer() = 0;
    virtual void ReuseTimerUpdated() = 0;
    virtual bool& HasBeenUsed() = 0;
    virtual void HasBeenUsedUpdated() = 0;
    virtual ::CountdownTimer& JumpTimer() = 0;
    virtual void JumpTimerUpdated() = 0;
    virtual float& LastJumpTime() = 0;
    virtual void LastJumpTimeUpdated() = 0;
    virtual bool& InJump() = 0;
    virtual void InJumpUpdated() = 0;
    virtual ::CountdownTimer& RepathTimer() = 0;
    virtual void RepathTimerUpdated() = 0;
    virtual Vector& PathGoal() = 0;
    virtual void PathGoalUpdated() = 0;
    virtual float& ActiveFollowStartTime() = 0;
    virtual void ActiveFollowStartTimeUpdated() = 0;
    virtual ::CountdownTimer& FollowMinuteTimer() = 0;
    virtual void FollowMinuteTimerUpdated() = 0;
    virtual ::CountdownTimer& BlockDirectionTimer() = 0;
    virtual void BlockDirectionTimerUpdated() = 0;
    static IChicken* FromOriginal(CChicken* p);
};

#endif // _INCLUDE_ICHICKEN_H
