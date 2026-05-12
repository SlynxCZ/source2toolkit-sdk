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

#ifndef _INCLUDE_CECONITEMVIEW_H
#define _INCLUDE_CECONITEMVIEW_H

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

#include "CAttributeList.h"
#include "IEconItemInterface.h"

class CEconItemView : public IEconItemInterface
{
public:
    DECLARE_SCHEMA_CLASS(CEconItemView);

    SCHEMA_FIELD(uint16_t, m_iItemDefinitionIndex);
    SCHEMA_FIELD(int32_t, m_iEntityQuality);
    SCHEMA_FIELD(uint32_t, m_iEntityLevel);
    SCHEMA_FIELD(uint64_t, m_iItemID);
    SCHEMA_FIELD(uint32_t, m_iItemIDHigh);
    SCHEMA_FIELD(uint32_t, m_iItemIDLow);
    SCHEMA_FIELD(uint32_t, m_iAccountID);
    SCHEMA_FIELD(uint32_t, m_iInventoryPosition);
    SCHEMA_FIELD(bool, m_bInitialized);
    SCHEMA_FIELD(CAttributeList, m_AttributeList);
    SCHEMA_FIELD(CAttributeList, m_NetworkedDynamicAttributes);
    SCHEMA_FIELD_POINTER(char, m_szCustomName);
    SCHEMA_FIELD_POINTER(char, m_szCustomNameOverride);
};

#endif // _INCLUDE_CECONITEMVIEW_H
