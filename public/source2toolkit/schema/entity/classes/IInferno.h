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

#ifndef _INCLUDE_IINFERNO_H
#define _INCLUDE_IINFERNO_H

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

class CInferno;
class CountdownTimer;
class Extent;
class IntervalTimer;

class IInferno : public virtual IBaseModelEntity
{
public:
    virtual ~IInferno() = default;

    virtual Vector* FirePositions() = 0;
    virtual Vector* FireParentPositions() = 0;
    virtual bool* FireIsBurning() = 0;
    virtual Vector* BurnNormal() = 0;
    virtual int32_t& FireCount() = 0;
    virtual void FireCountUpdated() = 0;
    virtual int32_t& InfernoType() = 0;
    virtual void InfernoTypeUpdated() = 0;
    virtual int32_t& FireEffectTickBegin() = 0;
    virtual void FireEffectTickBeginUpdated() = 0;
    virtual float& FireLifetime() = 0;
    virtual void FireLifetimeUpdated() = 0;
    virtual bool& InPostEffectTime() = 0;
    virtual void InPostEffectTimeUpdated() = 0;
    virtual bool& WasCreatedInSmoke() = 0;
    virtual void WasCreatedInSmokeUpdated() = 0;
    virtual ::Extent& Extent() = 0;
    virtual void ExtentUpdated() = 0;
    virtual ::CountdownTimer& DamageTimer() = 0;
    virtual void DamageTimerUpdated() = 0;
    virtual ::CountdownTimer& DamageRampTimer() = 0;
    virtual void DamageRampTimerUpdated() = 0;
    virtual Vector& SplashVelocity() = 0;
    virtual void SplashVelocityUpdated() = 0;
    virtual Vector& InitialSplashVelocity() = 0;
    virtual void InitialSplashVelocityUpdated() = 0;
    virtual Vector& StartPos() = 0;
    virtual void StartPosUpdated() = 0;
    virtual Vector& OriginalSpawnLocation() = 0;
    virtual void OriginalSpawnLocationUpdated() = 0;
    virtual ::IntervalTimer& ActiveTimer() = 0;
    virtual void ActiveTimerUpdated() = 0;
    virtual int32_t& FireSpawnOffset() = 0;
    virtual void FireSpawnOffsetUpdated() = 0;
    virtual int32_t& MaxFlames() = 0;
    virtual void MaxFlamesUpdated() = 0;
    virtual int32_t& SpreadCount() = 0;
    virtual void SpreadCountUpdated() = 0;
    virtual ::CountdownTimer& BookkeepingTimer() = 0;
    virtual void BookkeepingTimerUpdated() = 0;
    virtual ::CountdownTimer& NextSpreadTimer() = 0;
    virtual void NextSpreadTimerUpdated() = 0;
    virtual uint16_t& SourceItemDefIndex() = 0;
    virtual void SourceItemDefIndexUpdated() = 0;
    static IInferno* FromOriginal(CInferno* p);
    static IInferno* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IINFERNO_H
