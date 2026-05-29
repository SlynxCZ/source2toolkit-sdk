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

#ifndef _INCLUDE_IBASEPROPDOOR_H
#define _INCLUDE_IBASEPROPDOOR_H

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

#include "IDynamicProp.h"

#include "../enums/DoorState_t.h"

class CBaseEntity;
class CBasePropDoor;
class locksound_t;

class IBasePropDoor : public virtual IDynamicProp
{
public:
    virtual ~IBasePropDoor() = default;

    virtual float& AutoReturnDelay() = 0;
    virtual void AutoReturnDelayUpdated() = 0;
    virtual CUtlVector<CHandle<CBasePropDoor>>& DoorList() = 0;
    virtual void DoorListUpdated() = 0;
    virtual int32_t& HardwareType() = 0;
    virtual void HardwareTypeUpdated() = 0;
    virtual bool& NeedsHardware() = 0;
    virtual void NeedsHardwareUpdated() = 0;
    virtual ::DoorState_t& DoorState() = 0;
    virtual void DoorStateUpdated() = 0;
    virtual bool& Locked() = 0;
    virtual void LockedUpdated() = 0;
    virtual bool& NoNPCs() = 0;
    virtual void NoNPCsUpdated() = 0;
    virtual Vector& ClosedPosition() = 0;
    virtual void ClosedPositionUpdated() = 0;
    virtual QAngle& ClosedAngles() = 0;
    virtual void ClosedAnglesUpdated() = 0;
    virtual CHandle<CBaseEntity>& Blocker() = 0;
    virtual void BlockerUpdated() = 0;
    virtual bool& FirstBlocked() = 0;
    virtual void FirstBlockedUpdated() = 0;
    virtual ::locksound_t& Ls() = 0;
    virtual void LsUpdated() = 0;
    virtual bool& ForceClosed() = 0;
    virtual void ForceClosedUpdated() = 0;
    virtual Vector& LatchWorldPosition() = 0;
    virtual void LatchWorldPositionUpdated() = 0;
    virtual CHandle<CBaseEntity>& Activator() = 0;
    virtual void ActivatorUpdated() = 0;
    virtual CUtlSymbolLarge& SoundMoving() = 0;
    virtual void SoundMovingUpdated() = 0;
    virtual CUtlSymbolLarge& SoundOpen() = 0;
    virtual void SoundOpenUpdated() = 0;
    virtual CUtlSymbolLarge& SoundClose() = 0;
    virtual void SoundCloseUpdated() = 0;
    virtual CUtlSymbolLarge& SoundLock() = 0;
    virtual void SoundLockUpdated() = 0;
    virtual CUtlSymbolLarge& SoundUnlock() = 0;
    virtual void SoundUnlockUpdated() = 0;
    virtual CUtlSymbolLarge& SoundLatch() = 0;
    virtual void SoundLatchUpdated() = 0;
    virtual CUtlSymbolLarge& SoundPound() = 0;
    virtual void SoundPoundUpdated() = 0;
    virtual CUtlSymbolLarge& SoundJiggle() = 0;
    virtual void SoundJiggleUpdated() = 0;
    virtual CUtlSymbolLarge& SoundLockedAnim() = 0;
    virtual void SoundLockedAnimUpdated() = 0;
    virtual int32_t& NumCloseAttempts() = 0;
    virtual void NumCloseAttemptsUpdated() = 0;
    virtual CUtlStringToken* PhysicsMaterial() = 0;
    virtual CUtlSymbolLarge& SlaveName() = 0;
    virtual void SlaveNameUpdated() = 0;
    virtual CHandle<CBasePropDoor>& Master() = 0;
    virtual void MasterUpdated() = 0;
    virtual ::CEntityIOOutput& OnBlockedClosing() = 0;
    virtual void OnBlockedClosingUpdated() = 0;
    virtual ::CEntityIOOutput& OnBlockedOpening() = 0;
    virtual void OnBlockedOpeningUpdated() = 0;
    virtual ::CEntityIOOutput& OnUnblockedClosing() = 0;
    virtual void OnUnblockedClosingUpdated() = 0;
    virtual ::CEntityIOOutput& OnUnblockedOpening() = 0;
    virtual void OnUnblockedOpeningUpdated() = 0;
    virtual ::CEntityIOOutput& OnFullyClosed() = 0;
    virtual void OnFullyClosedUpdated() = 0;
    virtual ::CEntityIOOutput& OnFullyOpen() = 0;
    virtual void OnFullyOpenUpdated() = 0;
    virtual ::CEntityIOOutput& OnClose() = 0;
    virtual void OnCloseUpdated() = 0;
    virtual ::CEntityIOOutput& OnOpen() = 0;
    virtual void OnOpenUpdated() = 0;
    virtual ::CEntityIOOutput& OnLockedUse() = 0;
    virtual void OnLockedUseUpdated() = 0;
    virtual ::CEntityIOOutput& OnAjarOpen() = 0;
    virtual void OnAjarOpenUpdated() = 0;
    static IBasePropDoor* FromOriginal(CBasePropDoor* p);
};

#endif // _INCLUDE_IBASEPROPDOOR_H
