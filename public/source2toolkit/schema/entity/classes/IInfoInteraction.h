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

#ifndef _INCLUDE_IINFOINTERACTION_H
#define _INCLUDE_IINFOINTERACTION_H

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

#include "IPointEntity.h"

class CInfoInteraction;
class SceneOpportunityHandle_t;
class SceneRequestHandle_t;

class IInfoInteraction : public virtual IPointEntity
{
public:
    virtual ~IInfoInteraction() = default;

    virtual ::SceneRequestHandle_t& SceneRequest() = 0;
    virtual void SceneRequestUpdated() = 0;
    virtual ::SceneOpportunityHandle_t& SceneOpportunity() = 0;
    virtual void SceneOpportunityUpdated() = 0;
    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual CUtlSymbolLarge& StrSceneVDataName() = 0;
    virtual void StrSceneVDataNameUpdated() = 0;
    virtual CUtlSymbolLarge& StrPulseVDataName() = 0;
    virtual void StrPulseVDataNameUpdated() = 0;
    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual float& OwnerFOV() = 0;
    virtual void OwnerFOVUpdated() = 0;
    virtual CUtlSymbolLarge& StrLocalInterestReqTags() = 0;
    virtual void StrLocalInterestReqTagsUpdated() = 0;
    virtual CUtlSymbolLarge& StrLocalInterestOptTags() = 0;
    virtual void StrLocalInterestOptTagsUpdated() = 0;
    virtual CUtlSymbolLarge& StrLookTarget() = 0;
    virtual void StrLookTargetUpdated() = 0;
    virtual float& Duration() = 0;
    virtual void DurationUpdated() = 0;
    virtual float& Cooldown() = 0;
    virtual void CooldownUpdated() = 0;
    virtual int32_t& RepeatCount() = 0;
    virtual void RepeatCountUpdated() = 0;
    virtual bool& DisableOnExit() = 0;
    virtual void DisableOnExitUpdated() = 0;
    static IInfoInteraction* FromOriginal(CInfoInteraction* p);
    static IInfoInteraction* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IINFOINTERACTION_H
