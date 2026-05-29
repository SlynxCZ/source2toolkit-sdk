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

#ifndef _INCLUDE_IBREAKABLE_H
#define _INCLUDE_IBREAKABLE_H

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

#include "IBaseModelEntity.h"

#include "../enums/EOverrideBlockLOS_t.h"
#include "../enums/Explosions.h"
#include "../enums/Materials.h"
#include "../enums/PerformanceMode_t.h"

class CBaseEntity;
class CBasePlayerPawn;
class CBreakable;
class CPropDataComponent;

class IBreakable : public virtual IBaseModelEntity
{
public:
    virtual ~IBreakable() = default;
    CBreakable* GetOriginal() { return reinterpret_cast<CBreakable*>(IEntityInstance::GetOriginal()); }

    virtual ::CPropDataComponent& PropDataComponent() = 0;
    virtual void PropDataComponentUpdated() = 0;
    virtual ::Materials& Material() = 0;
    virtual void MaterialUpdated() = 0;
    virtual CHandle<CBaseEntity>& Breaker() = 0;
    virtual void BreakerUpdated() = 0;
    virtual ::Explosions& Explosion() = 0;
    virtual void ExplosionUpdated() = 0;
    virtual CUtlSymbolLarge& SpawnObject() = 0;
    virtual void SpawnObjectUpdated() = 0;
    virtual float& PressureDelay() = 0;
    virtual void PressureDelayUpdated() = 0;
    virtual int32_t& MinHealthDmg() = 0;
    virtual void MinHealthDmgUpdated() = 0;
    virtual CUtlSymbolLarge& PropData() = 0;
    virtual void PropDataUpdated() = 0;
    virtual float& ImpactEnergyScale() = 0;
    virtual void ImpactEnergyScaleUpdated() = 0;
    virtual ::EOverrideBlockLOS_t& OverrideBlockLOS() = 0;
    virtual void OverrideBlockLOSUpdated() = 0;
    virtual ::CEntityIOOutput& OnStartDeath() = 0;
    virtual void OnStartDeathUpdated() = 0;
    virtual ::CEntityIOOutput& OnBreak() = 0;
    virtual void OnBreakUpdated() = 0;
    virtual ::PerformanceMode_t& PerformanceMode() = 0;
    virtual void PerformanceModeUpdated() = 0;
    virtual CHandle<CBasePlayerPawn>& PhysicsAttacker() = 0;
    virtual void PhysicsAttackerUpdated() = 0;
    virtual float& LastPhysicsInfluenceTime() = 0;
    virtual void LastPhysicsInfluenceTimeUpdated() = 0;
    static IBreakable* FromOriginal(CBreakable* p);
};

#endif // _INCLUDE_IBREAKABLE_H
