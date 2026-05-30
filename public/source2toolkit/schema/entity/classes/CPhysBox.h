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

#ifndef _INCLUDE_CPHYSBOX_H
#define _INCLUDE_CPHYSBOX_H

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

#include "CBreakable.h"
#include "../enums/HoverPoseFlags_t.h"

class CBasePlayerPawn;

class CPhysBox : public CBreakable
{
public:
    DECLARE_SCHEMA_CLASS(CPhysBox);

    SCHEMA_FIELD(int32_t, m_damageType);
    SCHEMA_FIELD(int32_t, m_damageToEnableMotion);
    SCHEMA_FIELD(float, m_flForceToEnableMotion);
    SCHEMA_FIELD(Vector, m_vHoverPosePosition);
    SCHEMA_FIELD(QAngle, m_angHoverPoseAngles);
    SCHEMA_FIELD(bool, m_bNotSolidToWorld);
    SCHEMA_FIELD(bool, m_bEnableUseOutput);
    SCHEMA_FIELD(HoverPoseFlags_t, m_nHoverPoseFlags);
    SCHEMA_FIELD(float, m_flTouchOutputPerEntityDelay);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDamaged);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAwakened);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMotionEnabled);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerUse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartTouch);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hCarryingPlayer);

public:
    static CPhysBox* New(const char* className)
    {
        return CBaseEntity::New<CPhysBox>(className);
    }

    static CPhysBox* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysBox>(iIndex);
    }

    static CPhysBox* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};

#endif // _INCLUDE_CPHYSBOX_H
