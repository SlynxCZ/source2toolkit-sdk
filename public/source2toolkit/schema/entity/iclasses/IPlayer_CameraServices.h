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

#ifndef _INCLUDE_IPLAYER_CAMERASERVICES_H
#define _INCLUDE_IPLAYER_CAMERASERVICES_H

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

#include "IPlayerPawnComponent.h"

class CBaseEntity;
class CColorCorrection;
class CEnvSoundscapeTriggerable;
class CPostProcessingVolume;
class CTonemapController2;
class audioparams_t;
class fogplayerparams_t;

class IPlayer_CameraServices : public virtual IPlayerPawnComponent
{
public:
    virtual ~IPlayer_CameraServices() = default;

    virtual QAngle& CsViewPunchAngle() = 0;
    virtual void CsViewPunchAngleUpdated() = 0;
    virtual int32_t& CsViewPunchAngleTick() = 0;
    virtual void CsViewPunchAngleTickUpdated() = 0;
    virtual float& CsViewPunchAngleTickRatio() = 0;
    virtual void CsViewPunchAngleTickRatioUpdated() = 0;
    virtual fogplayerparams_t& PlayerFog() = 0;
    virtual void PlayerFogUpdated() = 0;
    virtual CHandle<CColorCorrection>& ColorCorrectionCtrl() = 0;
    virtual void ColorCorrectionCtrlUpdated() = 0;
    virtual CHandle<CBaseEntity>& ViewEntity() = 0;
    virtual void ViewEntityUpdated() = 0;
    virtual CHandle<CTonemapController2>& TonemapController() = 0;
    virtual void TonemapControllerUpdated() = 0;
    virtual audioparams_t& Audio() = 0;
    virtual void AudioUpdated() = 0;
    virtual CUtlVector<CHandle<CPostProcessingVolume>>& PostProcessingVolumes() = 0;
    virtual void PostProcessingVolumesUpdated() = 0;
    virtual float& OldPlayerZ() = 0;
    virtual void OldPlayerZUpdated() = 0;
    virtual float& OldPlayerViewOffsetZ() = 0;
    virtual void OldPlayerViewOffsetZUpdated() = 0;
    virtual CUtlVector<CHandle<CEnvSoundscapeTriggerable>>& TriggerSoundscapeList() = 0;
    virtual void TriggerSoundscapeListUpdated() = 0;
};

#endif // _INCLUDE_IPLAYER_CAMERASERVICES_H
