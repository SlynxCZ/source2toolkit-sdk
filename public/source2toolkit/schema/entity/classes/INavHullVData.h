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

#ifndef _INCLUDE_INAVHULLVDATA_H
#define _INCLUDE_INAVHULLVDATA_H

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

#include "IEntityInstance.h"

class CNavHullVData;

class INavHullVData
{
public:
    virtual ~INavHullVData() = default;
    virtual CNavHullVData* GetOriginal() const = 0;

    virtual bool& AgentEnabled() = 0;
    virtual void AgentEnabledUpdated() = 0;
    virtual float& AgentRadius() = 0;
    virtual void AgentRadiusUpdated() = 0;
    virtual float& AgentHeight() = 0;
    virtual void AgentHeightUpdated() = 0;
    virtual bool& AgentShortHeightEnabled() = 0;
    virtual void AgentShortHeightEnabledUpdated() = 0;
    virtual float& AgentShortHeight() = 0;
    virtual void AgentShortHeightUpdated() = 0;
    virtual bool& AgentCrawlEnabled() = 0;
    virtual void AgentCrawlEnabledUpdated() = 0;
    virtual float& AgentCrawlHeight() = 0;
    virtual void AgentCrawlHeightUpdated() = 0;
    virtual float& AgentMaxClimb() = 0;
    virtual void AgentMaxClimbUpdated() = 0;
    virtual int32_t& AgentMaxSlope() = 0;
    virtual void AgentMaxSlopeUpdated() = 0;
    virtual float& AgentMaxJumpDownDist() = 0;
    virtual void AgentMaxJumpDownDistUpdated() = 0;
    virtual float& AgentMaxJumpHorizDistBase() = 0;
    virtual void AgentMaxJumpHorizDistBaseUpdated() = 0;
    virtual float& AgentMaxJumpUpDist() = 0;
    virtual void AgentMaxJumpUpDistUpdated() = 0;
    virtual int32_t& AgentBorderErosion() = 0;
    virtual void AgentBorderErosionUpdated() = 0;
    virtual bool& FlowMapGenerationEnabled() = 0;
    virtual void FlowMapGenerationEnabledUpdated() = 0;
    virtual float& FlowMapNodeMaxRadius() = 0;
    virtual void FlowMapNodeMaxRadiusUpdated() = 0;
    static INavHullVData* FromOriginal(CNavHullVData* p);
};

#endif // _INCLUDE_INAVHULLVDATA_H
