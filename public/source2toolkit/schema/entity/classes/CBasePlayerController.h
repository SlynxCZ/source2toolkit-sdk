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

#ifndef _INCLUDE_CBASEPLAYERCONTROLLER_H
#define _INCLUDE_CBASEPLAYERCONTROLLER_H

#pragma once

#include "CBaseEntity.h"
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

#include "CBaseEntity.h"
#include "../enums/ChatIgnoreType_t.h"
#include "../enums/PlayerConnectedState.h"

class CBasePlayerPawn;

class CBasePlayerController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBasePlayerController);

    SCHEMA_FIELD(uint64_t, m_nInButtonsWhichAreToggles);
    SCHEMA_FIELD(uint32_t, m_nTickBase);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hPawn);
    SCHEMA_FIELD(bool, m_bKnownTeamMismatch);
    SCHEMA_FIELD(int32_t, m_nSplitScreenSlot);
    SCHEMA_FIELD(CHandle<CBasePlayerController>, m_hSplitOwner);
    SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerController>>, m_hSplitScreenPlayers);
    SCHEMA_FIELD(bool, m_bIsHLTV);
    SCHEMA_FIELD(PlayerConnectedState, m_iConnected);
    SCHEMA_FIELD_POINTER(char, m_iszPlayerName);
    SCHEMA_FIELD(CUtlString, m_szNetworkIDString);
    SCHEMA_FIELD(float, m_fLerpTime);
    SCHEMA_FIELD(bool, m_bLagCompensation);
    SCHEMA_FIELD(bool, m_bPredict);
    SCHEMA_FIELD(bool, m_bIsLowViolence);
    SCHEMA_FIELD(bool, m_bGamePaused);
    SCHEMA_FIELD(ChatIgnoreType_t, m_iIgnoreGlobalChat);
    SCHEMA_FIELD(float, m_flLastPlayerTalkTime);
    SCHEMA_FIELD(float, m_flLastEntitySteadyState);
    SCHEMA_FIELD(int32_t, m_nAvailableEntitySteadyState);
    SCHEMA_FIELD(bool, m_bHasAnySteadyStateEnts);
    SCHEMA_FIELD(uint64_t, m_steamID);
    SCHEMA_FIELD(bool, m_bNoClipEnabled);
    SCHEMA_FIELD(uint32_t, m_iDesiredFOV);

public:
    /// <summary>Set pawn for controller.</summary>
    void SetPawn(CBasePlayerPawn* pPawn);

public:
    static CBasePlayerController* New(const char* className)
    {
        return CBaseEntity::New<CBasePlayerController>(className);
    }

    static CBasePlayerController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBasePlayerController>(iIndex);
    }

    static CBasePlayerController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};

#endif // _INCLUDE_CBASEPLAYERCONTROLLER_H
