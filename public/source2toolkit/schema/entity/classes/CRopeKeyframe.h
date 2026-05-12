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

#ifndef _INCLUDE_CROPEKEYFRAME_H
#define _INCLUDE_CROPEKEYFRAME_H

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

#include "CBaseModelEntity.h"
#include "InfoForResourceTypeIMaterial2.h"

class CBaseEntity;

class CRopeKeyframe : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRopeKeyframe);

    SCHEMA_FIELD(uint16_t, m_RopeFlags);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iNextLinkName);
    SCHEMA_FIELD(int16_t, m_Slack);
    SCHEMA_FIELD(float, m_Width);
    SCHEMA_FIELD(float, m_TextureScale);
    SCHEMA_FIELD(uint8_t, m_nSegments);
    SCHEMA_FIELD(bool, m_bConstrainBetweenEndpoints);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strRopeMaterialModel);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_iRopeMaterialModelIndex);
    SCHEMA_FIELD(uint8_t, m_Subdiv);
    SCHEMA_FIELD(uint8_t, m_nChangeCount);
    SCHEMA_FIELD(int16_t, m_RopeLength);
    SCHEMA_FIELD(uint8_t, m_fLockedPoints);
    SCHEMA_FIELD(bool, m_bCreatedFromMapFile);
    SCHEMA_FIELD(float, m_flScrollSpeed);
    SCHEMA_FIELD(bool, m_bStartPointValid);
    SCHEMA_FIELD(bool, m_bEndPointValid);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hStartPoint);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEndPoint);

public:
    static CRopeKeyframe* New(const char* className)
    {
        return CBaseEntity::New<CRopeKeyframe>(className);
    }

    static CRopeKeyframe* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRopeKeyframe>(iIndex);
    }

    static CRopeKeyframe* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};

#endif // _INCLUDE_CROPEKEYFRAME_H
