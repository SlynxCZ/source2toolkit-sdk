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

#ifndef _INCLUDE_ICSWEAPONBASE_H
#define _INCLUDE_ICSWEAPONBASE_H

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

#include "IBasePlayerWeapon.h"

#include "../enums/CSWeaponMode.h"
#include "../enums/WeaponGameplayAnimState.h"

class CCSPlayerPawn;
class CCSWeaponBase;
class CIronSightController;

class ICSWeaponBase : public virtual IBasePlayerWeapon
{
public:
    virtual ~ICSWeaponBase() = default;
    CCSWeaponBase* GetOriginal() { return reinterpret_cast<CCSWeaponBase*>(IEntityInstance::GetOriginal()); }

    virtual bool& Removeable() = 0;
    virtual void RemoveableUpdated() = 0;
    virtual bool& PlayerAmmoStockOnPickup() = 0;
    virtual void PlayerAmmoStockOnPickupUpdated() = 0;
    virtual bool& RequireUseToTouch() = 0;
    virtual void RequireUseToTouchUpdated() = 0;
    virtual ::WeaponGameplayAnimState& WeaponGameplayAnimState() = 0;
    virtual void WeaponGameplayAnimStateUpdated() = 0;
    virtual float& WeaponGameplayAnimStateTimestamp() = 0;
    virtual void WeaponGameplayAnimStateTimestampUpdated() = 0;
    virtual float& InspectCancelCompleteTime() = 0;
    virtual void InspectCancelCompleteTimeUpdated() = 0;
    virtual bool& InspectPending() = 0;
    virtual void InspectPendingUpdated() = 0;
    virtual bool& InspectShouldLoop() = 0;
    virtual void InspectShouldLoopUpdated() = 0;
    virtual int32_t& LastEmptySoundCmdNum() = 0;
    virtual void LastEmptySoundCmdNumUpdated() = 0;
    virtual bool& FireOnEmpty() = 0;
    virtual void FireOnEmptyUpdated() = 0;
    virtual ::CEntityIOOutput& OnPlayerPickup() = 0;
    virtual void OnPlayerPickupUpdated() = 0;
    virtual ::CSWeaponMode& WeaponMode() = 0;
    virtual void WeaponModeUpdated() = 0;
    virtual float& TurningInaccuracyDelta() = 0;
    virtual void TurningInaccuracyDeltaUpdated() = 0;
    virtual Vector& TurningInaccuracyEyeDirLast() = 0;
    virtual void TurningInaccuracyEyeDirLastUpdated() = 0;
    virtual float& TurningInaccuracy() = 0;
    virtual void TurningInaccuracyUpdated() = 0;
    virtual float& AccuracyPenalty() = 0;
    virtual void AccuracyPenaltyUpdated() = 0;
    virtual float& LastAccuracyUpdateTime() = 0;
    virtual void LastAccuracyUpdateTimeUpdated() = 0;
    virtual float& AccuracySmoothedForZoom() = 0;
    virtual void AccuracySmoothedForZoomUpdated() = 0;
    virtual int32_t& RecoilIndex() = 0;
    virtual void RecoilIndexUpdated() = 0;
    virtual float& RecoilIndex() = 0;
    virtual void RecoilIndexUpdated() = 0;
    virtual bool& BurstMode() = 0;
    virtual void BurstModeUpdated() = 0;
    virtual int32_t& PostponeFireReadyTicks() = 0;
    virtual void PostponeFireReadyTicksUpdated() = 0;
    virtual float& PostponeFireReadyFrac() = 0;
    virtual void PostponeFireReadyFracUpdated() = 0;
    virtual bool& InReload() = 0;
    virtual void InReloadUpdated() = 0;
    virtual int32_t& DeployTick() = 0;
    virtual void DeployTickUpdated() = 0;
    virtual float& DroppedAtTime() = 0;
    virtual void DroppedAtTimeUpdated() = 0;
    virtual bool& IsHauledBack() = 0;
    virtual void IsHauledBackUpdated() = 0;
    virtual bool& SilencerOn() = 0;
    virtual void SilencerOnUpdated() = 0;
    virtual float& TimeSilencerSwitchComplete() = 0;
    virtual void TimeSilencerSwitchCompleteUpdated() = 0;
    virtual float& WeaponActionPlaybackRate() = 0;
    virtual void WeaponActionPlaybackRateUpdated() = 0;
    virtual int32_t& OriginalTeamNumber() = 0;
    virtual void OriginalTeamNumberUpdated() = 0;
    virtual int32_t& MostRecentTeamNumber() = 0;
    virtual void MostRecentTeamNumberUpdated() = 0;
    virtual bool& DroppedNearBuyZone() = 0;
    virtual void DroppedNearBuyZoneUpdated() = 0;
    virtual float& NextAttackRenderTimeOffset() = 0;
    virtual void NextAttackRenderTimeOffsetUpdated() = 0;
    virtual bool& CanBePickedUp() = 0;
    virtual void CanBePickedUpUpdated() = 0;
    virtual bool& UseCanOverrideNextOwnerTouchTime() = 0;
    virtual void UseCanOverrideNextOwnerTouchTimeUpdated() = 0;
    virtual float& NextOwnerTouchTime() = 0;
    virtual void NextOwnerTouchTimeUpdated() = 0;
    virtual float& NextPrevOwnerTouchTime() = 0;
    virtual void NextPrevOwnerTouchTimeUpdated() = 0;
    virtual float& NextPrevOwnerUseTime() = 0;
    virtual void NextPrevOwnerUseTimeUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& PrevOwner() = 0;
    virtual void PrevOwnerUpdated() = 0;
    virtual int32_t& DropTick() = 0;
    virtual void DropTickUpdated() = 0;
    virtual bool& WasActiveWeaponWhenDropped() = 0;
    virtual void WasActiveWeaponWhenDroppedUpdated() = 0;
    virtual bool& Donated() = 0;
    virtual void DonatedUpdated() = 0;
    virtual float& LastShotTime() = 0;
    virtual void LastShotTimeUpdated() = 0;
    virtual bool& WasOwnedByCT() = 0;
    virtual void WasOwnedByCTUpdated() = 0;
    virtual bool& WasOwnedByTerrorist() = 0;
    virtual void WasOwnedByTerroristUpdated() = 0;
    virtual int32_t& NumRemoveUnownedWeaponThink() = 0;
    virtual void NumRemoveUnownedWeaponThinkUpdated() = 0;
    virtual ::CIronSightController& IronSightController() = 0;
    virtual void IronSightControllerUpdated() = 0;
    virtual int32_t& IronSightMode() = 0;
    virtual void IronSightModeUpdated() = 0;
    virtual float& LastLOSTraceFailureTime() = 0;
    virtual void LastLOSTraceFailureTimeUpdated() = 0;
    virtual float& WatTickOffset() = 0;
    virtual void WatTickOffsetUpdated() = 0;
    virtual float& LastShakeTime() = 0;
    virtual void LastShakeTimeUpdated() = 0;
    static ICSWeaponBase* FromOriginal(CCSWeaponBase* p);
};

#endif // _INCLUDE_ICSWEAPONBASE_H
