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

#ifndef _INCLUDE_IPRECIPITATIONVDATA_H
#define _INCLUDE_IPRECIPITATIONVDATA_H

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

#include "IEntitySubclassVDataBase.h"

#include "../enums/ParticleAttachment_t.h"

class PrecipitationFilter_t;

class IPrecipitationVData : public virtual IEntitySubclassVDataBase
{
public:
    virtual ~IPrecipitationVData() = default;

    virtual float& InnerDistance() = 0;
    virtual void InnerDistanceUpdated() = 0;
    virtual ParticleAttachment_t& AttachType() = 0;
    virtual void AttachTypeUpdated() = 0;
    virtual bool& BatchSameVolumeType() = 0;
    virtual void BatchSameVolumeTypeUpdated() = 0;
    virtual int32_t& RTEnvCP() = 0;
    virtual void RTEnvCPUpdated() = 0;
    virtual int32_t& RTEnvCPComponent() = 0;
    virtual void RTEnvCPComponentUpdated() = 0;
    virtual CUtlString& Modifier() = 0;
    virtual void ModifierUpdated() = 0;
    virtual int32_t& UseSnapshotFromSurfaceGraph() = 0;
    virtual void UseSnapshotFromSurfaceGraphUpdated() = 0;
    virtual PrecipitationFilter_t& SnapshotFilter() = 0;
    virtual void SnapshotFilterUpdated() = 0;
};

#endif // _INCLUDE_IPRECIPITATIONVDATA_H
