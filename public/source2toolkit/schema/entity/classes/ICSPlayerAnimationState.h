/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

#ifndef _INCLUDE_ICSPLAYERANIMATIONSTATE_H
#define _INCLUDE_ICSPLAYERANIMATIONSTATE_H

#pragma once

#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitTypes.h"
#include "source2toolkit/schema/entityio.h"
#include "source2toolkit/schema/schema.h"
#include <cstdint>

#include "IEntityInstance.h"

#include "../enums/CCSPlayerAnimationState__AirAction_t.h"
#include "../enums/CCSPlayerAnimationState__Direction_t.h"
#include "../enums/CCSPlayerAnimationState__GroundMoveState_t.h"
#include "../enums/CCSPlayerAnimationState__MoveType_t.h"

class CCSPlayerAnimationState;

class ICSPlayerAnimationState
{
public:
    virtual ~ICSPlayerAnimationState() = default;
    virtual CCSPlayerAnimationState* GetOriginal() const = 0;

    virtual ::CCSPlayerAnimationState__MoveType_t& CurrentMoveType() = 0;
    virtual void CurrentMoveTypeUpdated() = 0;
    virtual ::CCSPlayerAnimationState__GroundMoveState_t& GroundMoveState() = 0;
    virtual void GroundMoveStateUpdated() = 0;
    virtual ::CCSPlayerAnimationState__Direction_t& GroundActionDirection() = 0;
    virtual void GroundActionDirectionUpdated() = 0;
    virtual ::CCSPlayerAnimationState__AirAction_t& AirAction() = 0;
    virtual void AirActionUpdated() = 0;
    virtual bool& WasOnGroundLastUpdate() = 0;
    virtual void WasOnGroundLastUpdateUpdated() = 0;
    virtual bool& WasStationaryLastUpdate() = 0;
    virtual void WasStationaryLastUpdateUpdated() = 0;
    virtual int32_t& ActionStartTick() = 0;
    virtual void ActionStartTickUpdated() = 0;
    virtual int32_t& StaticAimTimerStartTick() = 0;
    virtual void StaticAimTimerStartTickUpdated() = 0;
    virtual int32_t& PlantAndTurnStartTick() = 0;
    virtual void PlantAndTurnStartTickUpdated() = 0;
    virtual float& TurnOnSpotAngle() = 0;
    virtual void TurnOnSpotAngleUpdated() = 0;
    virtual float& PreviousAimYaw() = 0;
    virtual void PreviousAimYawUpdated() = 0;
    virtual float& PreviousHorizontalSpeed() = 0;
    virtual void PreviousHorizontalSpeedUpdated() = 0;
    virtual float& FootIKOffsetLeft() = 0;
    virtual void FootIKOffsetLeftUpdated() = 0;
    virtual float& FootIKOffsetRight() = 0;
    virtual void FootIKOffsetRightUpdated() = 0;
    virtual float& WeaponDropPercentageDueToMovement() = 0;
    virtual void WeaponDropPercentageDueToMovementUpdated() = 0;
    virtual float& WeaponDropSmoothDampVelocity() = 0;
    virtual void WeaponDropSmoothDampVelocityUpdated() = 0;
    static ICSPlayerAnimationState* FromOriginal(CCSPlayerAnimationState* p);
};

#endif // _INCLUDE_ICSPLAYERANIMATIONSTATE_H
