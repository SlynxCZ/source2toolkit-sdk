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

#ifndef _INCLUDE_IBASECSGRENADEPROJECTILE_H
#define _INCLUDE_IBASECSGRENADEPROJECTILE_H

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

#include "IBaseGrenade.h"

class CBaseCSGrenadeProjectile;
class InfoForResourceTypeIParticleSystemDefinition;

class IBaseCSGrenadeProjectile : public virtual IBaseGrenade
{
public:
    virtual ~IBaseCSGrenadeProjectile() = default;
    CBaseCSGrenadeProjectile* GetOriginal() { return reinterpret_cast<CBaseCSGrenadeProjectile*>(IEntityInstance::GetOriginal()); }

    virtual Vector& InitialPosition() = 0;
    virtual void InitialPositionUpdated() = 0;
    virtual Vector& InitialVelocity() = 0;
    virtual void InitialVelocityUpdated() = 0;
    virtual int32_t& Bounces() = 0;
    virtual void BouncesUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>& ExplodeEffectIndex() = 0;
    virtual void ExplodeEffectIndexUpdated() = 0;
    virtual int32_t& ExplodeEffectTickBegin() = 0;
    virtual void ExplodeEffectTickBeginUpdated() = 0;
    virtual Vector& ExplodeEffectOrigin() = 0;
    virtual void ExplodeEffectOriginUpdated() = 0;
    virtual float& SpawnTime() = 0;
    virtual void SpawnTimeUpdated() = 0;
    virtual uint8_t& OGSExtraFlags() = 0;
    virtual void OGSExtraFlagsUpdated() = 0;
    virtual bool& DetonationRecorded() = 0;
    virtual void DetonationRecordedUpdated() = 0;
    virtual uint16_t& ItemIndex() = 0;
    virtual void ItemIndexUpdated() = 0;
    virtual Vector& OriginalSpawnLocation() = 0;
    virtual void OriginalSpawnLocationUpdated() = 0;
    virtual float& LastBounceSoundTime() = 0;
    virtual void LastBounceSoundTimeUpdated() = 0;
    virtual RotationVector& GrenadeSpin() = 0;
    virtual void GrenadeSpinUpdated() = 0;
    virtual Vector& LastHitSurfaceNormal() = 0;
    virtual void LastHitSurfaceNormalUpdated() = 0;
    virtual int32_t& TicksAtZeroVelocity() = 0;
    virtual void TicksAtZeroVelocityUpdated() = 0;
    virtual bool& HasEverHitEnemy() = 0;
    virtual void HasEverHitEnemyUpdated() = 0;
    static IBaseCSGrenadeProjectile* FromOriginal(CBaseCSGrenadeProjectile* p);
};

#endif // _INCLUDE_IBASECSGRENADEPROJECTILE_H
