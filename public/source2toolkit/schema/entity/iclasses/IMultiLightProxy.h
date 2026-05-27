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

#ifndef _INCLUDE_IMULTILIGHTPROXY_H
#define _INCLUDE_IMULTILIGHTPROXY_H

#pragma once

#include <cstdint>

#include "ILogicalEntity.h"

class CLightEntity;

class IMultiLightProxy : public virtual ILogicalEntity
{
public:
    virtual ~IMultiLightProxy() = default;

    virtual CUtlSymbolLarge& LightNameFilter() = 0;
    virtual void LightNameFilterUpdated() = 0;
    virtual CUtlSymbolLarge& LightClassFilter() = 0;
    virtual void LightClassFilterUpdated() = 0;
    virtual float& LightRadiusFilter() = 0;
    virtual void LightRadiusFilterUpdated() = 0;
    virtual float& BrightnessDelta() = 0;
    virtual void BrightnessDeltaUpdated() = 0;
    virtual bool& PerformScreenFade() = 0;
    virtual void PerformScreenFadeUpdated() = 0;
    virtual float& TargetBrightnessMultiplier() = 0;
    virtual void TargetBrightnessMultiplierUpdated() = 0;
    virtual float& CurrentBrightnessMultiplier() = 0;
    virtual void CurrentBrightnessMultiplierUpdated() = 0;
    virtual CUtlVector<CHandle<CLightEntity>>& Lights() = 0;
    virtual void LightsUpdated() = 0;
};

#endif // _INCLUDE_IMULTILIGHTPROXY_H
