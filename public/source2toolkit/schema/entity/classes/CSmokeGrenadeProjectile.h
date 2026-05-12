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

#ifndef _INCLUDE_CSMOKEGRENADEPROJECTILE_H
#define _INCLUDE_CSMOKEGRENADEPROJECTILE_H

#pragma once

#include "CBaseEntity.h"
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

#include "CBaseCSGrenadeProjectile.h"

class CSmokeGrenadeProjectile : public CBaseCSGrenadeProjectile
{
public:
    DECLARE_SCHEMA_CLASS(CSmokeGrenadeProjectile);

    SCHEMA_FIELD(int32_t, m_nSmokeEffectTickBegin);
    SCHEMA_FIELD(bool, m_bDidSmokeEffect);
    SCHEMA_FIELD(int32_t, m_nRandomSeed);
    SCHEMA_FIELD(Vector, m_vSmokeColor);
    SCHEMA_FIELD(Vector, m_vSmokeDetonationPos);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_VoxelFrameData);
    SCHEMA_FIELD(int32_t, m_nVoxelFrameDataSize);
    SCHEMA_FIELD(int32_t, m_nVoxelUpdate);
    SCHEMA_FIELD(float, m_flLastBounce);
    SCHEMA_FIELD(float, m_fllastSimulationTime);
    SCHEMA_FIELD(bool, m_bExplodeFromInferno);
    SCHEMA_FIELD(bool, m_bDidGroundScorch);

public:
    static CSmokeGrenadeProjectile* New(const char* className)
    {
        return CBaseEntity::New<CSmokeGrenadeProjectile>(className);
    }

    static CSmokeGrenadeProjectile* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSmokeGrenadeProjectile>(iIndex);
    }

    static CSmokeGrenadeProjectile* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};

#endif // _INCLUDE_CSMOKEGRENADEPROJECTILE_H
