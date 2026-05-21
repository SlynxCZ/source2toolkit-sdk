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

#include "source2toolkit/schema/entity/classes/CCSPlayerPawn.h"
#include "source2toolkit/schema/entity/classes/CCSObserverPawn.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
#endif

#include "source2toolkit/schema/entities.h"
#include "source2toolkit/schema/takedamageinfo.h"

#include "networksystem/inetworkmessages.h"
#include "usermessages.pb.h"

#include "source2toolkit/utils/virtual.h"

enum class HudDestination
{
    Notify = 1,
    Console = 2,
    Chat = 3,
    Center = 4,
    Alert = 6
};

static void ClientPrint(int slot, int hudDestination, const char* message)
{
    INetworkMessageInternal* pNetMsg = GetNetworkMessages()->FindNetworkMessagePartial("TextMsg");
    auto data = pNetMsg->AllocateMessage()->ToPB<CUserMessageTextMsg>();

    data->set_dest(hudDestination);
    data->add_param(message);

    CPlayerBitVec recipients;
    recipients.Set(slot);

    GetGameEventSystem()->PostEventAbstract(CSplitScreenSlot(-1), false, ABSOLUTE_PLAYER_LIMIT,
                                                reinterpret_cast<const uint64*>(recipients.Base()), pNetMsg, data, 0,
                                                NetChannelBufType_t::BUF_RELIABLE);

    delete data;
}

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

void CCSPlayerController::PrintToConsole(const char* pszMessage)
{
    std::string pszSanitizedMessage;
    pszSanitizedMessage.reserve(strlen(pszMessage) + 2);
    pszSanitizedMessage = pszMessage;
    pszSanitizedMessage += '\n';
    ClientPrint(GetSlot(), (int)HudDestination::Console, pszSanitizedMessage.c_str());
}

void CCSPlayerController::PrintToChat(const char* pszMessage)
{
    ClientPrint(GetSlot(), (int)HudDestination::Chat, pszMessage);
}

void CCSPlayerController::PrintToCenter(const char* pszMessage)
{
    ClientPrint(GetSlot(), (int)HudDestination::Center, pszMessage);
}

void CCSPlayerController::PrintToCenterAlert(const char* pszMessage)
{
    ClientPrint(GetSlot(), (int)HudDestination::Alert, pszMessage);
}

void CCSPlayerController::PrintToCenterHtml(const char* pszMessage, int iDuration)
{
    IGameEvent *event = GetGameEventManager()->CreateEvent("show_survival_respawn_status", true);
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

#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.TakeDamageOld(this, &info, nullptr);
#else
    g_ToolkitAPI->Addresses()->CBaseEntity_TakeDamageOld()(this, &info, nullptr);
#endif
}

void CCSPlayerController::Respawn()
{
    if (!m_hPlayerPawn()) return;

    // The Call To Arms update appears to have invalidated the need for CCSPlayerPawn_Respawn.
    SetPawn(m_hPlayerPawn());
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayerController_Respawn");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayerController_Respawn");
#endif
    CALL_VIRTUAL(void, offset, this);
}

void CCSPlayerController::SwitchTeam(int nTeam)
{
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.SwitchTeam(this, static_cast<unsigned char>(nTeam));
#else
    g_ToolkitAPI->Addresses()->CCSPlayerController_SwitchTeam()(this, static_cast<unsigned char>(nTeam));
#endif
}

void CCSPlayerController::ChangeTeam(int nTeam)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayerController_ChangeTeam");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayerController_ChangeTeam");
#endif
    CALL_VIRTUAL(void, offset, this, nTeam);
}

bool CCSPlayerController::IsBot()
{
    return (m_fFlags & FL_FAKECLIENT) != 0;
}

void CCSPlayerController::Disconnect(ENetworkDisconnectionReason eReason)
{
    GetEngineServer()->DisconnectClient(GetSlot(), eReason);
}

