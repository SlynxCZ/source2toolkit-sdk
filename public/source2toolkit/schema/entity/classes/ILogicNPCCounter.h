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

#ifndef _INCLUDE_ILOGICNPCCOUNTER_H
#define _INCLUDE_ILOGICNPCCOUNTER_H

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

#include "IBaseEntity.h"

class CLogicNPCCounter;

class ILogicNPCCounter : public virtual IBaseEntity
{
public:
    virtual ~ILogicNPCCounter() = default;

    virtual ::CEntityIOOutput& OnMinCountAll() = 0;
    virtual void OnMinCountAllUpdated() = 0;
    virtual ::CEntityIOOutput& OnMaxCountAll() = 0;
    virtual void OnMaxCountAllUpdated() = 0;
    virtual ::CEntityIOOutput& OnMinCount_1() = 0;
    virtual void OnMinCount_1Updated() = 0;
    virtual ::CEntityIOOutput& OnMaxCount_1() = 0;
    virtual void OnMaxCount_1Updated() = 0;
    virtual ::CEntityIOOutput& OnMinCount_2() = 0;
    virtual void OnMinCount_2Updated() = 0;
    virtual ::CEntityIOOutput& OnMaxCount_2() = 0;
    virtual void OnMaxCount_2Updated() = 0;
    virtual ::CEntityIOOutput& OnMinCount_3() = 0;
    virtual void OnMinCount_3Updated() = 0;
    virtual ::CEntityIOOutput& OnMaxCount_3() = 0;
    virtual void OnMaxCount_3Updated() = 0;
    virtual CEntityHandle& Source() = 0;
    virtual void SourceUpdated() = 0;
    virtual CUtlSymbolLarge& SourceEntityName() = 0;
    virtual void SourceEntityNameUpdated() = 0;
    virtual float& DistanceMax() = 0;
    virtual void DistanceMaxUpdated() = 0;
    virtual bool& Disabled() = 0;
    virtual void DisabledUpdated() = 0;
    virtual int32_t& MinCountAll() = 0;
    virtual void MinCountAllUpdated() = 0;
    virtual int32_t& MaxCountAll() = 0;
    virtual void MaxCountAllUpdated() = 0;
    virtual int32_t& MinFactorAll() = 0;
    virtual void MinFactorAllUpdated() = 0;
    virtual int32_t& MaxFactorAll() = 0;
    virtual void MaxFactorAllUpdated() = 0;
    virtual CUtlSymbolLarge& NPCClassname_1() = 0;
    virtual void NPCClassname_1Updated() = 0;
    virtual int32_t& NPCState_1() = 0;
    virtual void NPCState_1Updated() = 0;
    virtual bool& InvertState_1() = 0;
    virtual void InvertState_1Updated() = 0;
    virtual int32_t& MinCount_1() = 0;
    virtual void MinCount_1Updated() = 0;
    virtual int32_t& MaxCount_1() = 0;
    virtual void MaxCount_1Updated() = 0;
    virtual int32_t& MinFactor_1() = 0;
    virtual void MinFactor_1Updated() = 0;
    virtual int32_t& MaxFactor_1() = 0;
    virtual void MaxFactor_1Updated() = 0;
    virtual float& DefaultDist_1() = 0;
    virtual void DefaultDist_1Updated() = 0;
    virtual CUtlSymbolLarge& NPCClassname_2() = 0;
    virtual void NPCClassname_2Updated() = 0;
    virtual int32_t& NPCState_2() = 0;
    virtual void NPCState_2Updated() = 0;
    virtual bool& InvertState_2() = 0;
    virtual void InvertState_2Updated() = 0;
    virtual int32_t& MinCount_2() = 0;
    virtual void MinCount_2Updated() = 0;
    virtual int32_t& MaxCount_2() = 0;
    virtual void MaxCount_2Updated() = 0;
    virtual int32_t& MinFactor_2() = 0;
    virtual void MinFactor_2Updated() = 0;
    virtual int32_t& MaxFactor_2() = 0;
    virtual void MaxFactor_2Updated() = 0;
    virtual float& DefaultDist_2() = 0;
    virtual void DefaultDist_2Updated() = 0;
    virtual CUtlSymbolLarge& NPCClassname_3() = 0;
    virtual void NPCClassname_3Updated() = 0;
    virtual int32_t& NPCState_3() = 0;
    virtual void NPCState_3Updated() = 0;
    virtual bool& InvertState_3() = 0;
    virtual void InvertState_3Updated() = 0;
    virtual int32_t& MinCount_3() = 0;
    virtual void MinCount_3Updated() = 0;
    virtual int32_t& MaxCount_3() = 0;
    virtual void MaxCount_3Updated() = 0;
    virtual int32_t& MinFactor_3() = 0;
    virtual void MinFactor_3Updated() = 0;
    virtual int32_t& MaxFactor_3() = 0;
    virtual void MaxFactor_3Updated() = 0;
    virtual float& DefaultDist_3() = 0;
    virtual void DefaultDist_3Updated() = 0;
    static ILogicNPCCounter* FromOriginal(CLogicNPCCounter* p);
};

#endif // _INCLUDE_ILOGICNPCCOUNTER_H
