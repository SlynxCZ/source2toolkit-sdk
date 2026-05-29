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

#ifndef _INCLUDE_IPOINTCAMERA_H
#define _INCLUDE_IPOINTCAMERA_H

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

class CPointCamera;

class IPointCamera : public virtual IBaseEntity
{
public:
    virtual ~IPointCamera() = default;

    virtual float& FOV() = 0;
    virtual void FOVUpdated() = 0;
    virtual float& Resolution() = 0;
    virtual void ResolutionUpdated() = 0;
    virtual bool& FogEnable() = 0;
    virtual void FogEnableUpdated() = 0;
    virtual Color& FogColor() = 0;
    virtual void FogColorUpdated() = 0;
    virtual float& FogStart() = 0;
    virtual void FogStartUpdated() = 0;
    virtual float& FogEnd() = 0;
    virtual void FogEndUpdated() = 0;
    virtual float& FogMaxDensity() = 0;
    virtual void FogMaxDensityUpdated() = 0;
    virtual bool& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual bool& UseScreenAspectRatio() = 0;
    virtual void UseScreenAspectRatioUpdated() = 0;
    virtual float& AspectRatio() = 0;
    virtual void AspectRatioUpdated() = 0;
    virtual bool& NoSky() = 0;
    virtual void NoSkyUpdated() = 0;
    virtual float& Brightness() = 0;
    virtual void BrightnessUpdated() = 0;
    virtual float& ZFar() = 0;
    virtual void ZFarUpdated() = 0;
    virtual float& ZNear() = 0;
    virtual void ZNearUpdated() = 0;
    virtual bool& CanHLTVUse() = 0;
    virtual void CanHLTVUseUpdated() = 0;
    virtual bool& AlignWithParent() = 0;
    virtual void AlignWithParentUpdated() = 0;
    virtual bool& DofEnabled() = 0;
    virtual void DofEnabledUpdated() = 0;
    virtual float& DofNearBlurry() = 0;
    virtual void DofNearBlurryUpdated() = 0;
    virtual float& DofNearCrisp() = 0;
    virtual void DofNearCrispUpdated() = 0;
    virtual float& DofFarCrisp() = 0;
    virtual void DofFarCrispUpdated() = 0;
    virtual float& DofFarBlurry() = 0;
    virtual void DofFarBlurryUpdated() = 0;
    virtual float& DofTiltToGround() = 0;
    virtual void DofTiltToGroundUpdated() = 0;
    virtual float& TargetFOV() = 0;
    virtual void TargetFOVUpdated() = 0;
    virtual float& DegreesPerSecond() = 0;
    virtual void DegreesPerSecondUpdated() = 0;
    virtual bool& IsOn() = 0;
    virtual void IsOnUpdated() = 0;
    virtual CPointCamera*& Next() = 0;
    virtual void NextUpdated() = 0;
    static IPointCamera* FromOriginal(CPointCamera* p);
};

#endif // _INCLUDE_IPOINTCAMERA_H
