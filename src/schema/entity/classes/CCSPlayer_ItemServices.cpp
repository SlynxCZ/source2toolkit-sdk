//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CCSPlayer_ItemServices.h"

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

void CCSPlayer_ItemServices::DropActivePlayerWeapon(CBasePlayerWeapon* pActiveWeapon)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_ItemServices_DropActivePlayerWeapon");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_ItemServices_DropActivePlayerWeapon");
#endif
    CALL_VIRTUAL(void, offset, this, pActiveWeapon);
}

void CCSPlayer_ItemServices::RemoveWeapons()
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_ItemServices_RemoveWeapons");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_ItemServices_RemoveWeapons");
#endif
    CALL_VIRTUAL(void, offset, this);
}

CBasePlayerWeapon* CCSPlayer_ItemServices::GiveNamedItem(const char* pszItem)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CCSPlayer_ItemServices_GiveNamedItem");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CCSPlayer_ItemServices_GiveNamedItem");
#endif
    return CALL_VIRTUAL(CBasePlayerWeapon*, offset, this, pszItem);
}