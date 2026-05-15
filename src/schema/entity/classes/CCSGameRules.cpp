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
#include "source2toolkit/schema/entities.h"

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

void CCSGameRules::TerminateRound(float flDelay, int32_t eRoundEndReason)
{
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.TerminateRound(this, flDelay, eRoundEndReason, 0, 0);
#else
    g_ToolkitAPI->Addresses()->CGameRules_TerminateRound()(this, flDelay, eRoundEndReason, 0, 0);
#endif
}

CBaseEntity* CCSGameRules::FindPickerEntity(CBasePlayerController* pPlayer)
{
    return UTIL_FindPickerEntity(pPlayer, this);
}

CCSPlayerController* CCSGameRules::GetClientAimTarget(CCSPlayerController* pPlayer)
{
    auto* pPawn = static_cast<CCSPlayerPawn*>(UTIL_FindPickerEntity(pPlayer, this));
    if (!pPawn) return nullptr;

    return V_strcmp(pPawn->GetClassname(), "player") == 0 ? pPawn->m_hOriginalController().Get() : nullptr;
}