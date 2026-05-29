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

#ifndef _INCLUDE_IBASEDOOR_H
#define _INCLUDE_IBASEDOOR_H

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

#include "IBaseToggle.h"

#include "../enums/FuncDoorSpawnPos_t.h"

class CBaseDoor;
class locksound_t;

class IBaseDoor : public virtual IBaseToggle
{
public:
    virtual ~IBaseDoor() = default;
    CBaseDoor* GetOriginal() { return reinterpret_cast<CBaseDoor*>(IEntityInstance::GetOriginal()); }

    virtual QAngle& MoveEntitySpace() = 0;
    virtual void MoveEntitySpaceUpdated() = 0;
    virtual Vector& MoveDirParentSpace() = 0;
    virtual void MoveDirParentSpaceUpdated() = 0;
    virtual ::locksound_t& Ls() = 0;
    virtual void LsUpdated() = 0;
    virtual bool& ForceClosed() = 0;
    virtual void ForceClosedUpdated() = 0;
    virtual bool& DoorGroup() = 0;
    virtual void DoorGroupUpdated() = 0;
    virtual bool& Locked() = 0;
    virtual void LockedUpdated() = 0;
    virtual bool& IgnoreDebris() = 0;
    virtual void IgnoreDebrisUpdated() = 0;
    virtual bool& NoNPCs() = 0;
    virtual void NoNPCsUpdated() = 0;
    virtual ::FuncDoorSpawnPos_t& SpawnPosition() = 0;
    virtual void SpawnPositionUpdated() = 0;
    virtual float& BlockDamage() = 0;
    virtual void BlockDamageUpdated() = 0;
    virtual CUtlSymbolLarge& NoiseMoving() = 0;
    virtual void NoiseMovingUpdated() = 0;
    virtual CUtlSymbolLarge& NoiseArrived() = 0;
    virtual void NoiseArrivedUpdated() = 0;
    virtual CUtlSymbolLarge& NoiseMovingClosed() = 0;
    virtual void NoiseMovingClosedUpdated() = 0;
    virtual CUtlSymbolLarge& NoiseArrivedClosed() = 0;
    virtual void NoiseArrivedClosedUpdated() = 0;
    virtual CUtlSymbolLarge& ChainTarget() = 0;
    virtual void ChainTargetUpdated() = 0;
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
    virtual bool& LoopMoveSound() = 0;
    virtual void LoopMoveSoundUpdated() = 0;
    virtual bool& CreateNavObstacle() = 0;
    virtual void CreateNavObstacleUpdated() = 0;
    virtual bool& IsChaining() = 0;
    virtual void IsChainingUpdated() = 0;
    virtual bool& IsUsable() = 0;
    virtual void IsUsableUpdated() = 0;
    static IBaseDoor* FromOriginal(CBaseDoor* p);
};

#endif // _INCLUDE_IBASEDOOR_H
