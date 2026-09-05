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

#include "source2toolkit/schema/entity/classes/CPlayer_ItemServices.h"

#include "source2toolkit/utils/virtual.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/addresses.h"
#include "core/gameconfig.h"
#include "core/shared.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
TOOLKIT_GLOBALVARS();
#endif

// The gamedata keys still name CCSPlayer_ItemServices: that is the class the
// vtable index was read off. Every item services object the game hands out is
// one, so the call is valid through the base pointer CBasePlayerPawn stores.

void CPlayer_ItemServices::DropActivePlayerWeapon(CBasePlayerWeapon* pActiveWeapon)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_ItemServices::DropActivePlayerWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_ItemServices::DropActivePlayerWeapon");
#endif
    CALL_VIRTUAL(void, offset, this, pActiveWeapon);
}

void CPlayer_ItemServices::RemoveWeapons(bool bRemoveSuit)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_ItemServices::RemoveWeapons");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_ItemServices::RemoveWeapons");
#endif
    CALL_VIRTUAL(void, offset, this, bRemoveSuit);
}

CBasePlayerWeapon* CPlayer_ItemServices::GiveNamedItem(const char* pszItem)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_ItemServices::GiveNamedItem");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_ItemServices::GiveNamedItem");
#endif
    return CALL_VIRTUAL(CBasePlayerWeapon*, offset, this, pszItem);
}
