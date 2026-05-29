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

#ifndef _INCLUDE_IENVSKY_H
#define _INCLUDE_IENVSKY_H

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

class CEnvSky;
class InfoForResourceTypeIMaterial2;

class IEnvSky : public virtual IBaseModelEntity
{
public:
    virtual ~IEnvSky() = default;

    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& SkyMaterial() = 0;
    virtual void SkyMaterialUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& SkyMaterialLightingOnly() = 0;
    virtual void SkyMaterialLightingOnlyUpdated() = 0;
    virtual bool& StartDisabled() = 0;
    virtual void StartDisabledUpdated() = 0;
    virtual Color& TintColor() = 0;
    virtual void TintColorUpdated() = 0;
    virtual Color& TintColorLightingOnly() = 0;
    virtual void TintColorLightingOnlyUpdated() = 0;
    virtual float& BrightnessScale() = 0;
    virtual void BrightnessScaleUpdated() = 0;
    virtual int32_t& FogType() = 0;
    virtual void FogTypeUpdated() = 0;
    virtual float& FogMinStart() = 0;
    virtual void FogMinStartUpdated() = 0;
    virtual float& FogMinEnd() = 0;
    virtual void FogMinEndUpdated() = 0;
    virtual float& FogMaxStart() = 0;
    virtual void FogMaxStartUpdated() = 0;
    virtual float& FogMaxEnd() = 0;
    virtual void FogMaxEndUpdated() = 0;
    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    static IEnvSky* FromOriginal(CEnvSky* p);
    static IEnvSky* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IENVSKY_H
