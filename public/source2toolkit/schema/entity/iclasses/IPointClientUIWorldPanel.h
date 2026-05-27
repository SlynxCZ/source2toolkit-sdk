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

#ifndef _INCLUDE_IPOINTCLIENTUIWORLDPANEL_H
#define _INCLUDE_IPOINTCLIENTUIWORLDPANEL_H

#pragma once

#include <cstdint>

#include "IBaseClientUIEntity.h"

class IPointClientUIWorldPanel : public virtual IBaseClientUIEntity
{
public:
    virtual ~IPointClientUIWorldPanel() = default;

    virtual bool& IgnoreInput() = 0;
    virtual void IgnoreInputUpdated() = 0;
    virtual bool& Lit() = 0;
    virtual void LitUpdated() = 0;
    virtual bool& FollowPlayerAcrossTeleport() = 0;
    virtual void FollowPlayerAcrossTeleportUpdated() = 0;
    virtual float& Width() = 0;
    virtual void WidthUpdated() = 0;
    virtual float& Height() = 0;
    virtual void HeightUpdated() = 0;
    virtual float& DPI() = 0;
    virtual void DPIUpdated() = 0;
    virtual float& InteractDistance() = 0;
    virtual void InteractDistanceUpdated() = 0;
    virtual float& DepthOffset() = 0;
    virtual void DepthOffsetUpdated() = 0;
    virtual uint32_t& OwnerContext() = 0;
    virtual void OwnerContextUpdated() = 0;
    virtual uint32_t& HorizontalAlign() = 0;
    virtual void HorizontalAlignUpdated() = 0;
    virtual uint32_t& VerticalAlign() = 0;
    virtual void VerticalAlignUpdated() = 0;
    virtual uint32_t& Orientation() = 0;
    virtual void OrientationUpdated() = 0;
    virtual bool& AllowInteractionFromAllSceneWorlds() = 0;
    virtual void AllowInteractionFromAllSceneWorldsUpdated() = 0;
    virtual CUtlVector<CUtlSymbolLarge>& CSSClasses() = 0;
    virtual void CSSClassesUpdated() = 0;
    virtual bool& Opaque() = 0;
    virtual void OpaqueUpdated() = 0;
    virtual bool& NoDepth() = 0;
    virtual void NoDepthUpdated() = 0;
    virtual bool& VisibleWhenParentNoDraw() = 0;
    virtual void VisibleWhenParentNoDrawUpdated() = 0;
    virtual bool& RenderBackface() = 0;
    virtual void RenderBackfaceUpdated() = 0;
    virtual bool& UseOffScreenIndicator() = 0;
    virtual void UseOffScreenIndicatorUpdated() = 0;
    virtual bool& ExcludeFromSaveGames() = 0;
    virtual void ExcludeFromSaveGamesUpdated() = 0;
    virtual bool& Grabbable() = 0;
    virtual void GrabbableUpdated() = 0;
    virtual bool& OnlyRenderToTexture() = 0;
    virtual void OnlyRenderToTextureUpdated() = 0;
    virtual bool& DisableMipGen() = 0;
    virtual void DisableMipGenUpdated() = 0;
    virtual int32_t& ExplicitImageLayout() = 0;
    virtual void ExplicitImageLayoutUpdated() = 0;
};

#endif // _INCLUDE_IPOINTCLIENTUIWORLDPANEL_H
