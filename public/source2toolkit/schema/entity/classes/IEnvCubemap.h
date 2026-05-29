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

#ifndef _INCLUDE_IENVCUBEMAP_H
#define _INCLUDE_IENVCUBEMAP_H

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

class CEnvCubemap;
class InfoForResourceTypeCTextureBase;

class IEnvCubemap : public virtual IBaseEntity
{
public:
    virtual ~IEnvCubemap() = default;

    virtual CStrongHandle<InfoForResourceTypeCTextureBase>& Entity_hCubemapTexture() = 0;
    virtual void Entity_hCubemapTextureUpdated() = 0;
    virtual bool& Entity_bCustomCubemapTexture() = 0;
    virtual void Entity_bCustomCubemapTextureUpdated() = 0;
    virtual float& Entity_flInfluenceRadius() = 0;
    virtual void Entity_flInfluenceRadiusUpdated() = 0;
    virtual Vector& Entity_vBoxProjectMins() = 0;
    virtual void Entity_vBoxProjectMinsUpdated() = 0;
    virtual Vector& Entity_vBoxProjectMaxs() = 0;
    virtual void Entity_vBoxProjectMaxsUpdated() = 0;
    virtual bool& Entity_bMoveable() = 0;
    virtual void Entity_bMoveableUpdated() = 0;
    virtual int32_t& Entity_nHandshake() = 0;
    virtual void Entity_nHandshakeUpdated() = 0;
    virtual int32_t& Entity_nEnvCubeMapArrayIndex() = 0;
    virtual void Entity_nEnvCubeMapArrayIndexUpdated() = 0;
    virtual int32_t& Entity_nPriority() = 0;
    virtual void Entity_nPriorityUpdated() = 0;
    virtual float& Entity_flEdgeFadeDist() = 0;
    virtual void Entity_flEdgeFadeDistUpdated() = 0;
    virtual Vector& Entity_vEdgeFadeDists() = 0;
    virtual void Entity_vEdgeFadeDistsUpdated() = 0;
    virtual float& Entity_flDiffuseScale() = 0;
    virtual void Entity_flDiffuseScaleUpdated() = 0;
    virtual bool& Entity_bStartDisabled() = 0;
    virtual void Entity_bStartDisabledUpdated() = 0;
    virtual bool& Entity_bDefaultEnvMap() = 0;
    virtual void Entity_bDefaultEnvMapUpdated() = 0;
    virtual bool& Entity_bDefaultSpecEnvMap() = 0;
    virtual void Entity_bDefaultSpecEnvMapUpdated() = 0;
    virtual bool& Entity_bIndoorCubeMap() = 0;
    virtual void Entity_bIndoorCubeMapUpdated() = 0;
    virtual bool& Entity_bCopyDiffuseFromDefaultCubemap() = 0;
    virtual void Entity_bCopyDiffuseFromDefaultCubemapUpdated() = 0;
    virtual bool& Entity_bEnabled() = 0;
    virtual void Entity_bEnabledUpdated() = 0;
    static IEnvCubemap* FromOriginal(CEnvCubemap* p);
    static IEnvCubemap* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IENVCUBEMAP_H
