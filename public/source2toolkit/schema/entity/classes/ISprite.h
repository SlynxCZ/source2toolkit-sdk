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

#ifndef _INCLUDE_ISPRITE_H
#define _INCLUDE_ISPRITE_H

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

class CBaseEntity;
class CSprite;
class InfoForResourceTypeIMaterial2;

class ISprite : public virtual IBaseModelEntity
{
public:
    virtual ~ISprite() = default;
    CSprite* GetOriginal() { return reinterpret_cast<CSprite*>(IEntityInstance::GetOriginal()); }

    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& SpriteMaterial() = 0;
    virtual void SpriteMaterialUpdated() = 0;
    virtual CHandle<CBaseEntity>& AttachedToEntity() = 0;
    virtual void AttachedToEntityUpdated() = 0;
    virtual float& SpriteFramerate() = 0;
    virtual void SpriteFramerateUpdated() = 0;
    virtual float& Frame() = 0;
    virtual void FrameUpdated() = 0;
    virtual float& DieTime() = 0;
    virtual void DieTimeUpdated() = 0;
    virtual uint32_t& Brightness() = 0;
    virtual void BrightnessUpdated() = 0;
    virtual float& BrightnessDuration() = 0;
    virtual void BrightnessDurationUpdated() = 0;
    virtual float& SpriteScale() = 0;
    virtual void SpriteScaleUpdated() = 0;
    virtual float& ScaleDuration() = 0;
    virtual void ScaleDurationUpdated() = 0;
    virtual bool& WorldSpaceScale() = 0;
    virtual void WorldSpaceScaleUpdated() = 0;
    virtual float& GlowProxySize() = 0;
    virtual void GlowProxySizeUpdated() = 0;
    virtual float& HDRColorScale() = 0;
    virtual void HDRColorScaleUpdated() = 0;
    virtual float& LastTime() = 0;
    virtual void LastTimeUpdated() = 0;
    virtual float& MaxFrame() = 0;
    virtual void MaxFrameUpdated() = 0;
    virtual float& StartScale() = 0;
    virtual void StartScaleUpdated() = 0;
    virtual float& DestScale() = 0;
    virtual void DestScaleUpdated() = 0;
    virtual float& ScaleTimeStart() = 0;
    virtual void ScaleTimeStartUpdated() = 0;
    virtual int32_t& StartBrightness() = 0;
    virtual void StartBrightnessUpdated() = 0;
    virtual int32_t& DestBrightness() = 0;
    virtual void DestBrightnessUpdated() = 0;
    virtual float& BrightnessTimeStart() = 0;
    virtual void BrightnessTimeStartUpdated() = 0;
    virtual int32_t& SpriteWidth() = 0;
    virtual void SpriteWidthUpdated() = 0;
    virtual int32_t& SpriteHeight() = 0;
    virtual void SpriteHeightUpdated() = 0;
    static ISprite* FromOriginal(CSprite* p);
};

#endif // _INCLUDE_ISPRITE_H
