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

#ifndef _INCLUDE_ITRIGGERPHYSICS_H
#define _INCLUDE_ITRIGGERPHYSICS_H

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

#include "IBaseTrigger.h"

class CTriggerPhysics;
class IPhysicsMotionController;

class ITriggerPhysics : public virtual IBaseTrigger
{
public:
    virtual ~ITriggerPhysics() = default;
    CTriggerPhysics* GetOriginal() { return reinterpret_cast<CTriggerPhysics*>(IEntityInstance::GetOriginal()); }

    virtual IPhysicsMotionController*& Controller() = 0;
    virtual void ControllerUpdated() = 0;
    virtual float& GravityScale() = 0;
    virtual void GravityScaleUpdated() = 0;
    virtual float& LinearLimit() = 0;
    virtual void LinearLimitUpdated() = 0;
    virtual float& LinearDamping() = 0;
    virtual void LinearDampingUpdated() = 0;
    virtual float& AngularLimit() = 0;
    virtual void AngularLimitUpdated() = 0;
    virtual float& AngularDamping() = 0;
    virtual void AngularDampingUpdated() = 0;
    virtual float& LinearForce() = 0;
    virtual void LinearForceUpdated() = 0;
    virtual float& Frequency() = 0;
    virtual void FrequencyUpdated() = 0;
    virtual float& DampingRatio() = 0;
    virtual void DampingRatioUpdated() = 0;
    virtual Vector& LinearForcePointAt() = 0;
    virtual void LinearForcePointAtUpdated() = 0;
    virtual bool& CollapseToForcePoint() = 0;
    virtual void CollapseToForcePointUpdated() = 0;
    virtual Vector& LinearForcePointAtWorld() = 0;
    virtual void LinearForcePointAtWorldUpdated() = 0;
    virtual Vector& LinearForceDirection() = 0;
    virtual void LinearForceDirectionUpdated() = 0;
    virtual bool& ConvertToDebrisWhenPossible() = 0;
    virtual void ConvertToDebrisWhenPossibleUpdated() = 0;
    static ITriggerPhysics* FromOriginal(CTriggerPhysics* p);
};

#endif // _INCLUDE_ITRIGGERPHYSICS_H
