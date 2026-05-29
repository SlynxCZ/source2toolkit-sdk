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

#ifndef _INCLUDE_IPARTICLESYSTEM_H
#define _INCLUDE_IPARTICLESYSTEM_H

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

#include "IBaseModelEntity.h"

class CBaseEntity;
class CParticleSystem;
class InfoForResourceTypeIParticleSystemDefinition;

class IParticleSystem : public virtual IBaseModelEntity
{
public:
    virtual ~IParticleSystem() = default;

    virtual char* SnapshotFileName() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual bool& Frozen() = 0;
    virtual void FrozenUpdated() = 0;
    virtual float& FreezeTransitionDuration() = 0;
    virtual void FreezeTransitionDurationUpdated() = 0;
    virtual int32_t& StopType() = 0;
    virtual void StopTypeUpdated() = 0;
    virtual bool& AnimateDuringGameplayPause() = 0;
    virtual void AnimateDuringGameplayPauseUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>& EffectIndex() = 0;
    virtual void EffectIndexUpdated() = 0;
    virtual float& StartTime() = 0;
    virtual void StartTimeUpdated() = 0;
    virtual float& PreSimTime() = 0;
    virtual void PreSimTimeUpdated() = 0;
    virtual Vector* ServerControlPoints() = 0;
    virtual uint8_t* ServerControlPointAssignments() = 0;
    virtual CHandle<CBaseEntity>* ControlPointEnts() = 0;
    virtual bool& NoSave() = 0;
    virtual void NoSaveUpdated() = 0;
    virtual bool& NoFreeze() = 0;
    virtual void NoFreezeUpdated() = 0;
    virtual bool& NoRamp() = 0;
    virtual void NoRampUpdated() = 0;
    virtual bool& StartActive() = 0;
    virtual void StartActiveUpdated() = 0;
    virtual CUtlSymbolLarge& EffectName() = 0;
    virtual void EffectNameUpdated() = 0;
    virtual CUtlSymbolLarge* ControlPointNames() = 0;
    virtual int32_t& DataCP() = 0;
    virtual void DataCPUpdated() = 0;
    virtual Vector& DataCPValue() = 0;
    virtual void DataCPValueUpdated() = 0;
    virtual int32_t& TintCP() = 0;
    virtual void TintCPUpdated() = 0;
    virtual Color& Tint() = 0;
    virtual void TintUpdated() = 0;
    static IParticleSystem* FromOriginal(CParticleSystem* p);
    static IParticleSystem* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IPARTICLESYSTEM_H
