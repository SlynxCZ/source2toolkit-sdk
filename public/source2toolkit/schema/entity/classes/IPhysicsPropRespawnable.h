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

#ifndef _INCLUDE_IPHYSICSPROPRESPAWNABLE_H
#define _INCLUDE_IPHYSICSPROPRESPAWNABLE_H

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

#include "IPhysicsProp.h"

class CPhysicsPropRespawnable;

class IPhysicsPropRespawnable : public virtual IPhysicsProp
{
public:
    virtual ~IPhysicsPropRespawnable() = default;
    CPhysicsPropRespawnable* GetOriginal() { return reinterpret_cast<CPhysicsPropRespawnable*>(IEntityInstance::GetOriginal()); }

    virtual Vector& OriginalSpawnOrigin() = 0;
    virtual void OriginalSpawnOriginUpdated() = 0;
    virtual QAngle& OriginalSpawnAngles() = 0;
    virtual void OriginalSpawnAnglesUpdated() = 0;
    virtual Vector& OriginalMins() = 0;
    virtual void OriginalMinsUpdated() = 0;
    virtual Vector& OriginalMaxs() = 0;
    virtual void OriginalMaxsUpdated() = 0;
    virtual float& RespawnDuration() = 0;
    virtual void RespawnDurationUpdated() = 0;
    static IPhysicsPropRespawnable* FromOriginal(CPhysicsPropRespawnable* p);
};

#endif // _INCLUDE_IPHYSICSPROPRESPAWNABLE_H
