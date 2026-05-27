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

#ifndef _INCLUDE_IPOINTWORLDTEXT_H
#define _INCLUDE_IPOINTWORLDTEXT_H

#pragma once

#include <cstdint>

#include "IModelPointEntity.h"

#include "../enums/PointWorldTextJustifyHorizontal_t.h"
#include "../enums/PointWorldTextJustifyVertical_t.h"
#include "../enums/PointWorldTextReorientMode_t.h"

class IPointWorldText : public virtual IModelPointEntity
{
public:
    virtual ~IPointWorldText() = default;

    virtual char* MessageText() = 0;
    virtual char* FontName() = 0;
    virtual char* BackgroundMaterialName() = 0;
    virtual bool& Enabled() = 0;
    virtual void EnabledUpdated() = 0;
    virtual bool& Fullbright() = 0;
    virtual void FullbrightUpdated() = 0;
    virtual float& WorldUnitsPerPx() = 0;
    virtual void WorldUnitsPerPxUpdated() = 0;
    virtual float& FontSize() = 0;
    virtual void FontSizeUpdated() = 0;
    virtual float& DepthOffset() = 0;
    virtual void DepthOffsetUpdated() = 0;
    virtual bool& DrawBackground() = 0;
    virtual void DrawBackgroundUpdated() = 0;
    virtual float& BackgroundBorderWidth() = 0;
    virtual void BackgroundBorderWidthUpdated() = 0;
    virtual float& BackgroundBorderHeight() = 0;
    virtual void BackgroundBorderHeightUpdated() = 0;
    virtual float& BackgroundWorldToUV() = 0;
    virtual void BackgroundWorldToUVUpdated() = 0;
    virtual Color& Color() = 0;
    virtual void ColorUpdated() = 0;
    virtual PointWorldTextJustifyHorizontal_t& JustifyHorizontal() = 0;
    virtual void JustifyHorizontalUpdated() = 0;
    virtual PointWorldTextJustifyVertical_t& JustifyVertical() = 0;
    virtual void JustifyVerticalUpdated() = 0;
    virtual PointWorldTextReorientMode_t& ReorientMode() = 0;
    virtual void ReorientModeUpdated() = 0;
};

#endif // _INCLUDE_IPOINTWORLDTEXT_H
