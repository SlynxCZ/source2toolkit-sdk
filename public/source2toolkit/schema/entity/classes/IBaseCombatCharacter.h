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

#ifndef _INCLUDE_IBASECOMBATCHARACTER_H
#define _INCLUDE_IBASECOMBATCHARACTER_H

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

#include "IBaseAnimGraph.h"

#include "../enums/Hull_t.h"

class CBaseCombatCharacter;
class CEconWearable;
class CMovementStatsProperty;
class RelationshipOverride_t;

class IBaseCombatCharacter : public virtual IBaseAnimGraph
{
public:
    virtual ~IBaseCombatCharacter() = default;

    virtual bool& ForceServerRagdoll() = 0;
    virtual void ForceServerRagdollUpdated() = 0;
    virtual CUtlVector<CHandle<CEconWearable>>& MyWearables() = 0;
    virtual void MyWearablesUpdated() = 0;
    virtual float& ImpactEnergyScale() = 0;
    virtual void ImpactEnergyScaleUpdated() = 0;
    virtual bool& ApplyStressDamage() = 0;
    virtual void ApplyStressDamageUpdated() = 0;
    virtual bool& DeathEventsDispatched() = 0;
    virtual void DeathEventsDispatchedUpdated() = 0;
    virtual CUtlVector<RelationshipOverride_t>*& VecRelationships() = 0;
    virtual void VecRelationshipsUpdated() = 0;
    virtual CUtlSymbolLarge& StrRelationships() = 0;
    virtual void StrRelationshipsUpdated() = 0;
    virtual ::Hull_t& Hull() = 0;
    virtual void HullUpdated() = 0;
    virtual uint32_t& NavHullIdx() = 0;
    virtual void NavHullIdxUpdated() = 0;
    virtual ::CMovementStatsProperty& MovementStats() = 0;
    virtual void MovementStatsUpdated() = 0;
    static IBaseCombatCharacter* FromOriginal(CBaseCombatCharacter* p);
    static IBaseCombatCharacter* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IBASECOMBATCHARACTER_H