void CCSPlayerController::ExecuteClientCommand(const char* pszCommand)
{
    GetEngineServer()->ClientCommand(GetPlayerSlot(), "%s", pszCommand);
}

void CCSPlayerController::ExecuteClientCommandFromServer(const char* pszCommand)
{
    CCommand args;
    args.Tokenize(pszCommand);

    auto handle = GetCVar()->FindConCommand(args.Arg(0));
    if (!handle.IsValidRef()) return;

    CCommandContext context(CommandTarget_t::CT_NO_TARGET, GetPlayerSlot());

    GetCVar()->DispatchConCommand(handle, context, args);
}

CCSPlayerPawn* CCSPlayerController::GetPawn()
{
    if (auto handle = m_hPawn(); handle.IsValid())
        return static_cast<CCSPlayerPawn*>(handle.Get());
    return nullptr;
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

CEntityIndex CCSPlayerController::GetPlayerIndex()
{
    return GetEntityIndex();
}

int CCSPlayerController::GetSlot()
{
    return GetIndex() - 1;
}

CPlayerSlot CCSPlayerController::GetPlayerSlot()
{
    return CPlayerSlot(GetSlot());
}

int CCSPlayerController::GetUserID()
{
    return GetEngineServer()->GetPlayerUserId(GetPlayerSlot()).Get();
}

CPlayerUserId CCSPlayerController::GetPlayerUserID()
{
    return GetEngineServer()->GetPlayerUserId(GetPlayerSlot());
}

uint64 CCSPlayerController::GetSteamID()
{
    return m_steamID();
}

CSteamID CCSPlayerController::GetPlayerSteamID()
{
    return CSteamID(static_cast<uint64>(m_steamID()));
}

const char* CCSPlayerController::GetPlayerName()
{
    return m_iszPlayerName();
}

CUtlString CCSPlayerController::GetIpAddress()
{
    if (const auto* netInfo = GetEngineServer()->GetPlayerNetInfo(GetPlayerSlot()))
    {
        uint32_t ip = netInfo->GetRemoteAddress().GetIP();

        ip = ((ip & 0x000000FF) << 24) |
             ((ip & 0x0000FF00) << 8)  |
             ((ip & 0x00FF0000) >> 8)  |
             ((ip & 0xFF000000) >> 24);

        char buffer[64];

        std::snprintf(
            buffer,
            sizeof(buffer),
            "%u.%u.%u.%u",
            (ip >> 24) & 0xFF,
            (ip >> 16) & 0xFF,
            (ip >> 8) & 0xFF,
            ip & 0xFF
        );

        return CUtlString(buffer);
    }

    return CUtlString();
}

void CCSPlayerController::ReplicateConVar(const char* pszConVar, const char* pszValue)
{
    INetChannel* pNetChannel = reinterpret_cast<INetChannel*>(GetEngineServer()->GetPlayerNetInfo(GetPlayerSlot()));
    if (pNetChannel)
    {
        static INetworkMessageInternal* pMsg = GetNetworkMessages()->FindNetworkMessagePartial("CNETMsg_SetConVar");

        CNetMessagePB<CNETMsg_SetConVar>* msg = pMsg->AllocateMessage()->ToPB<CNETMsg_SetConVar>();
        auto cvar = msg->mutable_convars()->add_cvars();
        cvar->set_name(pszConVar);
        cvar->set_value(pszValue);

        pNetChannel->SendNetMessage(msg, BUF_DEFAULT);

        delete msg;
    }
}

void CCSPlayerController::FireEventToClient(IGameEvent* pEvent)
{
    if (!pEvent) return;

#ifdef SOURCE2TOOLKIT_CORE
    IGameEventListener2* pListener = addresses::toolkitAddresses.LegacyGameEventListener(GetPlayerSlot());
#else
    IGameEventListener2* pListener = g_ToolkitAPI->Addresses()->CCSPlayerController_LegacyGameEventListener()(GetPlayerSlot());
#endif
    if (!pListener) return;

    pListener->FireGameEvent(pEvent);
}