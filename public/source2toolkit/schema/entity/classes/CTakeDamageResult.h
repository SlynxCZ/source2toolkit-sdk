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

#ifndef _INCLUDE_CTAKEDAMAGERESULT_H
#define _INCLUDE_CTAKEDAMAGERESULT_H

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

#include "DestructiblePartDamageRequest_t.h"
#include "../enums/TakeDamageFlags_t.h"

class CTakeDamageInfo;

class CTakeDamageResult
{
public:
    DECLARE_SCHEMA_CLASS(CTakeDamageResult);

    SCHEMA_FIELD(CTakeDamageInfo*, m_pOriginatingInfo);
    SCHEMA_FIELD(CUtlLeanVector, m_DestructibleHitGroupRequests);
    SCHEMA_FIELD(int32_t, m_nHealthLost);
    SCHEMA_FIELD(int32_t, m_nHealthBefore);
    SCHEMA_FIELD(float, m_flDamageDealt);
    SCHEMA_FIELD(float, m_flPreModifiedDamage);
    SCHEMA_FIELD(int32_t, m_nTotalledHealthLost);
    SCHEMA_FIELD(float, m_flTotalledDamageDealt);
    SCHEMA_FIELD(float, m_flTotalledPreModifiedDamage);
    SCHEMA_FIELD(float, m_flNewDamageAccumulatorValue);
    SCHEMA_FIELD(TakeDamageFlags_t, m_nDamageFlags);
    SCHEMA_FIELD(bool, m_bWasDamageSuppressed);
    SCHEMA_FIELD(bool, m_bSuppressFlinch);
    SCHEMA_FIELD(HitGroup_t, m_nOverrideFlinchHitGroup);
};

#endif // _INCLUDE_CTAKEDAMAGERESULT_H
