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

#ifndef _INCLUDE_IENVCOMBINEDLIGHTPROBEVOLUME_H
#define _INCLUDE_IENVCOMBINEDLIGHTPROBEVOLUME_H

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

class InfoForResourceTypeCTextureBase;

class IEnvCombinedLightProbeVolume : public virtual IBaseEntity
{
public:
    virtual ~IEnvCombinedLightProbeVolume() = default;

    virtual Color& Entity_Color() = 0;
    virtual void Entity_ColorUpdated() = 0;
    virtual float& Entity_flBrightness() = 0;
    virtual void Entity_flBrightnessUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hCubemapTexture() = 0;
    virtual void Entity_hCubemapTextureUpdated() = 0;
    virtual bool& Entity_bCustomCubemapTexture() = 0;
    virtual void Entity_bCustomCubemapTextureUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeTexture_AmbientCube() = 0;
    virtual void Entity_hLightProbeTexture_AmbientCubeUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeTexture_SDF() = 0;
    virtual void Entity_hLightProbeTexture_SDFUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeTexture_SH2_DC() = 0;
    virtual void Entity_hLightProbeTexture_SH2_DCUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeTexture_SH2_R() = 0;
    virtual void Entity_hLightProbeTexture_SH2_RUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeTexture_SH2_G() = 0;
    virtual void Entity_hLightProbeTexture_SH2_GUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeTexture_SH2_B() = 0;
    virtual void Entity_hLightProbeTexture_SH2_BUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeDirectLightIndicesTexture() = 0;
    virtual void Entity_hLightProbeDirectLightIndicesTextureUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeDirectLightScalarsTexture() = 0;
    virtual void Entity_hLightProbeDirectLightScalarsTextureUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hLightProbeDirectLightShadowsTexture() = 0;
    virtual void Entity_hLightProbeDirectLightShadowsTextureUpdated() = 0;
    virtual Vector& Entity_vBoxMins() = 0;
    virtual void Entity_vBoxMinsUpdated() = 0;
    virtual Vector& Entity_vBoxMaxs() = 0;
    virtual void Entity_vBoxMaxsUpdated() = 0;
    virtual bool& Entity_bMoveable() = 0;
    virtual void Entity_bMoveableUpdated() = 0;
    virtual int32_t& Entity_nHandshake() = 0;
    virtual void Entity_nHandshakeUpdated() = 0;
    virtual int32_t& Entity_nEnvCubeMapArrayIndex() = 0;
    virtual void Entity_nEnvCubeMapArrayIndexUpdated() = 0;
    virtual int32_t& Entity_nPriority() = 0;
    virtual void Entity_nPriorityUpdated() = 0;
    virtual bool& Entity_bStartDisabled() = 0;
    virtual void Entity_bStartDisabledUpdated() = 0;
    virtual float& Entity_flEdgeFadeDist() = 0;
    virtual void Entity_flEdgeFadeDistUpdated() = 0;
    virtual Vector& Entity_vEdgeFadeDists() = 0;
    virtual void Entity_vEdgeFadeDistsUpdated() = 0;
    virtual int32_t& Entity_nLightProbeSizeX() = 0;
    virtual void Entity_nLightProbeSizeXUpdated() = 0;
    virtual int32_t& Entity_nLightProbeSizeY() = 0;
    virtual void Entity_nLightProbeSizeYUpdated() = 0;
    virtual int32_t& Entity_nLightProbeSizeZ() = 0;
    virtual void Entity_nLightProbeSizeZUpdated() = 0;
    virtual int32_t& Entity_nLightProbeAtlasX() = 0;
    virtual void Entity_nLightProbeAtlasXUpdated() = 0;
    virtual int32_t& Entity_nLightProbeAtlasY() = 0;
    virtual void Entity_nLightProbeAtlasYUpdated() = 0;
    virtual int32_t& Entity_nLightProbeAtlasZ() = 0;
    virtual void Entity_nLightProbeAtlasZUpdated() = 0;
    virtual bool& Entity_bEnabled() = 0;
    virtual void Entity_bEnabledUpdated() = 0;
};

#endif // _INCLUDE_IENVCOMBINEDLIGHTPROBEVOLUME_H
