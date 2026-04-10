//
// Created by Michal Přikryl on 04.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "CBasePlayerPawn.h"

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

void CBasePlayerPawn::CommitSuicide(bool bExplode, bool bForce) {
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CBasePlayerPawn_CommitSuicide");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CBasePlayerPawn_CommitSuicide");
#endif
    CALL_VIRTUAL(void, offset, this, bExplode, bForce);
}

void CBasePlayerPawn::RemovePlayerItem(CBasePlayerWeapon* pWeapon) {
    if (!pWeapon) return;

#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.RemovePlayerItem(this, pWeapon);
#else
    g_ToolkitAPI->Addresses()->CBasePlayerPawn_RemovePlayerItem()(this, pWeapon);
#endif
}