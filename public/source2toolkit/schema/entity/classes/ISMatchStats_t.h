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

#ifndef _INCLUDE_ISMATCHSTATS_T_H
#define _INCLUDE_ISMATCHSTATS_T_H

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

#include "ISPerRoundStats_t.h"

class CSMatchStats_t;

class ISMatchStats_t : public virtual ISPerRoundStats_t
{
public:
    virtual ~ISMatchStats_t() = default;

    virtual int32_t& Enemy5Ks() = 0;
    virtual void Enemy5KsUpdated() = 0;
    virtual int32_t& Enemy4Ks() = 0;
    virtual void Enemy4KsUpdated() = 0;
    virtual int32_t& Enemy3Ks() = 0;
    virtual void Enemy3KsUpdated() = 0;
    virtual int32_t& EnemyKnifeKills() = 0;
    virtual void EnemyKnifeKillsUpdated() = 0;
    virtual int32_t& EnemyTaserKills() = 0;
    virtual void EnemyTaserKillsUpdated() = 0;
    virtual int32_t& Enemy2Ks() = 0;
    virtual void Enemy2KsUpdated() = 0;
    virtual int32_t& Utility_Count() = 0;
    virtual void Utility_CountUpdated() = 0;
    virtual int32_t& Utility_Successes() = 0;
    virtual void Utility_SuccessesUpdated() = 0;
    virtual int32_t& Utility_Enemies() = 0;
    virtual void Utility_EnemiesUpdated() = 0;
    virtual int32_t& Flash_Count() = 0;
    virtual void Flash_CountUpdated() = 0;
    virtual int32_t& Flash_Successes() = 0;
    virtual void Flash_SuccessesUpdated() = 0;
    virtual float& HealthPointsRemovedTotal() = 0;
    virtual void HealthPointsRemovedTotalUpdated() = 0;
    virtual float& HealthPointsDealtTotal() = 0;
    virtual void HealthPointsDealtTotalUpdated() = 0;
    virtual int32_t& ShotsFiredTotal() = 0;
    virtual void ShotsFiredTotalUpdated() = 0;
    virtual int32_t& ShotsOnTargetTotal() = 0;
    virtual void ShotsOnTargetTotalUpdated() = 0;
    virtual int32_t& I1v1Count() = 0;
    virtual void I1v1CountUpdated() = 0;
    virtual int32_t& I1v1Wins() = 0;
    virtual void I1v1WinsUpdated() = 0;
    virtual int32_t& I1v2Count() = 0;
    virtual void I1v2CountUpdated() = 0;
    virtual int32_t& I1v2Wins() = 0;
    virtual void I1v2WinsUpdated() = 0;
    virtual int32_t& EntryCount() = 0;
    virtual void EntryCountUpdated() = 0;
    virtual int32_t& EntryWins() = 0;
    virtual void EntryWinsUpdated() = 0;
    static ISMatchStats_t* FromOriginal(CSMatchStats_t* p);
    static ISMatchStats_t* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_ISMATCHSTATS_T_H
