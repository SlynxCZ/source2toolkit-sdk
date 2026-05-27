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

#ifndef _INCLUDE_IBASEPLAYERWEAPONVDATA_H
#define _INCLUDE_IBASEPLAYERWEAPONVDATA_H

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
#include <cstdint>

#include "IEntitySubclassVDataBase.h"

#include "../enums/ItemFlagTypes_t.h"
#include "../enums/RumbleEffect_t.h"

class IBasePlayerWeaponVData : public virtual IEntitySubclassVDataBase
{
public:
    virtual ~IBasePlayerWeaponVData() = default;

    virtual bool& BuiltRightHanded() = 0;
    virtual void BuiltRightHandedUpdated() = 0;
    virtual bool& AllowFlipping() = 0;
    virtual void AllowFlippingUpdated() = 0;
    virtual CUtlString& MuzzleFlashParticleConfig() = 0;
    virtual void MuzzleFlashParticleConfigUpdated() = 0;
    virtual uint8_t& MuzzleSmokeShotThreshold() = 0;
    virtual void MuzzleSmokeShotThresholdUpdated() = 0;
    virtual float& MuzzleSmokeTimeout() = 0;
    virtual void MuzzleSmokeTimeoutUpdated() = 0;
    virtual float& MuzzleSmokeDecrementRate() = 0;
    virtual void MuzzleSmokeDecrementRateUpdated() = 0;
    virtual bool& GenerateMuzzleLight() = 0;
    virtual void GenerateMuzzleLightUpdated() = 0;
    virtual bool& LinkedCooldowns() = 0;
    virtual void LinkedCooldownsUpdated() = 0;
    virtual ItemFlagTypes_t& Flags() = 0;
    virtual void FlagsUpdated() = 0;
    virtual int32_t& Weight() = 0;
    virtual void WeightUpdated() = 0;
    virtual bool& AutoSwitchTo() = 0;
    virtual void AutoSwitchToUpdated() = 0;
    virtual bool& AutoSwitchFrom() = 0;
    virtual void AutoSwitchFromUpdated() = 0;
    virtual uint8_t& PrimaryAmmoType() = 0;
    virtual void PrimaryAmmoTypeUpdated() = 0;
    virtual uint8_t& SecondaryAmmoType() = 0;
    virtual void SecondaryAmmoTypeUpdated() = 0;
    virtual int32_t& MaxClip1() = 0;
    virtual void MaxClip1Updated() = 0;
    virtual int32_t& MaxClip2() = 0;
    virtual void MaxClip2Updated() = 0;
    virtual int32_t& DefaultClip1() = 0;
    virtual void DefaultClip1Updated() = 0;
    virtual int32_t& DefaultClip2() = 0;
    virtual void DefaultClip2Updated() = 0;
    virtual bool& ReserveAmmoAsClips() = 0;
    virtual void ReserveAmmoAsClipsUpdated() = 0;
    virtual bool& TreatAsSingleClip() = 0;
    virtual void TreatAsSingleClipUpdated() = 0;
    virtual bool& KeepLoadedAmmo() = 0;
    virtual void KeepLoadedAmmoUpdated() = 0;
    virtual RumbleEffect_t& RumbleEffect() = 0;
    virtual void RumbleEffectUpdated() = 0;
    virtual float& DropSpeed() = 0;
    virtual void DropSpeedUpdated() = 0;
    virtual int32_t& Slot() = 0;
    virtual void SlotUpdated() = 0;
    virtual int32_t& Position() = 0;
    virtual void PositionUpdated() = 0;
};

#endif // _INCLUDE_IBASEPLAYERWEAPONVDATA_H
