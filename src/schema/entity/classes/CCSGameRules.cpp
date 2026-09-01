/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

#include "source2toolkit/schema/entity/classes/CCSGameRules.h"

#include "source2toolkit/schema/entity/classes/CCSPlayerController.h"
#include "source2toolkit/schema/entity/classes/CCSPlayerPawn.h"
#include "source2toolkit/utils/virtual.h"

#ifdef SOURCE2TOOLKIT_CORE
// TOOLKIT_ORIGINAL below needs SH_GLOB_SHPTR. This points it at the toolkit's
// own engine, the one every .stx plugin is handed; in a plugin build
// TOOLKIT_GLOBALVARS() already provides g_SHPtr, which is that same engine.
#include "sourcehook/sourcehook_metamod_override.h"
#endif

#ifdef SOURCE2TOOLKIT_CORE
#include "core/addresses.h"
#include "core/entities.h"
#include "core/gameconfig.h"
#include "core/shared.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitEntities.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
TOOLKIT_GLOBALVARS();
#endif

void CCSGameRules::TerminateRound(float flDelay, int32_t eRoundEndReason, uint32 nTeamId)
{
#ifdef SOURCE2TOOLKIT_CORE
    auto pfnTerminateRound = addresses::toolkitAddresses.CGameRules_TerminateRound();
#else
    auto pfnTerminateRound = g_ToolkitAPI->Addresses()->CGameRules_TerminateRound();
#endif
    if (!pfnTerminateRound)
        return;

    // The team is taken by pointer, and null is what "no winning team" looks
    // like -- passing a pointer to zero is not the same thing.
    uint32 nTeam = nTeamId;
    uint32* pnTeamId = nTeamId > 0 ? &nTeam : nullptr;

    // Past every plugin's Pre/Post handler, for the same reason as
    // CCSPlayerController::TakeDamage: ending the round because the server was
    // told to is not the game ending the round, and a gamemode's TerminateRound
    // hook exists to police the latter. This is also where a typed bypass could
    // not help -- those hooks declare (CCSGameRules, RoundEndReason, float,
    // void*, uint8_t) against this interface's (CGameRules*, uint32, uint32*,
    // float), so nothing here matches the shape they were declared with.
    //
    // See the note on CGameRules_TerminateRound_t: the argument order is not
    // the same on both platforms.
    auto pfnOriginal = TOOLKIT_ORIGINAL(pfnTerminateRound);
#ifdef _WIN32
    pfnOriginal(this, flDelay, static_cast<uint32>(eRoundEndReason), pnTeamId);
#else
    pfnOriginal(this, static_cast<uint32>(eRoundEndReason), pnTeamId, flDelay);
#endif
}

CBaseEntity* CCSGameRules::FindPickerEntity(CBasePlayerController* pPlayer)
{
#ifdef SOURCE2TOOLKIT_CORE
    return entities::entitiesManager.FindPickerEntity(pPlayer, this);
#else
    return g_ToolkitAPI->Entities()->FindPickerEntity(pPlayer, this);
#endif
}

CCSPlayerController* CCSGameRules::GetClientAimTarget(CCSPlayerController* pPlayer)
{
    auto* pPawn = static_cast<CCSPlayerPawn*>(FindPickerEntity(pPlayer));
    if (!pPawn) return nullptr;

    return V_strcmp(pPawn->GetClassname(), "player") == 0 ? pPawn->m_hOriginalController().Get() : nullptr;
}

void CCSGameRules::GoToIntermission(bool bAbortedMatch)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CGameRules::GoToIntermission");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CGameRules::GoToIntermission");
#endif
    CALL_VIRTUAL(void, offset, this, bAbortedMatch);
}
