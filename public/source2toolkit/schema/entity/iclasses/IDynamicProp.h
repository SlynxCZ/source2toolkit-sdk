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

#ifndef _INCLUDE_IDYNAMICPROP_H
#define _INCLUDE_IDYNAMICPROP_H

#pragma once

#include <cstdint>

#include "IBreakableProp.h"

#include "../enums/AnimLoopMode_t.h"

class IDynamicProp : public virtual IBreakableProp
{
public:
    virtual ~IDynamicProp() = default;

    virtual bool& CreateNavObstacle() = 0;
    virtual void CreateNavObstacleUpdated() = 0;
    virtual bool& NavObstacleUpdatesOverridden() = 0;
    virtual void NavObstacleUpdatesOverriddenUpdated() = 0;
    virtual bool& UseHitboxesForRenderBox() = 0;
    virtual void UseHitboxesForRenderBoxUpdated() = 0;
    virtual bool& UseAnimGraph() = 0;
    virtual void UseAnimGraphUpdated() = 0;
    virtual CEntityIOOutput& OutputAnimBegun() = 0;
    virtual void OutputAnimBegunUpdated() = 0;
    virtual CEntityIOOutput& OutputAnimOver() = 0;
    virtual void OutputAnimOverUpdated() = 0;
    virtual CEntityIOOutput& OutputAnimLoopCycleOver() = 0;
    virtual void OutputAnimLoopCycleOverUpdated() = 0;
    virtual CEntityIOOutput& OnAnimReachedStart() = 0;
    virtual void OnAnimReachedStartUpdated() = 0;
    virtual CEntityIOOutput& OnAnimReachedEnd() = 0;
    virtual void OnAnimReachedEndUpdated() = 0;
    virtual CUtlSymbolLarge& IdleAnim() = 0;
    virtual void IdleAnimUpdated() = 0;
    virtual AnimLoopMode_t& IdleAnimLoopMode() = 0;
    virtual void IdleAnimLoopModeUpdated() = 0;
    virtual bool& RandomizeCycle() = 0;
    virtual void RandomizeCycleUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual bool& FiredStartEndOutput() = 0;
    virtual void FiredStartEndOutputUpdated() = 0;
    virtual bool& ForceNpcExclude() = 0;
    virtual void ForceNpcExcludeUpdated() = 0;
    virtual bool& CreateNonSolid() = 0;
    virtual void CreateNonSolidUpdated() = 0;
    virtual bool& IsOverrideProp() = 0;
    virtual void IsOverridePropUpdated() = 0;
    virtual int32_t& InitialGlowState() = 0;
    virtual void InitialGlowStateUpdated() = 0;
    virtual int32_t& GlowRange() = 0;
    virtual void GlowRangeUpdated() = 0;
    virtual int32_t& GlowRangeMin() = 0;
    virtual void GlowRangeMinUpdated() = 0;
    virtual Color& GlowColor() = 0;
    virtual void GlowColorUpdated() = 0;
    virtual int32_t& GlowTeam() = 0;
    virtual void GlowTeamUpdated() = 0;
};

#endif // _INCLUDE_IDYNAMICPROP_H
