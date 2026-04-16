//
// Created by Michal Přikryl on 11.04.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CPlayerControllerComponent.h"

#include "source2toolkit/schema/entity/classes/CCSPlayerController.h"

CCSPlayerController* CPlayerControllerComponent::GetPlayerController() {
    return static_cast<CCSPlayerController*>(__m_pChainEntity());
}