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

#ifndef _INCLUDE_IBASEPLAYERWEAPON_H
#define _INCLUDE_IBASEPLAYERWEAPON_H

#pragma once

#include <cstdint>

#include "IEconEntity.h"

class IBasePlayerWeapon : public virtual IEconEntity
{
public:
    virtual ~IBasePlayerWeapon() = default;

    virtual int32_t& NextPrimaryAttackTick() = 0;
    virtual void NextPrimaryAttackTickUpdated() = 0;
    virtual float& NextPrimaryAttackTickRatio() = 0;
    virtual void NextPrimaryAttackTickRatioUpdated() = 0;
    virtual int32_t& NextSecondaryAttackTick() = 0;
    virtual void NextSecondaryAttackTickUpdated() = 0;
    virtual float& NextSecondaryAttackTickRatio() = 0;
    virtual void NextSecondaryAttackTickRatioUpdated() = 0;
    virtual int32_t& Clip1() = 0;
    virtual void Clip1Updated() = 0;
    virtual int32_t& Clip2() = 0;
    virtual void Clip2Updated() = 0;
    virtual int32_t* ReserveAmmo() = 0;
    virtual CEntityIOOutput& OnPlayerUse() = 0;
    virtual void OnPlayerUseUpdated() = 0;
};

#endif // _INCLUDE_IBASEPLAYERWEAPON_H
