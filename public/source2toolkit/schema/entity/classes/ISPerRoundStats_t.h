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

#ifndef _INCLUDE_ISPERROUNDSTATS_T_H
#define _INCLUDE_ISPERROUNDSTATS_T_H

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

class CSPerRoundStats_t;

class ISPerRoundStats_t
{
public:
    virtual ~ISPerRoundStats_t() = default;
    CSPerRoundStats_t* GetOriginal() { return reinterpret_cast<CSPerRoundStats_t*>(IEntityInstance::GetOriginal()); }

    virtual int32_t& Kills() = 0;
    virtual void KillsUpdated() = 0;
    virtual int32_t& Deaths() = 0;
    virtual void DeathsUpdated() = 0;
    virtual int32_t& Assists() = 0;
    virtual void AssistsUpdated() = 0;
    virtual int32_t& Damage() = 0;
    virtual void DamageUpdated() = 0;
    virtual int32_t& EquipmentValue() = 0;
    virtual void EquipmentValueUpdated() = 0;
    virtual int32_t& MoneySaved() = 0;
    virtual void MoneySavedUpdated() = 0;
    virtual int32_t& KillReward() = 0;
    virtual void KillRewardUpdated() = 0;
    virtual int32_t& LiveTime() = 0;
    virtual void LiveTimeUpdated() = 0;
    virtual int32_t& HeadShotKills() = 0;
    virtual void HeadShotKillsUpdated() = 0;
    virtual int32_t& Objective() = 0;
    virtual void ObjectiveUpdated() = 0;
    virtual int32_t& CashEarned() = 0;
    virtual void CashEarnedUpdated() = 0;
    virtual int32_t& UtilityDamage() = 0;
    virtual void UtilityDamageUpdated() = 0;
    virtual int32_t& EnemiesFlashed() = 0;
    virtual void EnemiesFlashedUpdated() = 0;
    static ISPerRoundStats_t* FromOriginal(CSPerRoundStats_t* p);
};

#endif // _INCLUDE_ISPERROUNDSTATS_T_H
