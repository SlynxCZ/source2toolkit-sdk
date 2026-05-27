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

#ifndef _INCLUDE_IBASEPLAYERCONTROLLER_H
#define _INCLUDE_IBASEPLAYERCONTROLLER_H

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

#include "IBaseEntity.h"

#include "../enums/ChatIgnoreType_t.h"
#include "../enums/PlayerConnectedState.h"

class CBasePlayerPawn;

class IBasePlayerController : public virtual IBaseEntity
{
public:
    virtual ~IBasePlayerController() = default;

    virtual uint64_t& InButtonsWhichAreToggles() = 0;
    virtual void InButtonsWhichAreTogglesUpdated() = 0;
    virtual uint32_t& TickBase() = 0;
    virtual void TickBaseUpdated() = 0;
    virtual CHandle<CBasePlayerPawn>& Pawn() = 0;
    virtual void PawnUpdated() = 0;
    virtual bool& KnownTeamMismatch() = 0;
    virtual void KnownTeamMismatchUpdated() = 0;
    virtual int32_t& SplitScreenSlot() = 0;
    virtual void SplitScreenSlotUpdated() = 0;
    virtual CHandle<CBasePlayerController>& SplitOwner() = 0;
    virtual void SplitOwnerUpdated() = 0;
    virtual CUtlVector<CHandle<CBasePlayerController>>& SplitScreenPlayers() = 0;
    virtual void SplitScreenPlayersUpdated() = 0;
    virtual bool& IsHLTV() = 0;
    virtual void IsHLTVUpdated() = 0;
    virtual PlayerConnectedState& Connected() = 0;
    virtual void ConnectedUpdated() = 0;
    virtual PlayerConnectedState& MostConnected() = 0;
    virtual void MostConnectedUpdated() = 0;
    virtual char* PlayerName() = 0;
    virtual CUtlString& NetworkIDString() = 0;
    virtual void NetworkIDStringUpdated() = 0;
    virtual float& LerpTime() = 0;
    virtual void LerpTimeUpdated() = 0;
    virtual bool& LagCompensation() = 0;
    virtual void LagCompensationUpdated() = 0;
    virtual bool& Predict() = 0;
    virtual void PredictUpdated() = 0;
    virtual bool& IsLowViolence() = 0;
    virtual void IsLowViolenceUpdated() = 0;
    virtual bool& GamePaused() = 0;
    virtual void GamePausedUpdated() = 0;
    virtual ChatIgnoreType_t& IgnoreGlobalChat() = 0;
    virtual void IgnoreGlobalChatUpdated() = 0;
    virtual float& LastPlayerTalkTime() = 0;
    virtual void LastPlayerTalkTimeUpdated() = 0;
    virtual float& LastEntitySteadyState() = 0;
    virtual void LastEntitySteadyStateUpdated() = 0;
    virtual int32_t& AvailableEntitySteadyState() = 0;
    virtual void AvailableEntitySteadyStateUpdated() = 0;
    virtual bool& HasAnySteadyStateEnts() = 0;
    virtual void HasAnySteadyStateEntsUpdated() = 0;
    virtual uint64_t& SteamID() = 0;
    virtual void SteamIDUpdated() = 0;
    virtual bool& NoClipEnabled() = 0;
    virtual void NoClipEnabledUpdated() = 0;
    virtual uint32_t& DesiredFOV() = 0;
    virtual void DesiredFOVUpdated() = 0;

    virtual void SetPawn(CBasePlayerPawn* pPawn) = 0;
};

#endif // _INCLUDE_IBASEPLAYERCONTROLLER_H
