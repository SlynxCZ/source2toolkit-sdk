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

#ifndef _INCLUDE_ITEXTUREBASEDANIMATABLE_H
#define _INCLUDE_ITEXTUREBASEDANIMATABLE_H

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

class CTextureBasedAnimatable;
class InfoForResourceTypeCTextureBase;

class ITextureBasedAnimatable : public virtual IBaseModelEntity
{
public:
    virtual ~ITextureBasedAnimatable() = default;

    virtual bool& Loop() = 0;
    virtual void LoopUpdated() = 0;
    virtual float& FPS() = 0;
    virtual void FPSUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& PositionKeys() = 0;
    virtual void PositionKeysUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& RotationKeys() = 0;
    virtual void RotationKeysUpdated() = 0;
    virtual Vector& AnimationBoundsMin() = 0;
    virtual void AnimationBoundsMinUpdated() = 0;
    virtual Vector& AnimationBoundsMax() = 0;
    virtual void AnimationBoundsMaxUpdated() = 0;
    virtual float& StartTime() = 0;
    virtual void StartTimeUpdated() = 0;
    virtual float& StartFrame() = 0;
    virtual void StartFrameUpdated() = 0;
    static ITextureBasedAnimatable* FromOriginal(CTextureBasedAnimatable* p);
    static ITextureBasedAnimatable* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_ITEXTUREBASEDANIMATABLE_H
