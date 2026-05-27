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

#ifndef _INCLUDE_ILIGHTCOMPONENT_H
#define _INCLUDE_ILIGHTCOMPONENT_H

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

class CEntityInstance*;
class InfoForResourceTypeCTextureBase;

class ILightComponent
{
public:
    virtual ~ILightComponent() = default;

    virtual CEntityInstance*& __m_pChainEntity() = 0;
    virtual void __m_pChainEntityUpdated() = 0;
    virtual Color& Color() = 0;
    virtual void ColorUpdated() = 0;
    virtual Color& SecondaryColor() = 0;
    virtual void SecondaryColorUpdated() = 0;
    virtual float& Brightness() = 0;
    virtual void BrightnessUpdated() = 0;
    virtual float& BrightnessScale() = 0;
    virtual void BrightnessScaleUpdated() = 0;
    virtual float& BrightnessMult() = 0;
    virtual void BrightnessMultUpdated() = 0;
    virtual float& Range() = 0;
    virtual void RangeUpdated() = 0;
    virtual float& Falloff() = 0;
    virtual void FalloffUpdated() = 0;
    virtual float& Attenuation0() = 0;
    virtual void Attenuation0Updated() = 0;
    virtual float& Attenuation1() = 0;
    virtual void Attenuation1Updated() = 0;
    virtual float& Attenuation2() = 0;
    virtual void Attenuation2Updated() = 0;
    virtual float& Theta() = 0;
    virtual void ThetaUpdated() = 0;
    virtual float& Phi() = 0;
    virtual void PhiUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& LightCookie() = 0;
    virtual void LightCookieUpdated() = 0;
    virtual int32_t& Cascades() = 0;
    virtual void CascadesUpdated() = 0;
    virtual int32_t& CastShadows() = 0;
    virtual void CastShadowsUpdated() = 0;
    virtual int32_t& ShadowWidth() = 0;
    virtual void ShadowWidthUpdated() = 0;
    virtual int32_t& ShadowHeight() = 0;
    virtual void ShadowHeightUpdated() = 0;
    virtual bool& RenderDiffuse() = 0;
    virtual void RenderDiffuseUpdated() = 0;
    virtual int32_t& RenderSpecular() = 0;
    virtual void RenderSpecularUpdated() = 0;
    virtual bool& RenderTransmissive() = 0;
    virtual void RenderTransmissiveUpdated() = 0;
    virtual float& OrthoLightWidth() = 0;
    virtual void OrthoLightWidthUpdated() = 0;
    virtual float& OrthoLightHeight() = 0;
    virtual void OrthoLightHeightUpdated() = 0;
    virtual int32_t& Style() = 0;
    virtual void StyleUpdated() = 0;
    virtual CUtlString& Pattern() = 0;
    virtual void PatternUpdated() = 0;
    virtual int32_t& CascadeRenderStaticObjects() = 0;
    virtual void CascadeRenderStaticObjectsUpdated() = 0;
    virtual float& ShadowCascadeCrossFade() = 0;
    virtual void ShadowCascadeCrossFadeUpdated() = 0;
    virtual float& ShadowCascadeDistanceFade() = 0;
    virtual void ShadowCascadeDistanceFadeUpdated() = 0;
    virtual float& ShadowCascadeDistance0() = 0;
    virtual void ShadowCascadeDistance0Updated() = 0;
    virtual float& ShadowCascadeDistance1() = 0;
    virtual void ShadowCascadeDistance1Updated() = 0;
    virtual float& ShadowCascadeDistance2() = 0;
    virtual void ShadowCascadeDistance2Updated() = 0;
    virtual float& ShadowCascadeDistance3() = 0;
    virtual void ShadowCascadeDistance3Updated() = 0;
    virtual int32_t& ShadowCascadeResolution0() = 0;
    virtual void ShadowCascadeResolution0Updated() = 0;
    virtual int32_t& ShadowCascadeResolution1() = 0;
    virtual void ShadowCascadeResolution1Updated() = 0;
    virtual int32_t& ShadowCascadeResolution2() = 0;
    virtual void ShadowCascadeResolution2Updated() = 0;
    virtual int32_t& ShadowCascadeResolution3() = 0;
    virtual void ShadowCascadeResolution3Updated() = 0;
    virtual bool& UsesBakedShadowing() = 0;
    virtual void UsesBakedShadowingUpdated() = 0;
    virtual int32_t& ShadowPriority() = 0;
    virtual void ShadowPriorityUpdated() = 0;
    virtual int32_t& BakedShadowIndex() = 0;
    virtual void BakedShadowIndexUpdated() = 0;
    virtual int32_t& LightPathUniqueId() = 0;
    virtual void LightPathUniqueIdUpdated() = 0;
    virtual int32_t& LightMapUniqueId() = 0;
    virtual void LightMapUniqueIdUpdated() = 0;
    virtual bool& RenderToCubemaps() = 0;
    virtual void RenderToCubemapsUpdated() = 0;
    virtual bool& AllowSSTGeneration() = 0;
    virtual void AllowSSTGenerationUpdated() = 0;
    virtual int32_t& DirectLight() = 0;
    virtual void DirectLightUpdated() = 0;
    virtual int32_t& BounceLight() = 0;
    virtual void BounceLightUpdated() = 0;
    virtual float& BounceScale() = 0;
    virtual void BounceScaleUpdated() = 0;
    virtual float& FadeMinDist() = 0;
    virtual void FadeMinDistUpdated() = 0;
    virtual float& FadeMaxDist() = 0;
    virtual void FadeMaxDistUpdated() = 0;
    virtual float& ShadowFadeMinDist() = 0;
    virtual void ShadowFadeMinDistUpdated() = 0;
    virtual float& ShadowFadeMaxDist() = 0;
    virtual void ShadowFadeMaxDistUpdated() = 0;
    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    virtual bool& Flicker() = 0;
    virtual void FlickerUpdated() = 0;
    virtual bool& PrecomputedFieldsValid() = 0;
    virtual void PrecomputedFieldsValidUpdated() = 0;
    virtual Vector& PrecomputedBoundsMins() = 0;
    virtual void PrecomputedBoundsMinsUpdated() = 0;
    virtual Vector& PrecomputedBoundsMaxs() = 0;
    virtual void PrecomputedBoundsMaxsUpdated() = 0;
    virtual Vector& PrecomputedOBBOrigin() = 0;
    virtual void PrecomputedOBBOriginUpdated() = 0;
    virtual QAngle& PrecomputedOBBAngles() = 0;
    virtual void PrecomputedOBBAnglesUpdated() = 0;
    virtual Vector& PrecomputedOBBExtent() = 0;
    virtual void PrecomputedOBBExtentUpdated() = 0;
    virtual float& PrecomputedMaxRange() = 0;
    virtual void PrecomputedMaxRangeUpdated() = 0;
    virtual int32_t& FogLightingMode() = 0;
    virtual void FogLightingModeUpdated() = 0;
    virtual float& FogContributionStength() = 0;
    virtual void FogContributionStengthUpdated() = 0;
    virtual float& NearClipPlane() = 0;
    virtual void NearClipPlaneUpdated() = 0;
    virtual Color& SkyColor() = 0;
    virtual void SkyColorUpdated() = 0;
    virtual float& SkyIntensity() = 0;
    virtual void SkyIntensityUpdated() = 0;
    virtual Color& SkyAmbientBounce() = 0;
    virtual void SkyAmbientBounceUpdated() = 0;
    virtual bool& UseSecondaryColor() = 0;
    virtual void UseSecondaryColorUpdated() = 0;
    virtual bool& MixedShadows() = 0;
    virtual void MixedShadowsUpdated() = 0;
    virtual float& LightStyleStartTime() = 0;
    virtual void LightStyleStartTimeUpdated() = 0;
    virtual float& CapsuleLength() = 0;
    virtual void CapsuleLengthUpdated() = 0;
    virtual float& MinRoughness() = 0;
    virtual void MinRoughnessUpdated() = 0;
    virtual bool& PvsModifyEntity() = 0;
    virtual void PvsModifyEntityUpdated() = 0;
};

#endif // _INCLUDE_ILIGHTCOMPONENT_H
