
//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CCSPlayer_WeaponServices.h"

#include "source2toolkit/utils/virtual.h"

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

void CCSPlayer_WeaponServices::DropWeapon(CBasePlayerWeapon *pWeapon, Vector *pVecTarget, Vector *pVelocity)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices_DropWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices_DropWeapon");
#endif
    CALL_VIRTUAL(void, offset, this, pWeapon, pVecTarget, pVelocity);
}

void CCSPlayer_WeaponServices::SelectWeapon(CBasePlayerWeapon* pWeapon, int unk1)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_WeaponServices_SelectWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_WeaponServices_SelectWeapon");
#endif
    CALL_VIRTUAL(void, offset, this, pWeapon, unk1);
}