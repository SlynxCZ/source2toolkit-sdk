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

#ifndef _INCLUDE_ISPLINECONSTRAINT_H
#define _INCLUDE_ISPLINECONSTRAINT_H

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

class CBaseEntity;
class CSplineConstraint;
class IPhysicsBody;

class ISplineConstraint : public virtual IPhysConstraint
{
public:
    virtual ~ISplineConstraint() = default;

    virtual Vector& AnchorOffsetRestore() = 0;
    virtual void AnchorOffsetRestoreUpdated() = 0;
    virtual CHandle<CBaseEntity>& SplineEntity() = 0;
    virtual void SplineEntityUpdated() = 0;
    virtual IPhysicsBody*& SplineBody() = 0;
    virtual void SplineBodyUpdated() = 0;
    virtual bool& EnableLateralConstraint() = 0;
    virtual void EnableLateralConstraintUpdated() = 0;
    virtual bool& EnableVerticalConstraint() = 0;
    virtual void EnableVerticalConstraintUpdated() = 0;
    virtual bool& EnableAngularConstraint() = 0;
    virtual void EnableAngularConstraintUpdated() = 0;
    virtual bool& EnableLimit() = 0;
    virtual void EnableLimitUpdated() = 0;
    virtual bool& FireEventsOnPath() = 0;
    virtual void FireEventsOnPathUpdated() = 0;
    virtual float& LinearFrequency() = 0;
    virtual void LinearFrequencyUpdated() = 0;
    virtual float& LinarDampingRatio() = 0;
    virtual void LinarDampingRatioUpdated() = 0;
    virtual float& JointFriction() = 0;
    virtual void JointFrictionUpdated() = 0;
    virtual float& TransitionTime() = 0;
    virtual void TransitionTimeUpdated() = 0;
    virtual Vector& PreSolveAnchorPos() = 0;
    virtual void PreSolveAnchorPosUpdated() = 0;
    virtual float& StartTransitionTime() = 0;
    virtual void StartTransitionTimeUpdated() = 0;
    virtual Vector& TangentSpaceAnchorAtTransitionStart() = 0;
    virtual void TangentSpaceAnchorAtTransitionStartUpdated() = 0;
    static ISplineConstraint* FromOriginal(CSplineConstraint* p);
};

#endif // _INCLUDE_ISPLINECONSTRAINT_H
