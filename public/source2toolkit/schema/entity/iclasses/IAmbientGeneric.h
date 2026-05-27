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

#ifndef _INCLUDE_IAMBIENTGENERIC_H
#define _INCLUDE_IAMBIENTGENERIC_H

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

#include "IPointEntity.h"

class CBaseEntity;
class dynpitchvol_t;

class IAmbientGeneric : public virtual IPointEntity
{
public:
    virtual ~IAmbientGeneric() = default;

    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual float& MaxRadius() = 0;
    virtual void MaxRadiusUpdated() = 0;
    virtual soundlevel_t& SoundLevel() = 0;
    virtual void SoundLevelUpdated() = 0;
    virtual dynpitchvol_t& Dpv() = 0;
    virtual void DpvUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual bool& Looping() = 0;
    virtual void LoopingUpdated() = 0;
    virtual CUtlSymbolLarge& Sound() = 0;
    virtual void SoundUpdated() = 0;
    virtual CUtlSymbolLarge& SourceEntName() = 0;
    virtual void SourceEntNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& SoundSource() = 0;
    virtual void SoundSourceUpdated() = 0;
    virtual CEntityIndex& SoundSourceEntIndex() = 0;
    virtual void SoundSourceEntIndexUpdated() = 0;
};

#endif // _INCLUDE_IAMBIENTGENERIC_H
