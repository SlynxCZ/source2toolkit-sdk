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

#ifndef _INCLUDE_IPHYSHINGE_H
#define _INCLUDE_IPHYSHINGE_H

#pragma once

#include <cstdint>

#include "IPhysConstraint.h"

#include "ConstraintSoundInfo.h"
#include "constraint_hingeparams_t.h"

class IPhysHinge : public virtual IPhysConstraint
{
public:
    virtual ~IPhysHinge() = default;

    virtual ConstraintSoundInfo& SoundInfo() = 0;
    virtual void SoundInfoUpdated() = 0;
    virtual CEntityIOOutput& NotifyMinLimitReached() = 0;
    virtual void NotifyMinLimitReachedUpdated() = 0;
    virtual CEntityIOOutput& NotifyMaxLimitReached() = 0;
    virtual void NotifyMaxLimitReachedUpdated() = 0;
    virtual bool& AtMinLimit() = 0;
    virtual void AtMinLimitUpdated() = 0;
    virtual bool& AtMaxLimit() = 0;
    virtual void AtMaxLimitUpdated() = 0;
    virtual constraint_hingeparams_t& Hinge() = 0;
    virtual void HingeUpdated() = 0;
    virtual float& HingeFriction() = 0;
    virtual void HingeFrictionUpdated() = 0;
    virtual float& SystemLoadScale() = 0;
    virtual void SystemLoadScaleUpdated() = 0;
    virtual bool& IsAxisLocal() = 0;
    virtual void IsAxisLocalUpdated() = 0;
    virtual float& MinRotation() = 0;
    virtual void MinRotationUpdated() = 0;
    virtual float& MaxRotation() = 0;
    virtual void MaxRotationUpdated() = 0;
    virtual float& InitialRotation() = 0;
    virtual void InitialRotationUpdated() = 0;
    virtual float& MotorFrequency() = 0;
    virtual void MotorFrequencyUpdated() = 0;
    virtual float& MotorDampingRatio() = 0;
    virtual void MotorDampingRatioUpdated() = 0;
    virtual float& AngleSpeed() = 0;
    virtual void AngleSpeedUpdated() = 0;
    virtual float& AngleSpeedThreshold() = 0;
    virtual void AngleSpeedThresholdUpdated() = 0;
    virtual float& LimitsDebugVisRotation() = 0;
    virtual void LimitsDebugVisRotationUpdated() = 0;
    virtual CEntityIOOutput& OnStartMoving() = 0;
    virtual void OnStartMovingUpdated() = 0;
    virtual CEntityIOOutput& OnStopMoving() = 0;
    virtual void OnStopMovingUpdated() = 0;
};

#endif // _INCLUDE_IPHYSHINGE_H
