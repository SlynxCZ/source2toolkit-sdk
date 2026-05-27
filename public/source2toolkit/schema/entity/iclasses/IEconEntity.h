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

#ifndef _INCLUDE_IECONENTITY_H
#define _INCLUDE_IECONENTITY_H

#pragma once

#include <cstdint>

#include "IBaseAnimGraph.h"

#include "CAttributeContainer.h"

class CBaseEntity;

class IEconEntity : public virtual IBaseAnimGraph
{
public:
    virtual ~IEconEntity() = default;

    virtual CAttributeContainer& AttributeManager() = 0;
    virtual void AttributeManagerUpdated() = 0;
    virtual uint32_t& OriginalOwnerXuidLow() = 0;
    virtual void OriginalOwnerXuidLowUpdated() = 0;
    virtual uint32_t& OriginalOwnerXuidHigh() = 0;
    virtual void OriginalOwnerXuidHighUpdated() = 0;
    virtual int32_t& FallbackPaintKit() = 0;
    virtual void FallbackPaintKitUpdated() = 0;
    virtual int32_t& FallbackSeed() = 0;
    virtual void FallbackSeedUpdated() = 0;
    virtual float& FallbackWear() = 0;
    virtual void FallbackWearUpdated() = 0;
    virtual int32_t& FallbackStatTrak() = 0;
    virtual void FallbackStatTrakUpdated() = 0;
    virtual CHandle<CBaseEntity>& OldProvidee() = 0;
    virtual void OldProvideeUpdated() = 0;
    virtual int32_t& OldOwnerClass() = 0;
    virtual void OldOwnerClassUpdated() = 0;
};

#endif // _INCLUDE_IECONENTITY_H
