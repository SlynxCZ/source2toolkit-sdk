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

#ifndef _INCLUDE_IENVEXPLOSION_H
#define _INCLUDE_IENVEXPLOSION_H

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

#include "IModelPointEntity.h"

#include "../enums/Class_T.h"
#include "../enums/DamageTypes_t.h"

class CBaseEntity;
class CEnvExplosion;

class IEnvExplosion : public virtual IModelPointEntity
{
public:
    virtual ~IEnvExplosion() = default;
    CEnvExplosion* GetOriginal() { return reinterpret_cast<CEnvExplosion*>(IEntityInstance::GetOriginal()); }

    virtual int32_t& Magnitude() = 0;
    virtual void MagnitudeUpdated() = 0;
    virtual float& PlayerDamage() = 0;
    virtual void PlayerDamageUpdated() = 0;
    virtual int32_t& RadiusOverride() = 0;
    virtual void RadiusOverrideUpdated() = 0;
    virtual float& InnerRadius() = 0;
    virtual void InnerRadiusUpdated() = 0;
    virtual float& DamageForce() = 0;
    virtual void DamageForceUpdated() = 0;
    virtual CHandle<CBaseEntity>& Inflictor() = 0;
    virtual void InflictorUpdated() = 0;
    virtual ::DamageTypes_t& CustomDamageType() = 0;
    virtual void CustomDamageTypeUpdated() = 0;
    virtual bool& CreateDebris() = 0;
    virtual void CreateDebrisUpdated() = 0;
    virtual CUtlSymbolLarge& CustomEffectName() = 0;
    virtual void CustomEffectNameUpdated() = 0;
    virtual CUtlSymbolLarge& CustomSoundName() = 0;
    virtual void CustomSoundNameUpdated() = 0;
    virtual bool& SuppressParticleImpulse() = 0;
    virtual void SuppressParticleImpulseUpdated() = 0;
    virtual ::Class_T& ClassIgnore() = 0;
    virtual void ClassIgnoreUpdated() = 0;
    virtual ::Class_T& ClassIgnore2() = 0;
    virtual void ClassIgnore2Updated() = 0;
    virtual CUtlSymbolLarge& EntityIgnoreName() = 0;
    virtual void EntityIgnoreNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& EntityIgnore() = 0;
    virtual void EntityIgnoreUpdated() = 0;
    static IEnvExplosion* FromOriginal(CEnvExplosion* p);
};

#endif // _INCLUDE_IENVEXPLOSION_H
