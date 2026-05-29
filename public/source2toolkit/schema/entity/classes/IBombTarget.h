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

#ifndef _INCLUDE_IBOMBTARGET_H
#define _INCLUDE_IBOMBTARGET_H

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

#include "IBaseTrigger.h"

class CBaseEntity;
class CBombTarget;

class IBombTarget : public virtual IBaseTrigger
{
public:
    virtual ~IBombTarget() = default;

    virtual ::CEntityIOOutput& OnBombExplode() = 0;
    virtual void OnBombExplodeUpdated() = 0;
    virtual ::CEntityIOOutput& OnBombPlanted() = 0;
    virtual void OnBombPlantedUpdated() = 0;
    virtual ::CEntityIOOutput& OnBombDefused() = 0;
    virtual void OnBombDefusedUpdated() = 0;
    virtual bool& IsBombSiteB() = 0;
    virtual void IsBombSiteBUpdated() = 0;
    virtual bool& IsHeistBombTarget() = 0;
    virtual void IsHeistBombTargetUpdated() = 0;
    virtual bool& BombPlantedHere() = 0;
    virtual void BombPlantedHereUpdated() = 0;
    virtual CUtlSymbolLarge& MountTarget() = 0;
    virtual void MountTargetUpdated() = 0;
    virtual CHandle<CBaseEntity>& InstructorHint() = 0;
    virtual void InstructorHintUpdated() = 0;
    virtual int32_t& BombSiteDesignation() = 0;
    virtual void BombSiteDesignationUpdated() = 0;
    static IBombTarget* FromOriginal(CBombTarget* p);
};

#endif // _INCLUDE_IBOMBTARGET_H
