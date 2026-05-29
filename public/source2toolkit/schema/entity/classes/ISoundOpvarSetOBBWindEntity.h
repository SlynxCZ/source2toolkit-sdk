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

#ifndef _INCLUDE_ISOUNDOPVARSETOBBWINDENTITY_H
#define _INCLUDE_ISOUNDOPVARSETOBBWINDENTITY_H

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

#include "ISoundOpvarSetPointBase.h"

class CSoundOpvarSetOBBWindEntity;

class ISoundOpvarSetOBBWindEntity : public virtual ISoundOpvarSetPointBase
{
public:
    virtual ~ISoundOpvarSetOBBWindEntity() = default;

    virtual Vector& Mins() = 0;
    virtual void MinsUpdated() = 0;
    virtual Vector& Maxs() = 0;
    virtual void MaxsUpdated() = 0;
    virtual Vector& DistanceMins() = 0;
    virtual void DistanceMinsUpdated() = 0;
    virtual Vector& DistanceMaxs() = 0;
    virtual void DistanceMaxsUpdated() = 0;
    virtual float& WindMin() = 0;
    virtual void WindMinUpdated() = 0;
    virtual float& WindMax() = 0;
    virtual void WindMaxUpdated() = 0;
    virtual float& WindMapMin() = 0;
    virtual void WindMapMinUpdated() = 0;
    virtual float& WindMapMax() = 0;
    virtual void WindMapMaxUpdated() = 0;
    static ISoundOpvarSetOBBWindEntity* FromOriginal(CSoundOpvarSetOBBWindEntity* p);
};

#endif // _INCLUDE_ISOUNDOPVARSETOBBWINDENTITY_H
