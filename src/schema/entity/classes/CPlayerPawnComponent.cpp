//
// Created by Michal Přikryl on 11.04.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CPlayerPawnComponent.h"

#include "source2toolkit/schema/entity/classes/CCSPlayerPawn.h"

CCSPlayerPawn* CPlayerPawnComponent::GetPlayerPawn() {
    return static_cast<CCSPlayerPawn*>(__m_pChainEntity());
}