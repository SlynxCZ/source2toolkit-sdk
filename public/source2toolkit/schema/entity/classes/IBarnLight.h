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

#ifndef _INCLUDE_IBARNLIGHT_H
#define _INCLUDE_IBARNLIGHT_H

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

#include "IBaseModelEntity.h"

class CBarnLight;
class CBaseModelEntity;
class InfoForResourceTypeCTextureBase;

class IBarnLight : public virtual IBaseModelEntity
{
public:
    virtual ~IBarnLight() = default;

    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    virtual int32_t& ColorMode() = 0;
    virtual void ColorModeUpdated() = 0;
    virtual Color& Color() = 0;
    virtual void ColorUpdated() = 0;
    virtual float& ColorTemperature() = 0;
    virtual void ColorTemperatureUpdated() = 0;
    virtual float& Brightness() = 0;
    virtual void BrightnessUpdated() = 0;
    virtual float& BrightnessScale() = 0;
    virtual void BrightnessScaleUpdated() = 0;
    virtual int32_t& DirectLight() = 0;
    virtual void DirectLightUpdated() = 0;
    virtual int32_t& BakedShadowIndex() = 0;
    virtual void BakedShadowIndexUpdated() = 0;
    virtual int32_t& LightPathUniqueId() = 0;
    virtual void LightPathUniqueIdUpdated() = 0;
    virtual int32_t& LightMapUniqueId() = 0;
    virtual void LightMapUniqueIdUpdated() = 0;
    virtual int32_t& LuminaireShape() = 0;
    virtual void LuminaireShapeUpdated() = 0;
    virtual float& LuminaireSize() = 0;
    virtual void LuminaireSizeUpdated() = 0;
    virtual float& LuminaireAnisotropy() = 0;
    virtual void LuminaireAnisotropyUpdated() = 0;
    virtual CUtlString& LightStyleString() = 0;
    virtual void LightStyleStringUpdated() = 0;
    virtual float& LightStyleStartTime() = 0;
    virtual void LightStyleStartTimeUpdated() = 0;
    virtual CUtlVector<CUtlString>& QueuedLightStyleStrings() = 0;
    virtual void QueuedLightStyleStringsUpdated() = 0;
    virtual CUtlVector<CUtlString>& LightStyleEvents() = 0;
    virtual void LightStyleEventsUpdated() = 0;
    virtual CUtlVector<CHandle<CBaseModelEntity>>& LightStyleTargets() = 0;
    virtual void LightStyleTargetsUpdated() = 0;
    virtual CEntityIOOutput* StyleEvent() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& LightCookie() = 0;
    virtual void LightCookieUpdated() = 0;
    virtual float& Shape() = 0;
    virtual void ShapeUpdated() = 0;
    virtual float& SoftX() = 0;
    virtual void SoftXUpdated() = 0;
    virtual float& SoftY() = 0;
    virtual void SoftYUpdated() = 0;
    virtual float& Skirt() = 0;
    virtual void SkirtUpdated() = 0;
    virtual float& SkirtNear() = 0;
    virtual void SkirtNearUpdated() = 0;
    virtual Vector& SizeParams() = 0;
    virtual void SizeParamsUpdated() = 0;
    virtual float& Range() = 0;
    virtual void RangeUpdated() = 0;
    virtual Vector& Shear() = 0;
    virtual void ShearUpdated() = 0;
    virtual int32_t& BakeSpecularToCubemaps() = 0;
    virtual void BakeSpecularToCubemapsUpdated() = 0;
    virtual Vector& BakeSpecularToCubemapsSize() = 0;
    virtual void BakeSpecularToCubemapsSizeUpdated() = 0;
    virtual float& BakeSpecularToCubemapsScale() = 0;
    virtual void BakeSpecularToCubemapsScaleUpdated() = 0;
    virtual int32_t& CastShadows() = 0;
    virtual void CastShadowsUpdated() = 0;
    virtual int32_t& ShadowMapSize() = 0;
    virtual void ShadowMapSizeUpdated() = 0;
    virtual int32_t& ShadowPriority() = 0;
    virtual void ShadowPriorityUpdated() = 0;
    virtual bool& ContactShadow() = 0;
    virtual void ContactShadowUpdated() = 0;
    virtual bool& ForceShadowsEnabled() = 0;
    virtual void ForceShadowsEnabledUpdated() = 0;
    virtual int32_t& BounceLight() = 0;
    virtual void BounceLightUpdated() = 0;
    virtual float& BounceScale() = 0;
    virtual void BounceScaleUpdated() = 0;
    virtual float& MinRoughness() = 0;
    virtual void MinRoughnessUpdated() = 0;
    virtual Vector& AlternateColor() = 0;
    virtual void AlternateColorUpdated() = 0;
    virtual float& AlternateColorBrightness() = 0;
    virtual void AlternateColorBrightnessUpdated() = 0;
    virtual int32_t& Fog() = 0;
    virtual void FogUpdated() = 0;
    virtual float& FogStrength() = 0;
    virtual void FogStrengthUpdated() = 0;
    virtual int32_t& FogShadows() = 0;
    virtual void FogShadowsUpdated() = 0;
    virtual float& FogScale() = 0;
    virtual void FogScaleUpdated() = 0;
    virtual float& FadeSizeStart() = 0;
    virtual void FadeSizeStartUpdated() = 0;
    virtual float& FadeSizeEnd() = 0;
    virtual void FadeSizeEndUpdated() = 0;
    virtual float& ShadowFadeSizeStart() = 0;
    virtual void ShadowFadeSizeStartUpdated() = 0;
    virtual float& ShadowFadeSizeEnd() = 0;
    virtual void ShadowFadeSizeEndUpdated() = 0;
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
    virtual int32_t& PrecomputedSubFrusta() = 0;
    virtual void PrecomputedSubFrustaUpdated() = 0;
    virtual Vector& PrecomputedOBBOrigin0() = 0;
    virtual void PrecomputedOBBOrigin0Updated() = 0;
    virtual QAngle& PrecomputedOBBAngles0() = 0;
    virtual void PrecomputedOBBAngles0Updated() = 0;
    virtual Vector& PrecomputedOBBExtent0() = 0;
    virtual void PrecomputedOBBExtent0Updated() = 0;
    virtual Vector& PrecomputedOBBOrigin1() = 0;
    virtual void PrecomputedOBBOrigin1Updated() = 0;
    virtual QAngle& PrecomputedOBBAngles1() = 0;
    virtual void PrecomputedOBBAngles1Updated() = 0;
    virtual Vector& PrecomputedOBBExtent1() = 0;
    virtual void PrecomputedOBBExtent1Updated() = 0;
    virtual Vector& PrecomputedOBBOrigin2() = 0;
    virtual void PrecomputedOBBOrigin2Updated() = 0;
    virtual QAngle& PrecomputedOBBAngles2() = 0;
    virtual void PrecomputedOBBAngles2Updated() = 0;
    virtual Vector& PrecomputedOBBExtent2() = 0;
    virtual void PrecomputedOBBExtent2Updated() = 0;
    virtual Vector& PrecomputedOBBOrigin3() = 0;
    virtual void PrecomputedOBBOrigin3Updated() = 0;
    virtual QAngle& PrecomputedOBBAngles3() = 0;
    virtual void PrecomputedOBBAngles3Updated() = 0;
    virtual Vector& PrecomputedOBBExtent3() = 0;
    virtual void PrecomputedOBBExtent3Updated() = 0;
    virtual Vector& PrecomputedOBBOrigin4() = 0;
    virtual void PrecomputedOBBOrigin4Updated() = 0;
    virtual QAngle& PrecomputedOBBAngles4() = 0;
    virtual void PrecomputedOBBAngles4Updated() = 0;
    virtual Vector& PrecomputedOBBExtent4() = 0;
    virtual void PrecomputedOBBExtent4Updated() = 0;
    virtual Vector& PrecomputedOBBOrigin5() = 0;
    virtual void PrecomputedOBBOrigin5Updated() = 0;
    virtual QAngle& PrecomputedOBBAngles5() = 0;
    virtual void PrecomputedOBBAngles5Updated() = 0;
    virtual Vector& PrecomputedOBBExtent5() = 0;
    virtual void PrecomputedOBBExtent5Updated() = 0;
    virtual bool& PvsModifyEntity() = 0;
    virtual void PvsModifyEntityUpdated() = 0;
    virtual bool& TransmitAlways() = 0;
    virtual void TransmitAlwaysUpdated() = 0;
    virtual CUtlVector<uint16_t>& VisClusters() = 0;
    virtual void VisClustersUpdated() = 0;
    static IBarnLight* FromOriginal(CBarnLight* p);
};

#endif // _INCLUDE_IBARNLIGHT_H
