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

#ifndef _INCLUDE_IENVVOLUMETRICFOGCONTROLLER_H
#define _INCLUDE_IENVVOLUMETRICFOGCONTROLLER_H

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

class CEnvVolumetricFogController;
class InfoForResourceTypeCTextureBase;

class IEnvVolumetricFogController : public virtual IBaseEntity
{
public:
    virtual ~IEnvVolumetricFogController() = default;
    CEnvVolumetricFogController* GetOriginal() { return reinterpret_cast<CEnvVolumetricFogController*>(IEntityInstance::GetOriginal()); }

    virtual float& Scattering() = 0;
    virtual void ScatteringUpdated() = 0;
    virtual Color& TintColor() = 0;
    virtual void TintColorUpdated() = 0;
    virtual float& Anisotropy() = 0;
    virtual void AnisotropyUpdated() = 0;
    virtual float& FadeSpeed() = 0;
    virtual void FadeSpeedUpdated() = 0;
    virtual float& DrawDistance() = 0;
    virtual void DrawDistanceUpdated() = 0;
    virtual float& FadeInStart() = 0;
    virtual void FadeInStartUpdated() = 0;
    virtual float& FadeInEnd() = 0;
    virtual void FadeInEndUpdated() = 0;
    virtual float& IndirectStrength() = 0;
    virtual void IndirectStrengthUpdated() = 0;
    virtual int32_t& VolumeDepth() = 0;
    virtual void VolumeDepthUpdated() = 0;
    virtual float& FirstVolumeSliceThickness() = 0;
    virtual void FirstVolumeSliceThicknessUpdated() = 0;
    virtual int32_t& IndirectTextureDimX() = 0;
    virtual void IndirectTextureDimXUpdated() = 0;
    virtual int32_t& IndirectTextureDimY() = 0;
    virtual void IndirectTextureDimYUpdated() = 0;
    virtual int32_t& IndirectTextureDimZ() = 0;
    virtual void IndirectTextureDimZUpdated() = 0;
    virtual Vector& BoxMins() = 0;
    virtual void BoxMinsUpdated() = 0;
    virtual Vector& BoxMaxs() = 0;
    virtual void BoxMaxsUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual float& StartAnisoTime() = 0;
    virtual void StartAnisoTimeUpdated() = 0;
    virtual float& StartScatterTime() = 0;
    virtual void StartScatterTimeUpdated() = 0;
    virtual float& StartDrawDistanceTime() = 0;
    virtual void StartDrawDistanceTimeUpdated() = 0;
    virtual float& StartAnisotropy() = 0;
    virtual void StartAnisotropyUpdated() = 0;
    virtual float& StartScattering() = 0;
    virtual void StartScatteringUpdated() = 0;
    virtual float& StartDrawDistance() = 0;
    virtual void StartDrawDistanceUpdated() = 0;
    virtual float& DefaultAnisotropy() = 0;
    virtual void DefaultAnisotropyUpdated() = 0;
    virtual float& DefaultScattering() = 0;
    virtual void DefaultScatteringUpdated() = 0;
    virtual float& DefaultDrawDistance() = 0;
    virtual void DefaultDrawDistanceUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual bool& EnableIndirect() = 0;
    virtual void EnableIndirectUpdated() = 0;
    virtual bool& IsMaster() = 0;
    virtual void IsMasterUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& FogIndirectTexture() = 0;
    virtual void FogIndirectTextureUpdated() = 0;
    virtual int32_t& ForceRefreshCount() = 0;
    virtual void ForceRefreshCountUpdated() = 0;
    virtual float& NoiseSpeed() = 0;
    virtual void NoiseSpeedUpdated() = 0;
    virtual float& NoiseStrength() = 0;
    virtual void NoiseStrengthUpdated() = 0;
    virtual Vector& NoiseScale() = 0;
    virtual void NoiseScaleUpdated() = 0;
    virtual float& WindSpeed() = 0;
    virtual void WindSpeedUpdated() = 0;
    virtual Vector& WindDirection() = 0;
    virtual void WindDirectionUpdated() = 0;
    virtual bool& FirstTime() = 0;
    virtual void FirstTimeUpdated() = 0;
    static IEnvVolumetricFogController* FromOriginal(CEnvVolumetricFogController* p);
};

#endif // _INCLUDE_IENVVOLUMETRICFOGCONTROLLER_H
