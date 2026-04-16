//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CCSPlayerPawn.h"
#include "source2toolkit/schema/entity/classes/CCSPlayerController.h"

CCSPlayerController* CCSPlayerPawn::GetController()
{
    if (auto handle = m_hController(); handle.IsValid())
        return static_cast<CCSPlayerController*>(handle.Get());
    return nullptr;
}

CCSPlayerController* CCSPlayerPawn::GetDefaultController()
{
    if (auto handle = m_hDefaultController(); handle.IsValid())
        return static_cast<CCSPlayerController*>(handle.Get());
    return nullptr;
}

CCSPlayerController* CCSPlayerPawn::GetOriginalController()
{
    if (auto handle = m_hOriginalController(); handle.IsValid())
        return handle.Get();
    return nullptr;
}