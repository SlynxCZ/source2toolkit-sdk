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

#ifndef _INCLUDE_IPOINTORIENT_H
#define _INCLUDE_IPOINTORIENT_H

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

#include "IBaseEntity.h"

#include "../enums/PointOrientConstraint_t.h"
#include "../enums/PointOrientGoalDirectionType_t.h"

class CBaseEntity;

class IPointOrient : public virtual IBaseEntity
{
public:
    virtual ~IPointOrient() = default;

    virtual CUtlSymbolLarge& SpawnTargetName() = 0;
    virtual void SpawnTargetNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& Target() = 0;
    virtual void TargetUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual PointOrientGoalDirectionType_t& GoalDirection() = 0;
    virtual void GoalDirectionUpdated() = 0;
    virtual PointOrientConstraint_t& Constraint() = 0;
    virtual void ConstraintUpdated() = 0;
    virtual float& MaxTurnRate() = 0;
    virtual void MaxTurnRateUpdated() = 0;
    virtual float& LastGameTime() = 0;
    virtual void LastGameTimeUpdated() = 0;
};

#endif // _INCLUDE_IPOINTORIENT_H
