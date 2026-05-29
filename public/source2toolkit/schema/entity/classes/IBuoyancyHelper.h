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

#ifndef _INCLUDE_IBUOYANCYHELPER_H
#define _INCLUDE_IBUOYANCYHELPER_H

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

class CBuoyancyHelper;
class IPhysicsMotionController;

class IBuoyancyHelper
{
public:
    virtual ~IBuoyancyHelper() = default;
    CBuoyancyHelper* GetOriginal() { return reinterpret_cast<CBuoyancyHelper*>(IEntityInstance::GetOriginal()); }

    virtual IPhysicsMotionController*& Controller() = 0;
    virtual void ControllerUpdated() = 0;
    virtual CUtlStringToken* FluidType() = 0;
    virtual float& FluidDensity() = 0;
    virtual void FluidDensityUpdated() = 0;
    virtual float& NeutrallyBuoyantGravity() = 0;
    virtual void NeutrallyBuoyantGravityUpdated() = 0;
    virtual float& NeutrallyBuoyantLinearDamping() = 0;
    virtual void NeutrallyBuoyantLinearDampingUpdated() = 0;
    virtual float& NeutrallyBuoyantAngularDamping() = 0;
    virtual void NeutrallyBuoyantAngularDampingUpdated() = 0;
    virtual bool& NeutrallyBuoyant() = 0;
    virtual void NeutrallyBuoyantUpdated() = 0;
    virtual CUtlVector<float>& FractionOfWheelSubmergedForWheelFriction() = 0;
    virtual void FractionOfWheelSubmergedForWheelFrictionUpdated() = 0;
    virtual CUtlVector<float>& WheelFrictionScales() = 0;
    virtual void WheelFrictionScalesUpdated() = 0;
    virtual CUtlVector<float>& FractionOfWheelSubmergedForWheelDrag() = 0;
    virtual void FractionOfWheelSubmergedForWheelDragUpdated() = 0;
    virtual CUtlVector<float>& WheelDrag() = 0;
    virtual void WheelDragUpdated() = 0;
    static IBuoyancyHelper* FromOriginal(CBuoyancyHelper* p);
};

#endif // _INCLUDE_IBUOYANCYHELPER_H
