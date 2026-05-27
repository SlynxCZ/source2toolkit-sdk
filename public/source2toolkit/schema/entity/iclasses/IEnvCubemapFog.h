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

#ifndef _INCLUDE_IENVCUBEMAPFOG_H
#define _INCLUDE_IENVCUBEMAPFOG_H

#pragma once

#include <cstdint>

#include "IBaseEntity.h"

class InfoForResourceTypeCTextureBase;
class InfoForResourceTypeIMaterial2;

class IEnvCubemapFog : public virtual IBaseEntity
{
public:
    virtual ~IEnvCubemapFog() = default;

    virtual float& EndDistance() = 0;
    virtual void EndDistanceUpdated() = 0;
    virtual float& StartDistance() = 0;
    virtual void StartDistanceUpdated() = 0;
    virtual float& FogFalloffExponent() = 0;
    virtual void FogFalloffExponentUpdated() = 0;
    virtual bool& HeightFogEnabled() = 0;
    virtual void HeightFogEnabledUpdated() = 0;
    virtual float& FogHeightWidth() = 0;
    virtual void FogHeightWidthUpdated() = 0;
    virtual float& FogHeightEnd() = 0;
    virtual void FogHeightEndUpdated() = 0;
    virtual float& FogHeightStart() = 0;
    virtual void FogHeightStartUpdated() = 0;
    virtual float& FogHeightExponent() = 0;
    virtual void FogHeightExponentUpdated() = 0;
    virtual float& LODBias() = 0;
    virtual void LODBiasUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual float& FogMaxOpacity() = 0;
    virtual void FogMaxOpacityUpdated() = 0;
    virtual int32_t& CubemapSourceType() = 0;
    virtual void CubemapSourceTypeUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& SkyMaterial() = 0;
    virtual void SkyMaterialUpdated() = 0;
    virtual CUtlSymbolLarge& SkyEntity() = 0;
    virtual void SkyEntityUpdated() = 0;
    virtual int32_t& HeightFogType() = 0;
    virtual void HeightFogTypeUpdated() = 0;
    virtual int32_t& FogHeightBlendMode() = 0;
    virtual void FogHeightBlendModeUpdated() = 0;
    virtual int32_t& FogHeightCoordinateSpace() = 0;
    virtual void FogHeightCoordinateSpaceUpdated() = 0;
    virtual int32_t& DistanceFogType() = 0;
    virtual void DistanceFogTypeUpdated() = 0;
    virtual CUtlSymbolLarge& DistanceFogCurveString() = 0;
    virtual void DistanceFogCurveStringUpdated() = 0;
    virtual CUtlSymbolLarge& HeightFogCurveString() = 0;
    virtual void HeightFogCurveStringUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& FogCubemapTexture() = 0;
    virtual void FogCubemapTextureUpdated() = 0;
    virtual bool& HasHeightFogEnd() = 0;
    virtual void HasHeightFogEndUpdated() = 0;
    virtual bool& FirstTime() = 0;
    virtual void FirstTimeUpdated() = 0;
};

#endif // _INCLUDE_IENVCUBEMAPFOG_H
