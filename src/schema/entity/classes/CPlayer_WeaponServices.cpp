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

#include "source2toolkit/schema/entity/classes/CPlayer_WeaponServices.h"

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

// The gamedata keys still name CCSPlayer_WeaponServices: that is the class the
// vtable indices and the Destroy signature were read off. Every weapon services
// object the game hands out is one, so the calls are valid through the base
// pointer CBasePlayerPawn stores.

bool CPlayer_WeaponServices::CanUse(CBasePlayerWeapon* pWeapon)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices::CanUse");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices::CanUse");
#endif
    return CALL_VIRTUAL(bool, offset, this, pWeapon);
}

void CPlayer_WeaponServices::DropWeapon(CBasePlayerWeapon *pWeapon, Vector *pVecTarget, Vector *pVelocity)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices::DropWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices::DropWeapon");
#endif
    CALL_VIRTUAL(void, offset, this, pWeapon, pVecTarget, pVelocity);
}

int CPlayer_WeaponServices::BumpWeapon(CBasePlayerWeapon* pWeapon)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices::BumpWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices::BumpWeapon");
#endif
    return CALL_VIRTUAL(int, offset, this, pWeapon);
}

void CPlayer_WeaponServices::SelectItem(CBasePlayerWeapon* pWeapon, int unk1)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices::SelectItem");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices::SelectItem");
#endif
    CALL_VIRTUAL(void, offset, this, pWeapon, unk1);
}

void CPlayer_WeaponServices::Destroy(CBasePlayerWeapon* pWeapon)
{
#ifndef _WIN32
    if(pWeapon)
#endif
    {
#ifdef SOURCE2TOOLKIT_CORE
        addresses::toolkitAddresses.CPlayer_WeaponServices_Destroy()(this, pWeapon);
#else
        g_ToolkitAPI->Addresses()->CPlayer_WeaponServices_Destroy()(this, pWeapon);
#endif
    }
}
