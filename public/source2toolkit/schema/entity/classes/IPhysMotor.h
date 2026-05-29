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

#ifndef _INCLUDE_IPHYSMOTOR_H
#define _INCLUDE_IPHYSMOTOR_H

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

#include "ILogicalEntity.h"

class CBaseEntity;
class CMotorController;
class CPhysMotor;
class IPhysicsBody;
class IPhysicsJoint;

class IPhysMotor : public virtual ILogicalEntity
{
public:
    virtual ~IPhysMotor() = default;

    virtual CUtlSymbolLarge& NameAttach() = 0;
    virtual void NameAttachUpdated() = 0;
    virtual CUtlSymbolLarge& NameAnchor() = 0;
    virtual void NameAnchorUpdated() = 0;
    virtual CHandle<CBaseEntity>& AttachedObject() = 0;
    virtual void AttachedObjectUpdated() = 0;
    virtual CHandle<CBaseEntity>& AnchorObject() = 0;
    virtual void AnchorObjectUpdated() = 0;
    virtual float& SpinUp() = 0;
    virtual void SpinUpUpdated() = 0;
    virtual float& SpinDown() = 0;
    virtual void SpinDownUpdated() = 0;
    virtual float& MotorFriction() = 0;
    virtual void MotorFrictionUpdated() = 0;
    virtual float& AdditionalAcceleration() = 0;
    virtual void AdditionalAccelerationUpdated() = 0;
    virtual float& AngularAcceleration() = 0;
    virtual void AngularAccelerationUpdated() = 0;
    virtual float& TorqueScale() = 0;
    virtual void TorqueScaleUpdated() = 0;
    virtual float& TargetSpeed() = 0;
    virtual void TargetSpeedUpdated() = 0;
    virtual float& SpeedWhenSpinUpOrSpinDownStarted() = 0;
    virtual void SpeedWhenSpinUpOrSpinDownStartedUpdated() = 0;
    virtual IPhysicsBody*& FixedWorldBody() = 0;
    virtual void FixedWorldBodyUpdated() = 0;
    virtual IPhysicsJoint*& MotorJoint() = 0;
    virtual void MotorJointUpdated() = 0;
    virtual ::CMotorController& Motor() = 0;
    virtual void MotorUpdated() = 0;
    static IPhysMotor* FromOriginal(CPhysMotor* p);
};

#endif // _INCLUDE_IPHYSMOTOR_H
