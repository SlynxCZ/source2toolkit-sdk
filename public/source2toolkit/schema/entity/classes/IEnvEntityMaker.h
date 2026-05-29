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

#ifndef _INCLUDE_IENVENTITYMAKER_H
#define _INCLUDE_IENVENTITYMAKER_H

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

#include "IPointEntity.h"

class CBaseEntity;
class CEnvEntityMaker;

class IEnvEntityMaker : public virtual IPointEntity
{
public:
    virtual ~IEnvEntityMaker() = default;
    CEnvEntityMaker* GetOriginal() { return reinterpret_cast<CEnvEntityMaker*>(IEntityInstance::GetOriginal()); }

    virtual Vector& EntityMins() = 0;
    virtual void EntityMinsUpdated() = 0;
    virtual Vector& EntityMaxs() = 0;
    virtual void EntityMaxsUpdated() = 0;
    virtual CHandle<CBaseEntity>& CurrentInstance() = 0;
    virtual void CurrentInstanceUpdated() = 0;
    virtual CHandle<CBaseEntity>& CurrentBlocker() = 0;
    virtual void CurrentBlockerUpdated() = 0;
    virtual Vector& BlockerOrigin() = 0;
    virtual void BlockerOriginUpdated() = 0;
    virtual QAngle& PostSpawnDirection() = 0;
    virtual void PostSpawnDirectionUpdated() = 0;
    virtual float& PostSpawnDirectionVariance() = 0;
    virtual void PostSpawnDirectionVarianceUpdated() = 0;
    virtual float& PostSpawnSpeed() = 0;
    virtual void PostSpawnSpeedUpdated() = 0;
    virtual bool& PostSpawnUseAngles() = 0;
    virtual void PostSpawnUseAnglesUpdated() = 0;
    virtual CUtlSymbolLarge& Template() = 0;
    virtual void TemplateUpdated() = 0;
    virtual ::CEntityIOOutput& OutputOnSpawned() = 0;
    virtual void OutputOnSpawnedUpdated() = 0;
    virtual ::CEntityIOOutput& OutputOnFailedSpawn() = 0;
    virtual void OutputOnFailedSpawnUpdated() = 0;
    static IEnvEntityMaker* FromOriginal(CEnvEntityMaker* p);
};

#endif // _INCLUDE_IENVENTITYMAKER_H
