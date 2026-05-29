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

#ifndef _INCLUDE_IBASEPLAYERPAWN_H
#define _INCLUDE_IBASEPLAYERPAWN_H

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

#include "IBaseCombatCharacter.h"

class CAI_Expresser;
class CBasePlayerController;
class CBasePlayerPawn;
class CBasePlayerWeapon;
class CPlayer_AutoaimServices;
class CPlayer_CameraServices;
class CPlayer_FlashlightServices;
class CPlayer_ItemServices;
class CPlayer_MovementServices;
class CPlayer_ObserverServices;
class CPlayer_UseServices;
class CPlayer_WaterServices;
class CPlayer_WeaponServices;
class IBasePlayerWeapon;
class ViewAngleServerChange_t;
class sky3dparams_t;
class sndopvarlatchdata_t;

class IBasePlayerPawn : public virtual IBaseCombatCharacter
{
public:
    virtual ~IBasePlayerPawn() = default;

    virtual CPlayer_WeaponServices*& WeaponServices() = 0;
    virtual void WeaponServicesUpdated() = 0;
    virtual CPlayer_ItemServices*& ItemServices() = 0;
    virtual void ItemServicesUpdated() = 0;
    virtual CPlayer_AutoaimServices*& AutoaimServices() = 0;
    virtual void AutoaimServicesUpdated() = 0;
    virtual CPlayer_ObserverServices*& ObserverServices() = 0;
    virtual void ObserverServicesUpdated() = 0;
    virtual CPlayer_WaterServices*& WaterServices() = 0;
    virtual void WaterServicesUpdated() = 0;
    virtual CPlayer_UseServices*& UseServices() = 0;
    virtual void UseServicesUpdated() = 0;
    virtual CPlayer_FlashlightServices*& FlashlightServices() = 0;
    virtual void FlashlightServicesUpdated() = 0;
    virtual CPlayer_CameraServices*& CameraServices() = 0;
    virtual void CameraServicesUpdated() = 0;
    virtual CPlayer_MovementServices*& MovementServices() = 0;
    virtual void MovementServicesUpdated() = 0;
    virtual CUtlVector<ViewAngleServerChange_t>& ServerViewAngleChanges() = 0;
    virtual void ServerViewAngleChangesUpdated() = 0;
    virtual QAngle& V_angle() = 0;
    virtual void V_angleUpdated() = 0;
    virtual QAngle& V_anglePrevious() = 0;
    virtual void V_anglePreviousUpdated() = 0;
    virtual uint32_t& HideHUD() = 0;
    virtual void HideHUDUpdated() = 0;
    virtual ::sky3dparams_t& Skybox3d() = 0;
    virtual void Skybox3dUpdated() = 0;
    virtual float& TimeLastHurt() = 0;
    virtual void TimeLastHurtUpdated() = 0;
    virtual float& DeathTime() = 0;
    virtual void DeathTimeUpdated() = 0;
    virtual float& NextSuicideTime() = 0;
    virtual void NextSuicideTimeUpdated() = 0;
    virtual bool& InitHUD() = 0;
    virtual void InitHUDUpdated() = 0;
    virtual CAI_Expresser*& Expresser() = 0;
    virtual void ExpresserUpdated() = 0;
    virtual CHandle<CBasePlayerController>& Controller() = 0;
    virtual void ControllerUpdated() = 0;
    virtual CHandle<CBasePlayerController>& DefaultController() = 0;
    virtual void DefaultControllerUpdated() = 0;
    virtual float& HltvReplayDelay() = 0;
    virtual void HltvReplayDelayUpdated() = 0;
    virtual float& HltvReplayEnd() = 0;
    virtual void HltvReplayEndUpdated() = 0;
    virtual CEntityIndex& HltvReplayEntity() = 0;
    virtual void HltvReplayEntityUpdated() = 0;
    virtual CUtlVector<sndopvarlatchdata_t>& SndOpvarLatchData() = 0;
    virtual void SndOpvarLatchDataUpdated() = 0;

    /// <summary>Force suicide.</summary>
    virtual void CommitSuicide(bool bExplode, bool bForce) = 0;
    /// <summary>Remove weapon from player.</summary>
    virtual void RemovePlayerItem(IBasePlayerWeapon* pWeapon) = 0;
    static IBasePlayerPawn* FromOriginal(CBasePlayerPawn* p);
    static IBasePlayerPawn* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IBASEPLAYERPAWN_H
