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

#ifndef _INCLUDE_IGENERICCONSTRAINT_H
#define _INCLUDE_IGENERICCONSTRAINT_H

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

#include "IPhysConstraint.h"

#include "../enums/JointMotion_t.h"

class CGenericConstraint;

class IGenericConstraint : public virtual IPhysConstraint
{
public:
    virtual ~IGenericConstraint() = default;

    virtual bool& PlaceAnchorsAtConstraintTransform() = 0;
    virtual void PlaceAnchorsAtConstraintTransformUpdated() = 0;
    virtual ::JointMotion_t& LinearMotionX() = 0;
    virtual void LinearMotionXUpdated() = 0;
    virtual ::JointMotion_t& LinearMotionY() = 0;
    virtual void LinearMotionYUpdated() = 0;
    virtual ::JointMotion_t& LinearMotionZ() = 0;
    virtual void LinearMotionZUpdated() = 0;
    virtual float& LinearFrequencyX() = 0;
    virtual void LinearFrequencyXUpdated() = 0;
    virtual float& LinearFrequencyY() = 0;
    virtual void LinearFrequencyYUpdated() = 0;
    virtual float& LinearFrequencyZ() = 0;
    virtual void LinearFrequencyZUpdated() = 0;
    virtual float& LinearDampingRatioX() = 0;
    virtual void LinearDampingRatioXUpdated() = 0;
    virtual float& LinearDampingRatioY() = 0;
    virtual void LinearDampingRatioYUpdated() = 0;
    virtual float& LinearDampingRatioZ() = 0;
    virtual void LinearDampingRatioZUpdated() = 0;
    virtual float& MaxLinearImpulseX() = 0;
    virtual void MaxLinearImpulseXUpdated() = 0;
    virtual float& MaxLinearImpulseY() = 0;
    virtual void MaxLinearImpulseYUpdated() = 0;
    virtual float& MaxLinearImpulseZ() = 0;
    virtual void MaxLinearImpulseZUpdated() = 0;
    virtual float& BreakAfterTimeX() = 0;
    virtual void BreakAfterTimeXUpdated() = 0;
    virtual float& BreakAfterTimeY() = 0;
    virtual void BreakAfterTimeYUpdated() = 0;
    virtual float& BreakAfterTimeZ() = 0;
    virtual void BreakAfterTimeZUpdated() = 0;
    virtual float& BreakAfterTimeStartTimeX() = 0;
    virtual void BreakAfterTimeStartTimeXUpdated() = 0;
    virtual float& BreakAfterTimeStartTimeY() = 0;
    virtual void BreakAfterTimeStartTimeYUpdated() = 0;
    virtual float& BreakAfterTimeStartTimeZ() = 0;
    virtual void BreakAfterTimeStartTimeZUpdated() = 0;
    virtual float& BreakAfterTimeThresholdX() = 0;
    virtual void BreakAfterTimeThresholdXUpdated() = 0;
    virtual float& BreakAfterTimeThresholdY() = 0;
    virtual void BreakAfterTimeThresholdYUpdated() = 0;
    virtual float& BreakAfterTimeThresholdZ() = 0;
    virtual void BreakAfterTimeThresholdZUpdated() = 0;
    virtual float& NotifyForceX() = 0;
    virtual void NotifyForceXUpdated() = 0;
    virtual float& NotifyForceY() = 0;
    virtual void NotifyForceYUpdated() = 0;
    virtual float& NotifyForceZ() = 0;
    virtual void NotifyForceZUpdated() = 0;
    virtual float& NotifyForceMinTimeX() = 0;
    virtual void NotifyForceMinTimeXUpdated() = 0;
    virtual float& NotifyForceMinTimeY() = 0;
    virtual void NotifyForceMinTimeYUpdated() = 0;
    virtual float& NotifyForceMinTimeZ() = 0;
    virtual void NotifyForceMinTimeZUpdated() = 0;
    virtual float& NotifyForceLastTimeX() = 0;
    virtual void NotifyForceLastTimeXUpdated() = 0;
    virtual float& NotifyForceLastTimeY() = 0;
    virtual void NotifyForceLastTimeYUpdated() = 0;
    virtual float& NotifyForceLastTimeZ() = 0;
    virtual void NotifyForceLastTimeZUpdated() = 0;
    virtual bool& AxisNotifiedX() = 0;
    virtual void AxisNotifiedXUpdated() = 0;
    virtual bool& AxisNotifiedY() = 0;
    virtual void AxisNotifiedYUpdated() = 0;
    virtual bool& AxisNotifiedZ() = 0;
    virtual void AxisNotifiedZUpdated() = 0;
    virtual ::JointMotion_t& AngularMotionX() = 0;
    virtual void AngularMotionXUpdated() = 0;
    virtual ::JointMotion_t& AngularMotionY() = 0;
    virtual void AngularMotionYUpdated() = 0;
    virtual ::JointMotion_t& AngularMotionZ() = 0;
    virtual void AngularMotionZUpdated() = 0;
    virtual float& AngularFrequencyX() = 0;
    virtual void AngularFrequencyXUpdated() = 0;
    virtual float& AngularFrequencyY() = 0;
    virtual void AngularFrequencyYUpdated() = 0;
    virtual float& AngularFrequencyZ() = 0;
    virtual void AngularFrequencyZUpdated() = 0;
    virtual float& AngularDampingRatioX() = 0;
    virtual void AngularDampingRatioXUpdated() = 0;
    virtual float& AngularDampingRatioY() = 0;
    virtual void AngularDampingRatioYUpdated() = 0;
    virtual float& AngularDampingRatioZ() = 0;
    virtual void AngularDampingRatioZUpdated() = 0;
    virtual float& MaxAngularImpulseX() = 0;
    virtual void MaxAngularImpulseXUpdated() = 0;
    virtual float& MaxAngularImpulseY() = 0;
    virtual void MaxAngularImpulseYUpdated() = 0;
    virtual float& MaxAngularImpulseZ() = 0;
    virtual void MaxAngularImpulseZUpdated() = 0;
    virtual ::CEntityIOOutput& NotifyForceReachedX() = 0;
    virtual void NotifyForceReachedXUpdated() = 0;
    virtual ::CEntityIOOutput& NotifyForceReachedY() = 0;
    virtual void NotifyForceReachedYUpdated() = 0;
    virtual ::CEntityIOOutput& NotifyForceReachedZ() = 0;
    virtual void NotifyForceReachedZUpdated() = 0;
    static IGenericConstraint* FromOriginal(CGenericConstraint* p);
};

#endif // _INCLUDE_IGENERICCONSTRAINT_H
