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

#ifndef _INCLUDE_IENVBEAM_H
#define _INCLUDE_IENVBEAM_H

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

#include "IBeam.h"

#include "../enums/Touch_t.h"

class CBaseEntity;
class CEnvBeam;
class InfoForResourceTypeIMaterial2;

class IEnvBeam : public virtual IBeam
{
public:
    virtual ~IEnvBeam() = default;

    virtual int32_t& Active() = 0;
    virtual void ActiveUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& SpriteTexture() = 0;
    virtual void SpriteTextureUpdated() = 0;
    virtual CUtlSymbolLarge& StartEntity() = 0;
    virtual void StartEntityUpdated() = 0;
    virtual CUtlSymbolLarge& EndEntity() = 0;
    virtual void EndEntityUpdated() = 0;
    virtual float& Life() = 0;
    virtual void LifeUpdated() = 0;
    virtual float& BoltWidth() = 0;
    virtual void BoltWidthUpdated() = 0;
    virtual float& NoiseAmplitude() = 0;
    virtual void NoiseAmplitudeUpdated() = 0;
    virtual int32_t& Speed() = 0;
    virtual void SpeedUpdated() = 0;
    virtual float& Restrike() = 0;
    virtual void RestrikeUpdated() = 0;
    virtual CUtlSymbolLarge& SpriteName() = 0;
    virtual void SpriteNameUpdated() = 0;
    virtual int32_t& FrameStart() = 0;
    virtual void FrameStartUpdated() = 0;
    virtual Vector& EndPointWorld() = 0;
    virtual void EndPointWorldUpdated() = 0;
    virtual Vector& EndPointRelative() = 0;
    virtual void EndPointRelativeUpdated() = 0;
    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual ::Touch_t& TouchType() = 0;
    virtual void TouchTypeUpdated() = 0;
    virtual CUtlSymbolLarge& FilterName() = 0;
    virtual void FilterNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& Filter() = 0;
    virtual void FilterUpdated() = 0;
    virtual CUtlSymbolLarge& Decal() = 0;
    virtual void DecalUpdated() = 0;
    virtual ::CEntityIOOutput& OnTouchedByEntity() = 0;
    virtual void OnTouchedByEntityUpdated() = 0;
    static IEnvBeam* FromOriginal(CEnvBeam* p);
    static IEnvBeam* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IENVBEAM_H
