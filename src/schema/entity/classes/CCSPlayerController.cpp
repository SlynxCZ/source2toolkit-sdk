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


#include "source2toolkit/schema/entity/classes/CCSPlayerController.h"

#include "tier0/dbg.h"

#include "source2toolkit/schema/entity/classes/CCSPlayerPawn.h"
#include "source2toolkit/schema/entity/classes/CCSObserverPawn.h"
#include "source2toolkit/schema/takedamageinfo.h"
#include "source2toolkit/schema/takedamageresult.h"
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
#include "core/menus.h"
#include "core/shared.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitMenus.h"
#include "source2toolkit/IToolkitPlugin.h"
TOOLKIT_GLOBALVARS();
#endif

#include "iserver.h"

CCSPlayerController *CCSPlayerController::FromPawn(CCSPlayerPawn* pPawn)
{
    return static_cast<CCSPlayerController*>(pPawn->m_hController().Get());
}

CCSPlayerController *CCSPlayerController::FromSlot(int iSlot)
{
    return static_cast<CCSPlayerController*>(GetEntitySystem()->GetEntityInstance(CEntityIndex(iSlot + 1)));
}

CCSPlayerController *CCSPlayerController::FromSlot(CPlayerSlot slot)
{
    if (!slot.IsValid())
        return nullptr;

    return FromSlot(slot.Get());
}

CCSPlayerController *CCSPlayerController::FromUserId(int iUserId)
{
    for (int i = 0; i < GetGlobalVars()->maxClients; ++i)
    {
        CCSPlayerController* controller = FromSlot(i);
        if (!controller)
            continue;

        if (iUserId == GetEngineServer()->GetPlayerUserId(i).Get()) return controller;
    }
    return nullptr;
}

CCSPlayerController *CCSPlayerController::FromUserId(CPlayerUserId userId)
{
    return FromUserId(userId.Get());
}

CCSPlayerController *CCSPlayerController::FromSteamId(uint64 uSteamId)
{
    for (int i = 0; i < GetGlobalVars()->maxClients; ++i)
    {
        CCSPlayerController* controller = FromSlot(i);
        if (!controller)
            continue;

        if (uSteamId == controller->m_steamID()) return controller;
    }
    return nullptr;
}

CCSPlayerController *CCSPlayerController::FromSteamId(CSteamID steamId)
{
    return FromSteamId(steamId.ConvertToUint64());
}

void CCSPlayerController::PrintToCenterHtml(const char* pszMessage, int iDuration, bool bMenu)
{
#ifdef SOURCE2TOOLKIT_CORE
    if (!bMenu && menus::menuManager.GetActiveMenu(this))
#else
    if (!bMenu && g_ToolkitAPI->Menus()->GetActiveMenu(this))
#endif
        return;

    IGameEvent *event = GetGameEventManager()->CreateEvent("show_survival_respawn_status", true);
    if (!event) return;

    event->SetString("loc_token", pszMessage);
    event->SetInt("duration", iDuration);
    event->SetPlayer("userid", GetPlayerSlot());

    FireEventToClient(event);
}

void CCSPlayerController::TakeDamage(CCSPlayerController* pAttacker, int iDamage, DamageTypes_t bitsDamageType)
{
    if (!m_bPawnIsAlive || m_iConnected() != PlayerConnectedState::Connected || !pAttacker || pAttacker->m_iConnected() != PlayerConnectedState::Connected)
        return;

    CCSPlayerPawn* pVictimPawn = GetPlayerPawn();
    if (!pVictimPawn) return;

    CCSPlayerPawn* pAttackerPawn = pAttacker->GetPlayerPawn();
    if (!pAttackerPawn) return;

    auto flDamage = static_cast<float>(iDamage);

    CTakeDamageInfo info(pVictimPawn, pAttackerPawn, nullptr, flDamage, bitsDamageType);
    info.m_nDamageFlags = static_cast<TakeDamageFlags_t>(static_cast<int>(info.m_nDamageFlags) | static_cast<int>(TakeDamageFlags_t::DFLAG_SUPPRESS_DAMAGE_MODIFICATION));

    CTakeDamageResult result(iDamage);
    result.CopyFrom(&info);

#ifdef SOURCE2TOOLKIT_CORE
    auto pfn = addresses::toolkitAddresses.CBaseEntity_TakeDamageOld();
#else
    auto pfn = g_ToolkitAPI->Addresses()->CBaseEntity_TakeDamageOld();
#endif

    // Past every plugin's Pre/Post handler. Damage the toolkit was asked to
    // deal is not the game dealing damage, so a plugin hooking TakeDamage to
    // police the game's own hits should not have to tell the two apart -- and
    // a handler that supercedes would otherwise silently swallow this.
    //
    // On the pawn, not the controller: the tracing showed a real hit arriving
    // on classname 'player' while this call arrived on 'cs_player_controller',
    // whose m_iHealth is 0.
    TOOLKIT_ORIGINAL(pfn)(pVictimPawn, &info, &result);
}

void CCSPlayerController::Respawn()
{
    if (!m_hPlayerPawn()) return;

    // The Call To Arms update appears to have invalidated the need for CCSPlayerPawn_Respawn.
    SetPawn(m_hPlayerPawn());
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayerController::Respawn");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayerController::Respawn");
#endif
    CALL_VIRTUAL(void, offset, this);
}

void CCSPlayerController::SwitchTeam(int nTeam)
{
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.CCSPlayerController_SwitchTeam()(this, static_cast<unsigned char>(nTeam));
#else
    g_ToolkitAPI->Addresses()->CCSPlayerController_SwitchTeam()(this, static_cast<unsigned char>(nTeam));
#endif
}

void CCSPlayerController::ChangeTeam(int nTeam)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayerController::ChangeTeam");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayerController::ChangeTeam");
#endif
    CALL_VIRTUAL(void, offset, this, nTeam);
}

CCSPlayerPawn* CCSPlayerController::GetPlayerPawn()
{
    if (auto handle = m_hPlayerPawn(); handle.IsValid())
        return handle.Get();
    return nullptr;
}

CCSObserverPawn* CCSPlayerController::GetObserverPawn()
{
    if (auto handle = m_hObserverPawn(); handle.IsValid())
        return handle.Get();
    return nullptr;
}
