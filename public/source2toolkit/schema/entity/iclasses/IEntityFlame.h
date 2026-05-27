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

#ifndef _INCLUDE_IENTITYFLAME_H
#define _INCLUDE_IENTITYFLAME_H

#pragma once

#include <cstdint>

#include "IBaseEntity.h"

class CBaseEntity;

class IEntityFlame : public virtual IBaseEntity
{
public:
    virtual ~IEntityFlame() = default;

    virtual CHandle<CBaseEntity>& EntAttached() = 0;
    virtual void EntAttachedUpdated() = 0;
    virtual bool& CheapEffect() = 0;
    virtual void CheapEffectUpdated() = 0;
    virtual float& Size() = 0;
    virtual void SizeUpdated() = 0;
    virtual bool& UseHitboxes() = 0;
    virtual void UseHitboxesUpdated() = 0;
    virtual int32_t& NumHitboxFires() = 0;
    virtual void NumHitboxFiresUpdated() = 0;
    virtual float& HitboxFireScale() = 0;
    virtual void HitboxFireScaleUpdated() = 0;
    virtual float& Lifetime() = 0;
    virtual void LifetimeUpdated() = 0;
    virtual CHandle<CBaseEntity>& Attacker() = 0;
    virtual void AttackerUpdated() = 0;
    virtual float& DirectDamagePerSecond() = 0;
    virtual void DirectDamagePerSecondUpdated() = 0;
    virtual int32_t& CustomDamageType() = 0;
    virtual void CustomDamageTypeUpdated() = 0;
};

#endif // _INCLUDE_IENTITYFLAME_H
