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

#ifndef _INCLUDE_IPATHPARTICLEROPE_H
#define _INCLUDE_IPATHPARTICLEROPE_H

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

class CPathParticleRope;
class InfoForResourceTypeIParticleSystemDefinition;

class IPathParticleRope : public virtual IBaseEntity
{
public:
    virtual ~IPathParticleRope() = default;

    virtual bool& StartActive() = 0;
    virtual void StartActiveUpdated() = 0;
    virtual float& MaxSimulationTime() = 0;
    virtual void MaxSimulationTimeUpdated() = 0;
    virtual CUtlSymbolLarge& EffectName() = 0;
    virtual void EffectNameUpdated() = 0;
    virtual CUtlVector<CUtlSymbolLarge>& PathNodes_Name() = 0;
    virtual void PathNodes_NameUpdated() = 0;
    virtual float& ParticleSpacing() = 0;
    virtual void ParticleSpacingUpdated() = 0;
    virtual float& Slack() = 0;
    virtual void SlackUpdated() = 0;
    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual Color& ColorTint() = 0;
    virtual void ColorTintUpdated() = 0;
    virtual int32_t& EffectState() = 0;
    virtual void EffectStateUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>& EffectIndex() = 0;
    virtual void EffectIndexUpdated() = 0;
    virtual CUtlVector<Vector>& PathNodes_Position() = 0;
    virtual void PathNodes_PositionUpdated() = 0;
    virtual CUtlVector<Vector>& PathNodes_TangentIn() = 0;
    virtual void PathNodes_TangentInUpdated() = 0;
    virtual CUtlVector<Vector>& PathNodes_TangentOut() = 0;
    virtual void PathNodes_TangentOutUpdated() = 0;
    virtual CUtlVector<Vector>& PathNodes_Color() = 0;
    virtual void PathNodes_ColorUpdated() = 0;
    virtual CUtlVector<bool>& PathNodes_PinEnabled() = 0;
    virtual void PathNodes_PinEnabledUpdated() = 0;
    virtual CUtlVector<float>& PathNodes_RadiusScale() = 0;
    virtual void PathNodes_RadiusScaleUpdated() = 0;
    static IPathParticleRope* FromOriginal(CPathParticleRope* p);
};

#endif // _INCLUDE_IPATHPARTICLEROPE_H
