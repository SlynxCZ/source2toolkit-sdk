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

#ifndef _INCLUDE_ILOGICAUTO_H
#define _INCLUDE_ILOGICAUTO_H

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

class ILogicAuto : public virtual IBaseEntity
{
public:
    virtual ~ILogicAuto() = default;

    virtual CEntityIOOutput& OnMapSpawn() = 0;
    virtual void OnMapSpawnUpdated() = 0;
    virtual CEntityIOOutput& OnDemoMapSpawn() = 0;
    virtual void OnDemoMapSpawnUpdated() = 0;
    virtual CEntityIOOutput& OnNewGame() = 0;
    virtual void OnNewGameUpdated() = 0;
    virtual CEntityIOOutput& OnLoadGame() = 0;
    virtual void OnLoadGameUpdated() = 0;
    virtual CEntityIOOutput& OnMapTransition() = 0;
    virtual void OnMapTransitionUpdated() = 0;
    virtual CEntityIOOutput& OnBackgroundMap() = 0;
    virtual void OnBackgroundMapUpdated() = 0;
    virtual CEntityIOOutput& OnMultiNewMap() = 0;
    virtual void OnMultiNewMapUpdated() = 0;
    virtual CEntityIOOutput& OnMultiNewRound() = 0;
    virtual void OnMultiNewRoundUpdated() = 0;
    virtual CEntityIOOutput& OnVREnabled() = 0;
    virtual void OnVREnabledUpdated() = 0;
    virtual CEntityIOOutput& OnVRNotEnabled() = 0;
    virtual void OnVRNotEnabledUpdated() = 0;
    virtual CUtlSymbolLarge& Globalstate() = 0;
    virtual void GlobalstateUpdated() = 0;
};

#endif // _INCLUDE_ILOGICAUTO_H
