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

#include "source2toolkit/schema/entity/classes/CCSPlayer_WeaponServices.h"

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
#endif

bool CCSPlayer_WeaponServices::CanUse(CBasePlayerWeapon* pWeapon)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices_CanUse");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices_CanUse");
#endif
    return CALL_VIRTUAL(bool, offset, this, pWeapon);
}

void CCSPlayer_WeaponServices::DropWeapon(CBasePlayerWeapon *pWeapon, Vector *pVecTarget, Vector *pVelocity)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices_DropWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices_DropWeapon");
#endif
    CALL_VIRTUAL(void, offset, this, pWeapon, pVecTarget, pVelocity);
}

int CCSPlayer_WeaponServices::BumpWeapon(CBasePlayerWeapon* pWeapon)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices_BumpWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices_BumpWeapon");
#endif
    return CALL_VIRTUAL(int, offset, this, pWeapon);
}

void CCSPlayer_WeaponServices::SelectItem(CBasePlayerWeapon* pWeapon, int unk1)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices_SelectItem");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices_SelectItem");
#endif
    CALL_VIRTUAL(void, offset, this, pWeapon, unk1);
}

void CCSPlayer_WeaponServices::Destroy(CBasePlayerWeapon* pWeapon)
{
#ifndef _WIN32
    if(pWeapon)
#endif
    {
#ifdef SOURCE2TOOLKIT_CORE
        addresses::toolkitAddresses.CCSPlayer_WeaponServices_Destroy()(this, pWeapon);
#else
        g_ToolkitAPI->Addresses()->CCSPlayer_WeaponServices_Destroy()(this, pWeapon);
#endif
    }
}
