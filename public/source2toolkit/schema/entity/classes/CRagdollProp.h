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

#ifndef _INCLUDE_CRAGDOLLPROP_H
#define _INCLUDE_CRAGDOLLPROP_H

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

#include "CBaseAnimGraph.h"
#include "ragdoll_t.h"

class CBaseEntity;
class CBasePlayerPawn;

class CRagdollProp : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollProp);

    SCHEMA_FIELD(ragdoll_t, m_ragdoll);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(CUtlVector<bool>, m_ragEnabled);
    SCHEMA_FIELD(CUtlVector<Vector>, m_ragPos);
    SCHEMA_FIELD(CUtlVector<QAngle>, m_ragAngles);
    SCHEMA_FIELD(uint32_t, m_lastUpdateTickCount);
    SCHEMA_FIELD(bool, m_allAsleep);
    SCHEMA_FIELD(bool, m_bFirstCollisionAfterLaunch);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hDamageEntity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hKiller);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hPhysicsAttacker);
    SCHEMA_FIELD(float, m_flLastPhysicsInfluenceTime);
    SCHEMA_FIELD(float, m_flFadeOutStartTime);
    SCHEMA_FIELD(float, m_flFadeTime);
    SCHEMA_FIELD(Vector, m_vecLastOrigin);
    SCHEMA_FIELD(float, m_flAwakeTime);
    SCHEMA_FIELD(float, m_flLastOriginChangeTime);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strOriginClassName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strSourceClassName);
    SCHEMA_FIELD(bool, m_bHasBeenPhysgunned);
    SCHEMA_FIELD(bool, m_bAllowStretch);
    SCHEMA_FIELD(float, m_flBlendWeight);
    SCHEMA_FIELD(float, m_flDefaultFadeScale);
    SCHEMA_FIELD(CUtlVector<Vector>, m_ragdollMins);
    SCHEMA_FIELD(CUtlVector<Vector>, m_ragdollMaxs);
    SCHEMA_FIELD(bool, m_bShouldDeleteActivationRecord);

public:
    static CRagdollProp* New(const char* className)
    {
        return CBaseEntity::New<CRagdollProp>(className);
    }

    static CRagdollProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollProp>(iIndex);
    }

    static CRagdollProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};

#endif // _INCLUDE_CRAGDOLLPROP_H
