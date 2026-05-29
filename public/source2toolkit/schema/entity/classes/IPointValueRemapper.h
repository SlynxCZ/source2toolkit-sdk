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

#ifndef _INCLUDE_IPOINTVALUEREMAPPER_H
#define _INCLUDE_IPOINTVALUEREMAPPER_H

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

#include "../enums/ValueRemapperHapticsType_t.h"
#include "../enums/ValueRemapperInputType_t.h"
#include "../enums/ValueRemapperMomentumType_t.h"
#include "../enums/ValueRemapperOutputType_t.h"
#include "../enums/ValueRemapperRatchetType_t.h"

class CBaseEntity;
class CBasePlayerPawn;
class CPointValueRemapper;

class IPointValueRemapper : public virtual IBaseEntity
{
public:
    virtual ~IPointValueRemapper() = default;
    CPointValueRemapper* GetOriginal() { return reinterpret_cast<CPointValueRemapper*>(IEntityInstance::GetOriginal()); }

    virtual bool& Disabled() = 0;
    virtual void DisabledUpdated() = 0;
    virtual bool& UpdateOnClient() = 0;
    virtual void UpdateOnClientUpdated() = 0;
    virtual ::ValueRemapperInputType_t& InputType() = 0;
    virtual void InputTypeUpdated() = 0;
    virtual CUtlSymbolLarge& RemapLineStartName() = 0;
    virtual void RemapLineStartNameUpdated() = 0;
    virtual CUtlSymbolLarge& RemapLineEndName() = 0;
    virtual void RemapLineEndNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& RemapLineStart() = 0;
    virtual void RemapLineStartUpdated() = 0;
    virtual CHandle<CBaseEntity>& RemapLineEnd() = 0;
    virtual void RemapLineEndUpdated() = 0;
    virtual float& MaximumChangePerSecond() = 0;
    virtual void MaximumChangePerSecondUpdated() = 0;
    virtual float& DisengageDistance() = 0;
    virtual void DisengageDistanceUpdated() = 0;
    virtual float& EngageDistance() = 0;
    virtual void EngageDistanceUpdated() = 0;
    virtual bool& RequiresUseKey() = 0;
    virtual void RequiresUseKeyUpdated() = 0;
    virtual ::ValueRemapperOutputType_t& OutputType() = 0;
    virtual void OutputTypeUpdated() = 0;
    virtual CUtlSymbolLarge& OutputEntityName() = 0;
    virtual void OutputEntityNameUpdated() = 0;
    virtual CUtlSymbolLarge& OutputEntity2Name() = 0;
    virtual void OutputEntity2NameUpdated() = 0;
    virtual CUtlSymbolLarge& OutputEntity3Name() = 0;
    virtual void OutputEntity3NameUpdated() = 0;
    virtual CUtlSymbolLarge& OutputEntity4Name() = 0;
    virtual void OutputEntity4NameUpdated() = 0;
    virtual CUtlVector<CHandle<CBaseEntity>>& OutputEntities() = 0;
    virtual void OutputEntitiesUpdated() = 0;
    virtual ::ValueRemapperHapticsType_t& HapticsType() = 0;
    virtual void HapticsTypeUpdated() = 0;
    virtual ::ValueRemapperMomentumType_t& MomentumType() = 0;
    virtual void MomentumTypeUpdated() = 0;
    virtual float& MomentumModifier() = 0;
    virtual void MomentumModifierUpdated() = 0;
    virtual float& SnapValue() = 0;
    virtual void SnapValueUpdated() = 0;
    virtual float& CurrentMomentum() = 0;
    virtual void CurrentMomentumUpdated() = 0;
    virtual ::ValueRemapperRatchetType_t& RatchetType() = 0;
    virtual void RatchetTypeUpdated() = 0;
    virtual float& RatchetOffset() = 0;
    virtual void RatchetOffsetUpdated() = 0;
    virtual float& InputOffset() = 0;
    virtual void InputOffsetUpdated() = 0;
    virtual bool& Engaged() = 0;
    virtual void EngagedUpdated() = 0;
    virtual bool& FirstUpdate() = 0;
    virtual void FirstUpdateUpdated() = 0;
    virtual float& PreviousValue() = 0;
    virtual void PreviousValueUpdated() = 0;
    virtual float& PreviousUpdateTickTime() = 0;
    virtual void PreviousUpdateTickTimeUpdated() = 0;
    virtual Vector& PreviousTestPoint() = 0;
    virtual void PreviousTestPointUpdated() = 0;
    virtual CHandle<CBasePlayerPawn>& UsingPlayer() = 0;
    virtual void UsingPlayerUpdated() = 0;
    virtual float& CustomOutputValue() = 0;
    virtual void CustomOutputValueUpdated() = 0;
    virtual CUtlSymbolLarge& SoundEngage() = 0;
    virtual void SoundEngageUpdated() = 0;
    virtual CUtlSymbolLarge& SoundDisengage() = 0;
    virtual void SoundDisengageUpdated() = 0;
    virtual CUtlSymbolLarge& SoundReachedValueZero() = 0;
    virtual void SoundReachedValueZeroUpdated() = 0;
    virtual CUtlSymbolLarge& SoundReachedValueOne() = 0;
    virtual void SoundReachedValueOneUpdated() = 0;
    virtual CUtlSymbolLarge& SoundMovingLoop() = 0;
    virtual void SoundMovingLoopUpdated() = 0;
    virtual ::CEntityIOOutput& OnReachedValueZero() = 0;
    virtual void OnReachedValueZeroUpdated() = 0;
    virtual ::CEntityIOOutput& OnReachedValueOne() = 0;
    virtual void OnReachedValueOneUpdated() = 0;
    virtual ::CEntityIOOutput& OnReachedValueCustom() = 0;
    virtual void OnReachedValueCustomUpdated() = 0;
    virtual ::CEntityIOOutput& OnEngage() = 0;
    virtual void OnEngageUpdated() = 0;
    virtual ::CEntityIOOutput& OnDisengage() = 0;
    virtual void OnDisengageUpdated() = 0;
    static IPointValueRemapper* FromOriginal(CPointValueRemapper* p);
};

#endif // _INCLUDE_IPOINTVALUEREMAPPER_H
