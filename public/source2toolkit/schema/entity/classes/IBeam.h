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

#ifndef _INCLUDE_IBEAM_H
#define _INCLUDE_IBEAM_H

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

#include "../enums/BeamClipStyle_t.h"
#include "../enums/BeamType_t.h"

class CBaseEntity;
class CBeam;
class InfoForResourceTypeIMaterial2;

class IBeam : public virtual IBaseModelEntity
{
public:
    virtual ~IBeam() = default;

    virtual float& FrameRate() = 0;
    virtual void FrameRateUpdated() = 0;
    virtual float& HDRColorScale() = 0;
    virtual void HDRColorScaleUpdated() = 0;
    virtual float& FireTime() = 0;
    virtual void FireTimeUpdated() = 0;
    virtual float& Damage() = 0;
    virtual void DamageUpdated() = 0;
    virtual uint8_t& NumBeamEnts() = 0;
    virtual void NumBeamEntsUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& BaseMaterial() = 0;
    virtual void BaseMaterialUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIMaterial2>& HaloIndex() = 0;
    virtual void HaloIndexUpdated() = 0;
    virtual ::BeamType_t& BeamType() = 0;
    virtual void BeamTypeUpdated() = 0;
    virtual uint32_t& BeamFlags() = 0;
    virtual void BeamFlagsUpdated() = 0;
    virtual CHandle<CBaseEntity>* AttachEntity() = 0;
    virtual float& Width() = 0;
    virtual void WidthUpdated() = 0;
    virtual float& EndWidth() = 0;
    virtual void EndWidthUpdated() = 0;
    virtual float& FadeLength() = 0;
    virtual void FadeLengthUpdated() = 0;
    virtual float& HaloScale() = 0;
    virtual void HaloScaleUpdated() = 0;
    virtual float& Amplitude() = 0;
    virtual void AmplitudeUpdated() = 0;
    virtual float& StartFrame() = 0;
    virtual void StartFrameUpdated() = 0;
    virtual float& Speed() = 0;
    virtual void SpeedUpdated() = 0;
    virtual float& Frame() = 0;
    virtual void FrameUpdated() = 0;
    virtual ::BeamClipStyle_t& ClipStyle() = 0;
    virtual void ClipStyleUpdated() = 0;
    virtual bool& TurnedOff() = 0;
    virtual void TurnedOffUpdated() = 0;
    virtual Vector& EndPos() = 0;
    virtual void EndPosUpdated() = 0;
    virtual CHandle<CBaseEntity>& EndEntity() = 0;
    virtual void EndEntityUpdated() = 0;
    virtual int32_t& DissolveType() = 0;
    virtual void DissolveTypeUpdated() = 0;
    static IBeam* FromOriginal(CBeam* p);
    static IBeam* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IBEAM_H
