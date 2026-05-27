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

#ifndef _INCLUDE_IBASEPLAYERVDATA_H
#define _INCLUDE_IBASEPLAYERVDATA_H

#pragma once

#include <cstdint>

#include "IEntitySubclassVDataBase.h"

#include "CSkillFloat.h"

class IBasePlayerVData : public virtual IEntitySubclassVDataBase
{
public:
    virtual ~IBasePlayerVData() = default;

    virtual CSkillFloat& HeadDamageMultiplier() = 0;
    virtual void HeadDamageMultiplierUpdated() = 0;
    virtual CSkillFloat& ChestDamageMultiplier() = 0;
    virtual void ChestDamageMultiplierUpdated() = 0;
    virtual CSkillFloat& StomachDamageMultiplier() = 0;
    virtual void StomachDamageMultiplierUpdated() = 0;
    virtual CSkillFloat& ArmDamageMultiplier() = 0;
    virtual void ArmDamageMultiplierUpdated() = 0;
    virtual CSkillFloat& LegDamageMultiplier() = 0;
    virtual void LegDamageMultiplierUpdated() = 0;
    virtual float& HoldBreathTime() = 0;
    virtual void HoldBreathTimeUpdated() = 0;
    virtual float& DrowningDamageInterval() = 0;
    virtual void DrowningDamageIntervalUpdated() = 0;
    virtual int32_t& DrowningDamageInitial() = 0;
    virtual void DrowningDamageInitialUpdated() = 0;
    virtual int32_t& DrowningDamageMax() = 0;
    virtual void DrowningDamageMaxUpdated() = 0;
    virtual int32_t& WaterSpeed() = 0;
    virtual void WaterSpeedUpdated() = 0;
    virtual float& UseRange() = 0;
    virtual void UseRangeUpdated() = 0;
    virtual float& UseAngleTolerance() = 0;
    virtual void UseAngleToleranceUpdated() = 0;
    virtual float& CrouchTime() = 0;
    virtual void CrouchTimeUpdated() = 0;
};

#endif // _INCLUDE_IBASEPLAYERVDATA_H
