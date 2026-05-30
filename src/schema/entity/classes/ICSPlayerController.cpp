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

#include "source2toolkit/schema/entity/classes/ICSPlayerController.h"
#include "source2toolkit/schema/entity/classes/ICSPlayerPawn.h"
#include "source2toolkit/schema/schema.h"

#include "entity2/entitysystem.h"
#include "entity2/entityidentity.h"

// ICSPlayerController::FromRaw and FromOriginal are defined in the core
// (CCSPlayerController.cpp) and resolved at runtime from source2toolkit.so.
// The helpers below are implemented in the SDK so plugins don't need to
// import them from the core — they only call FromRaw which comes from the core.

ICSPlayerController* ICSPlayerController::FromSlot(int iSlot)
{
    auto* raw = GetEntitySystem()->GetEntityInstance(CEntityIndex(iSlot + 1));
    return raw ? ICSPlayerController::FromRaw(raw) : nullptr;
}

ICSPlayerController* ICSPlayerController::FromSlot(CPlayerSlot slot)
{
    if (!slot.IsValid()) return nullptr;
    return FromSlot(slot.Get());
}

ICSPlayerController* ICSPlayerController::FromPawn(ICSPlayerPawn* pPawn)
{
    if (!pPawn) return nullptr;
    auto* pController = pPawn->GetController();
    return pController;
}

ICSPlayerController* ICSPlayerController::FromUserId(int iUserId)
{
    for (int i = 0; i < GetGlobalVars()->maxClients; ++i)
    {
        if (iUserId == GetEngineServer()->GetPlayerUserId(i).Get())
            return FromSlot(i);
    }
    return nullptr;
}

ICSPlayerController* ICSPlayerController::FromUserId(CPlayerUserId userId)
{
    return FromUserId(userId.Get());
}

ICSPlayerController* ICSPlayerController::FromSteamId(uint64 uSteamId)
{
    for (int i = 0; i < GetGlobalVars()->maxClients; ++i)
    {
        auto* p = FromSlot(i);
        if (p && p->GetSteamID() == uSteamId)
            return p;
    }
    return nullptr;
}

ICSPlayerController* ICSPlayerController::FromSteamId(CSteamID steamId)
{
    return FromSteamId(steamId.ConvertToUint64());
}
