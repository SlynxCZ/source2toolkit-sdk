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

#ifndef _INCLUDE_IC4_H
#define _INCLUDE_IC4_H

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

#include "ICSWeaponBase.h"

class EntitySpottedState_t;

class IC4 : public virtual ICSWeaponBase
{
public:
    virtual ~IC4() = default;

    virtual Vector& LastValidPlayerHeldPosition() = 0;
    virtual void LastValidPlayerHeldPositionUpdated() = 0;
    virtual Vector& LastValidDroppedPosition() = 0;
    virtual void LastValidDroppedPositionUpdated() = 0;
    virtual bool& DoValidDroppedPositionCheck() = 0;
    virtual void DoValidDroppedPositionCheckUpdated() = 0;
    virtual bool& StartedArming() = 0;
    virtual void StartedArmingUpdated() = 0;
    virtual float& ArmedTime() = 0;
    virtual void ArmedTimeUpdated() = 0;
    virtual bool& BombPlacedAnimation() = 0;
    virtual void BombPlacedAnimationUpdated() = 0;
    virtual bool& IsPlantingViaUse() = 0;
    virtual void IsPlantingViaUseUpdated() = 0;
    virtual EntitySpottedState_t& EntitySpottedState() = 0;
    virtual void EntitySpottedStateUpdated() = 0;
    virtual int32_t& SpotRules() = 0;
    virtual void SpotRulesUpdated() = 0;
    virtual bool* PlayedArmingBeeps() = 0;
    virtual bool& BombPlanted() = 0;
    virtual void BombPlantedUpdated() = 0;
};

#endif // _INCLUDE_IC4_H
