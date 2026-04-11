//
// Created by Michal Přikryl on 11.04.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "CPlayerControllerComponent.h"

#include "CCSPlayerController.h"

CCSPlayerController* CPlayerControllerComponent::GetPlayerController() {
    return static_cast<CCSPlayerController*>(__m_pChainEntity());
}