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

#ifndef _INCLUDE_IFUNCROTATOR_H
#define _INCLUDE_IFUNCROTATOR_H

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

#include "IBaseModelEntity.h"

#include "../enums/CFuncRotator__Rotate_t.h"
#include "../enums/RotatorTargetSpace_t.h"

class CBaseEntity;
class CFuncMover;
class CFuncRotator;
class RotatorHistoryEntry_t;
class RotatorQueueEntry_t;

class IFuncRotator : public virtual IBaseModelEntity
{
public:
    virtual ~IFuncRotator() = default;
    CFuncRotator* GetOriginal() { return reinterpret_cast<CFuncRotator*>(IEntityInstance::GetOriginal()); }

    virtual CHandle<CBaseEntity>& RotatorTarget() = 0;
    virtual void RotatorTargetUpdated() = 0;
    virtual bool& IsRotating() = 0;
    virtual void IsRotatingUpdated() = 0;
    virtual bool& IsReversing() = 0;
    virtual void IsReversingUpdated() = 0;
    virtual float& TimeToReachMaxSpeed() = 0;
    virtual void TimeToReachMaxSpeedUpdated() = 0;
    virtual float& TimeToReachZeroSpeed() = 0;
    virtual void TimeToReachZeroSpeedUpdated() = 0;
    virtual float& DistanceAlongArcTraveled() = 0;
    virtual void DistanceAlongArcTraveledUpdated() = 0;
    virtual float& TimeToWaitOscillate() = 0;
    virtual void TimeToWaitOscillateUpdated() = 0;
    virtual float& TimeRotationStart() = 0;
    virtual void TimeRotationStartUpdated() = 0;
    virtual Quaternion& LSPrevChange() = 0;
    virtual void LSPrevChangeUpdated() = 0;
    virtual Quaternion& WSPrev() = 0;
    virtual void WSPrevUpdated() = 0;
    virtual Quaternion& WSInit() = 0;
    virtual void WSInitUpdated() = 0;
    virtual Quaternion& LSInit() = 0;
    virtual void LSInitUpdated() = 0;
    virtual Quaternion& LSOrientation() = 0;
    virtual void LSOrientationUpdated() = 0;
    virtual ::CEntityIOOutput& OnRotationStarted() = 0;
    virtual void OnRotationStartedUpdated() = 0;
    virtual ::CEntityIOOutput& OnRotationCompleted() = 0;
    virtual void OnRotationCompletedUpdated() = 0;
    virtual ::CEntityIOOutput& OnOscillate() = 0;
    virtual void OnOscillateUpdated() = 0;
    virtual ::CEntityIOOutput& OnOscillateStartArrive() = 0;
    virtual void OnOscillateStartArriveUpdated() = 0;
    virtual ::CEntityIOOutput& OnOscillateStartDepart() = 0;
    virtual void OnOscillateStartDepartUpdated() = 0;
    virtual ::CEntityIOOutput& OnOscillateEndArrive() = 0;
    virtual void OnOscillateEndArriveUpdated() = 0;
    virtual ::CEntityIOOutput& OnOscillateEndDepart() = 0;
    virtual void OnOscillateEndDepartUpdated() = 0;
    virtual bool& OscillateDepart() = 0;
    virtual void OscillateDepartUpdated() = 0;
    virtual int32_t& OscillateCount() = 0;
    virtual void OscillateCountUpdated() = 0;
    virtual ::CFuncRotator__Rotate_t& RotateType() = 0;
    virtual void RotateTypeUpdated() = 0;
    virtual ::CFuncRotator__Rotate_t& PrevRotateType() = 0;
    virtual void PrevRotateTypeUpdated() = 0;
    virtual bool& HasTargetOverride() = 0;
    virtual void HasTargetOverrideUpdated() = 0;
    virtual Quaternion& OrientationOverride() = 0;
    virtual void OrientationOverrideUpdated() = 0;
    virtual ::RotatorTargetSpace_t& SpaceOverride() = 0;
    virtual void SpaceOverrideUpdated() = 0;
    virtual QAngle& AngularVelocity() = 0;
    virtual void AngularVelocityUpdated() = 0;
    virtual Vector& LookAtForcedUp() = 0;
    virtual void LookAtForcedUpUpdated() = 0;
    virtual CUtlSymbolLarge& StrRotatorTarget() = 0;
    virtual void StrRotatorTargetUpdated() = 0;
    virtual bool& RecordHistory() = 0;
    virtual void RecordHistoryUpdated() = 0;
    virtual CUtlVector<RotatorHistoryEntry_t>& RotatorHistory() = 0;
    virtual void RotatorHistoryUpdated() = 0;
    virtual bool& ReturningToPreviousOrientation() = 0;
    virtual void ReturningToPreviousOrientationUpdated() = 0;
    virtual CUtlVector<RotatorQueueEntry_t>& RotatorQueue() = 0;
    virtual void RotatorQueueUpdated() = 0;
    virtual CUtlVector<RotatorHistoryEntry_t>& RotatorQueueHistory() = 0;
    virtual void RotatorQueueHistoryUpdated() = 0;
    virtual ::SolidType_t& SolidType() = 0;
    virtual void SolidTypeUpdated() = 0;
    virtual CHandle<CFuncMover>& SpeedFromMover() = 0;
    virtual void SpeedFromMoverUpdated() = 0;
    virtual CUtlSymbolLarge& SpeedFromMover() = 0;
    virtual void SpeedFromMoverUpdated() = 0;
    virtual float& SpeedScale() = 0;
    virtual void SpeedScaleUpdated() = 0;
    virtual float& MinYawRotation() = 0;
    virtual void MinYawRotationUpdated() = 0;
    virtual float& MaxYawRotation() = 0;
    virtual void MaxYawRotationUpdated() = 0;
    static IFuncRotator* FromOriginal(CFuncRotator* p);
};

#endif // _INCLUDE_IFUNCROTATOR_H
