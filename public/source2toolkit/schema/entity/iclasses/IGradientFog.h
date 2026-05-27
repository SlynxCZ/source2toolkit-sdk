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

#ifndef _INCLUDE_IGRADIENTFOG_H
#define _INCLUDE_IGRADIENTFOG_H

#pragma once

#include <cstdint>

#include "IBaseEntity.h"

class InfoForResourceTypeCTextureBase;

class IGradientFog : public virtual IBaseEntity
{
public:
    virtual ~IGradientFog() = default;

    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& GradientFogTexture() = 0;
    virtual void GradientFogTextureUpdated() = 0;
    virtual float& FogStartDistance() = 0;
    virtual void FogStartDistanceUpdated() = 0;
    virtual float& FogEndDistance() = 0;
    virtual void FogEndDistanceUpdated() = 0;
    virtual bool& HeightFogEnabled() = 0;
    virtual void HeightFogEnabledUpdated() = 0;
    virtual float& FogStartHeight() = 0;
    virtual void FogStartHeightUpdated() = 0;
    virtual float& FogEndHeight() = 0;
    virtual void FogEndHeightUpdated() = 0;
    virtual float& FarZ() = 0;
    virtual void FarZUpdated() = 0;
    virtual float& FogMaxOpacity() = 0;
    virtual void FogMaxOpacityUpdated() = 0;
    virtual float& FogFalloffExponent() = 0;
    virtual void FogFalloffExponentUpdated() = 0;
    virtual float& FogVerticalExponent() = 0;
    virtual void FogVerticalExponentUpdated() = 0;
    virtual Color& FogColor() = 0;
    virtual void FogColorUpdated() = 0;
    virtual float& FogStrength() = 0;
    virtual void FogStrengthUpdated() = 0;
    virtual float& FadeTime() = 0;
    virtual void FadeTimeUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual bool& IsEnabled() = 0;
    virtual void IsEnabledUpdated() = 0;
    virtual bool& GradientFogNeedsTextures() = 0;
    virtual void GradientFogNeedsTexturesUpdated() = 0;
};

#endif // _INCLUDE_IGRADIENTFOG_H
