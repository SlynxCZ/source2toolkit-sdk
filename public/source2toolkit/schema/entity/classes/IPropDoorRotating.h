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

#ifndef _INCLUDE_IPROPDOORROTATING_H
#define _INCLUDE_IPROPDOORROTATING_H

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

#include "IBasePropDoor.h"

#include "../enums/PropDoorRotatingOpenDirection_e.h"
#include "../enums/PropDoorRotatingSpawnPos_t.h"
#include "../enums/doorCheck_e.h"

class CEntityBlocker;
class CPropDoorRotating;

class IPropDoorRotating : public virtual IBasePropDoor
{
public:
    virtual ~IPropDoorRotating() = default;

    virtual Vector& Axis() = 0;
    virtual void AxisUpdated() = 0;
    virtual float& Distance() = 0;
    virtual void DistanceUpdated() = 0;
    virtual ::PropDoorRotatingSpawnPos_t& SpawnPosition() = 0;
    virtual void SpawnPositionUpdated() = 0;
    virtual ::PropDoorRotatingOpenDirection_e& OpenDirection() = 0;
    virtual void OpenDirectionUpdated() = 0;
    virtual ::PropDoorRotatingOpenDirection_e& CurrentOpenDirection() = 0;
    virtual void CurrentOpenDirectionUpdated() = 0;
    virtual ::doorCheck_e& DefaultCheckDirection() = 0;
    virtual void DefaultCheckDirectionUpdated() = 0;
    virtual float& AjarAngle() = 0;
    virtual void AjarAngleUpdated() = 0;
    virtual QAngle& RotationAjarDeprecated() = 0;
    virtual void RotationAjarDeprecatedUpdated() = 0;
    virtual QAngle& RotationClosed() = 0;
    virtual void RotationClosedUpdated() = 0;
    virtual QAngle& RotationOpenForward() = 0;
    virtual void RotationOpenForwardUpdated() = 0;
    virtual QAngle& RotationOpenBack() = 0;
    virtual void RotationOpenBackUpdated() = 0;
    virtual QAngle& Goal() = 0;
    virtual void GoalUpdated() = 0;
    virtual Vector& ForwardBoundsMin() = 0;
    virtual void ForwardBoundsMinUpdated() = 0;
    virtual Vector& ForwardBoundsMax() = 0;
    virtual void ForwardBoundsMaxUpdated() = 0;
    virtual Vector& BackBoundsMin() = 0;
    virtual void BackBoundsMinUpdated() = 0;
    virtual Vector& BackBoundsMax() = 0;
    virtual void BackBoundsMaxUpdated() = 0;
    virtual bool& AjarDoorShouldntAlwaysOpen() = 0;
    virtual void AjarDoorShouldntAlwaysOpenUpdated() = 0;
    virtual CHandle<CEntityBlocker>& EntityBlocker() = 0;
    virtual void EntityBlockerUpdated() = 0;
    static IPropDoorRotating* FromOriginal(CPropDoorRotating* p);
};

#endif // _INCLUDE_IPROPDOORROTATING_H
