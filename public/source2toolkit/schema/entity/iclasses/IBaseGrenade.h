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

#ifndef _INCLUDE_IBASEGRENADE_H
#define _INCLUDE_IBASEGRENADE_H

#pragma once

#include <cstdint>

#include "IBaseAnimGraph.h"

class CCSPlayerPawn;

class IBaseGrenade : public virtual IBaseAnimGraph
{
public:
    virtual ~IBaseGrenade() = default;

    virtual CEntityIOOutput& OnPlayerPickup() = 0;
    virtual void OnPlayerPickupUpdated() = 0;
    virtual CEntityIOOutput& OnExplode() = 0;
    virtual void OnExplodeUpdated() = 0;
    virtual bool& HasWarnedAI() = 0;
    virtual void HasWarnedAIUpdated() = 0;
    virtual bool& IsSmokeGrenade() = 0;
    virtual void IsSmokeGrenadeUpdated() = 0;
    virtual bool& IsLive() = 0;
    virtual void IsLiveUpdated() = 0;
    virtual float& DmgRadius() = 0;
    virtual void DmgRadiusUpdated() = 0;
    virtual float& DetonateTime() = 0;
    virtual void DetonateTimeUpdated() = 0;
    virtual float& WarnAITime() = 0;
    virtual void WarnAITimeUpdated() = 0;
    virtual float& Damage() = 0;
    virtual void DamageUpdated() = 0;
    virtual CUtlSymbolLarge& BounceSound() = 0;
    virtual void BounceSoundUpdated() = 0;
    virtual CUtlString& ExplosionSound() = 0;
    virtual void ExplosionSoundUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& Thrower() = 0;
    virtual void ThrowerUpdated() = 0;
    virtual float& NextAttack() = 0;
    virtual void NextAttackUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& OriginalThrower() = 0;
    virtual void OriginalThrowerUpdated() = 0;
};

#endif // _INCLUDE_IBASEGRENADE_H
