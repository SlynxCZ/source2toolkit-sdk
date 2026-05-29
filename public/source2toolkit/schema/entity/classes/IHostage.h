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

#ifndef _INCLUDE_IHOSTAGE_H
#define _INCLUDE_IHOSTAGE_H

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

#include "IHostageExpresserShim.h"

class CBaseEntity;
class CCSPlayerPawn;
class CCSPlayerPawnBase;
class CHostage;
class CountdownTimer;
class EntitySpottedState_t;

class IHostage : public virtual IHostageExpresserShim
{
public:
    virtual ~IHostage() = default;

    virtual ::CEntityIOOutput& OnHostageBeginGrab() = 0;
    virtual void OnHostageBeginGrabUpdated() = 0;
    virtual ::CEntityIOOutput& OnFirstPickedUp() = 0;
    virtual void OnFirstPickedUpUpdated() = 0;
    virtual ::CEntityIOOutput& OnDroppedNotRescued() = 0;
    virtual void OnDroppedNotRescuedUpdated() = 0;
    virtual ::CEntityIOOutput& OnRescued() = 0;
    virtual void OnRescuedUpdated() = 0;
    virtual ::EntitySpottedState_t& EntitySpottedState() = 0;
    virtual void EntitySpottedStateUpdated() = 0;
    virtual int32_t& SpotRules() = 0;
    virtual void SpotRulesUpdated() = 0;
    virtual uint32_t& UiHostageSpawnExclusionGroupMask() = 0;
    virtual void UiHostageSpawnExclusionGroupMaskUpdated() = 0;
    virtual uint32_t& HostageSpawnRandomFactor() = 0;
    virtual void HostageSpawnRandomFactorUpdated() = 0;
    virtual bool& Remove() = 0;
    virtual void RemoveUpdated() = 0;
    virtual Vector& Vel() = 0;
    virtual void VelUpdated() = 0;
    virtual bool& IsRescued() = 0;
    virtual void IsRescuedUpdated() = 0;
    virtual bool& JumpedThisFrame() = 0;
    virtual void JumpedThisFrameUpdated() = 0;
    virtual int32_t& HostageState() = 0;
    virtual void HostageStateUpdated() = 0;
    virtual CHandle<CBaseEntity>& Leader() = 0;
    virtual void LeaderUpdated() = 0;
    virtual CHandle<CCSPlayerPawnBase>& LastLeader() = 0;
    virtual void LastLeaderUpdated() = 0;
    virtual ::CountdownTimer& ReuseTimer() = 0;
    virtual void ReuseTimerUpdated() = 0;
    virtual bool& HasBeenUsed() = 0;
    virtual void HasBeenUsedUpdated() = 0;
    virtual Vector& Accel() = 0;
    virtual void AccelUpdated() = 0;
    virtual bool& IsRunning() = 0;
    virtual void IsRunningUpdated() = 0;
    virtual bool& IsCrouching() = 0;
    virtual void IsCrouchingUpdated() = 0;
    virtual ::CountdownTimer& JumpTimer() = 0;
    virtual void JumpTimerUpdated() = 0;
    virtual bool& IsWaitingForLeader() = 0;
    virtual void IsWaitingForLeaderUpdated() = 0;
    virtual ::CountdownTimer& RepathTimer() = 0;
    virtual void RepathTimerUpdated() = 0;
    virtual ::CountdownTimer& InhibitDoorTimer() = 0;
    virtual void InhibitDoorTimerUpdated() = 0;
    virtual ::CountdownTimer& InhibitObstacleAvoidanceTimer() = 0;
    virtual void InhibitObstacleAvoidanceTimerUpdated() = 0;
    virtual ::CountdownTimer& WiggleTimer() = 0;
    virtual void WiggleTimerUpdated() = 0;
    virtual bool& IsAdjusted() = 0;
    virtual void IsAdjustedUpdated() = 0;
    virtual bool& HandsHaveBeenCut() = 0;
    virtual void HandsHaveBeenCutUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& HostageGrabber() = 0;
    virtual void HostageGrabberUpdated() = 0;
    virtual float& LastGrabTime() = 0;
    virtual void LastGrabTimeUpdated() = 0;
    virtual Vector& PositionWhenStartedDroppingToGround() = 0;
    virtual void PositionWhenStartedDroppingToGroundUpdated() = 0;
    virtual Vector& GrabbedPos() = 0;
    virtual void GrabbedPosUpdated() = 0;
    virtual float& RescueStartTime() = 0;
    virtual void RescueStartTimeUpdated() = 0;
    virtual float& GrabSuccessTime() = 0;
    virtual void GrabSuccessTimeUpdated() = 0;
    virtual float& DropStartTime() = 0;
    virtual void DropStartTimeUpdated() = 0;
    virtual int32_t& ApproachRewardPayouts() = 0;
    virtual void ApproachRewardPayoutsUpdated() = 0;
    virtual int32_t& PickupEventCount() = 0;
    virtual void PickupEventCountUpdated() = 0;
    virtual Vector& SpawnGroundPos() = 0;
    virtual void SpawnGroundPosUpdated() = 0;
    virtual Vector& HostageResetPosition() = 0;
    virtual void HostageResetPositionUpdated() = 0;
    static IHostage* FromOriginal(CHostage* p);
    static IHostage* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IHOSTAGE_H
