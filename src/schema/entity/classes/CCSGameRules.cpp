//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CCSGameRules.h"

#include "source2toolkit/schema/entity/classes/CCSPlayerController.h"
#include "source2toolkit/schema/entity/classes/CCSPlayerPawn.h"
#include "source2toolkit/schema/entity.h"

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

    return pPawn->GetClassname() == "player" ? pPawn->m_hOriginalController().Get() : nullptr;
}