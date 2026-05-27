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

#ifndef _INCLUDE_ISOUNDOPVARSETPOINTENTITY_H
#define _INCLUDE_ISOUNDOPVARSETPOINTENTITY_H

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

#include "ISoundOpvarSetPointBase.h"

class ISoundOpvarSetPointEntity : public virtual ISoundOpvarSetPointBase
{
public:
    virtual ~ISoundOpvarSetPointEntity() = default;

    virtual CEntityIOOutput& OnEnter() = 0;
    virtual void OnEnterUpdated() = 0;
    virtual CEntityIOOutput& OnExit() = 0;
    virtual void OnExitUpdated() = 0;
    virtual bool& AutoDisable() = 0;
    virtual void AutoDisableUpdated() = 0;
    virtual float& DistanceMin() = 0;
    virtual void DistanceMinUpdated() = 0;
    virtual float& DistanceMax() = 0;
    virtual void DistanceMaxUpdated() = 0;
    virtual float& DistanceMapMin() = 0;
    virtual void DistanceMapMinUpdated() = 0;
    virtual float& DistanceMapMax() = 0;
    virtual void DistanceMapMaxUpdated() = 0;
    virtual float& OcclusionRadius() = 0;
    virtual void OcclusionRadiusUpdated() = 0;
    virtual float& OcclusionMin() = 0;
    virtual void OcclusionMinUpdated() = 0;
    virtual float& OcclusionMax() = 0;
    virtual void OcclusionMaxUpdated() = 0;
    virtual float& ValSetOnDisable() = 0;
    virtual void ValSetOnDisableUpdated() = 0;
    virtual bool& SetValueOnDisable() = 0;
    virtual void SetValueOnDisableUpdated() = 0;
    virtual bool& Reloading() = 0;
    virtual void ReloadingUpdated() = 0;
    virtual int32_t& SimulationMode() = 0;
    virtual void SimulationModeUpdated() = 0;
    virtual int32_t& VisibilitySamples() = 0;
    virtual void VisibilitySamplesUpdated() = 0;
    virtual Vector& DynamicProxyPoint() = 0;
    virtual void DynamicProxyPointUpdated() = 0;
    virtual float& DynamicMaximumOcclusion() = 0;
    virtual void DynamicMaximumOcclusionUpdated() = 0;
    virtual CEntityHandle& DynamicEntity() = 0;
    virtual void DynamicEntityUpdated() = 0;
    virtual CUtlSymbolLarge& DynamicEntityName() = 0;
    virtual void DynamicEntityNameUpdated() = 0;
    virtual float& PathingDistanceNormFactor() = 0;
    virtual void PathingDistanceNormFactorUpdated() = 0;
    virtual Vector& PathingSourcePos() = 0;
    virtual void PathingSourcePosUpdated() = 0;
    virtual Vector& PathingListenerPos() = 0;
    virtual void PathingListenerPosUpdated() = 0;
    virtual Vector& PathingDirection() = 0;
    virtual void PathingDirectionUpdated() = 0;
    virtual int32_t& PathingSourceIndex() = 0;
    virtual void PathingSourceIndexUpdated() = 0;
};

#endif // _INCLUDE_ISOUNDOPVARSETPOINTENTITY_H
