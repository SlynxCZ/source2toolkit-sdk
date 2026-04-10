//
// Created by Michal Přikryl on 04.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "CBasePlayerController.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
#endif

void CBasePlayerController::SetPawn(CBasePlayerPawn* pPawn){
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.SetPawn(this, pPawn, true, false, false, false);
#else
    g_ToolkitAPI->Addresses()->CBasePlayerController_SetPawn()(this, pPawn, true, false, false, false);
#endif
}