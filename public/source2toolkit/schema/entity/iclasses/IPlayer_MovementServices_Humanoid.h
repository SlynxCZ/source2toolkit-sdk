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

#ifndef _INCLUDE_IPLAYER_MOVEMENTSERVICES_HUMANOID_H
#define _INCLUDE_IPLAYER_MOVEMENTSERVICES_HUMANOID_H

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
#include <cstdint>

#include "IPlayer_MovementServices.h"

class IPlayer_MovementServices_Humanoid : public virtual IPlayer_MovementServices
{
public:
    virtual ~IPlayer_MovementServices_Humanoid() = default;

    virtual float& StepSoundTime() = 0;
    virtual void StepSoundTimeUpdated() = 0;
    virtual float& FallVelocity() = 0;
    virtual void FallVelocityUpdated() = 0;
    virtual Vector& GroundNormal() = 0;
    virtual void GroundNormalUpdated() = 0;
    virtual float& SurfaceFriction() = 0;
    virtual void SurfaceFrictionUpdated() = 0;
    virtual CUtlStringToken* SurfaceProps() = 0;
    virtual int32_t& Stepside() = 0;
    virtual void StepsideUpdated() = 0;
    virtual Vector& SmoothedVelocity() = 0;
    virtual void SmoothedVelocityUpdated() = 0;
};

#endif // _INCLUDE_IPLAYER_MOVEMENTSERVICES_HUMANOID_H
