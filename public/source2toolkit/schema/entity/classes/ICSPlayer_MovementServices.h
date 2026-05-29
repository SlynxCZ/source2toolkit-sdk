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

#ifndef _INCLUDE_ICSPLAYER_MOVEMENTSERVICES_H
#define _INCLUDE_ICSPLAYER_MOVEMENTSERVICES_H

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

#include "IPlayer_MovementServices_Humanoid.h"

class CCSPlayerAnimationState;
class CCSPlayerLegacyJump;
class CCSPlayerModernJump;
class CCSPlayer_MovementServices;

class ICSPlayer_MovementServices : public virtual IPlayer_MovementServices_Humanoid
{
public:
    virtual ~ICSPlayer_MovementServices() = default;

    virtual ::CCSPlayerAnimationState& AnimationState() = 0;
    virtual void AnimationStateUpdated() = 0;
    virtual bool& UsingGroundTopologyOffset() = 0;
    virtual void UsingGroundTopologyOffsetUpdated() = 0;
    virtual float& UsingGroundTopologyOffsetTransitionSmoothing() = 0;
    virtual void UsingGroundTopologyOffsetTransitionSmoothingUpdated() = 0;
    virtual Vector& LadderNormal() = 0;
    virtual void LadderNormalUpdated() = 0;
    virtual int32_t& LadderSurfacePropIndex() = 0;
    virtual void LadderSurfacePropIndexUpdated() = 0;
    virtual bool& Ducked() = 0;
    virtual void DuckedUpdated() = 0;
    virtual float& DuckAmount() = 0;
    virtual void DuckAmountUpdated() = 0;
    virtual float& DuckSpeed() = 0;
    virtual void DuckSpeedUpdated() = 0;
    virtual bool& DuckOverride() = 0;
    virtual void DuckOverrideUpdated() = 0;
    virtual bool& DesiresDuck() = 0;
    virtual void DesiresDuckUpdated() = 0;
    virtual bool& Ducking() = 0;
    virtual void DuckingUpdated() = 0;
    virtual float& DuckRootOffset() = 0;
    virtual void DuckRootOffsetUpdated() = 0;
    virtual float& DuckViewOffset() = 0;
    virtual void DuckViewOffsetUpdated() = 0;
    virtual float& LastDuckTime() = 0;
    virtual void LastDuckTimeUpdated() = 0;
    virtual float& BombPlantViewOffset() = 0;
    virtual void BombPlantViewOffsetUpdated() = 0;
    virtual Vector2D& LastPositionAtFullCrouchSpeed() = 0;
    virtual void LastPositionAtFullCrouchSpeedUpdated() = 0;
    virtual bool& DuckUntilOnGround() = 0;
    virtual void DuckUntilOnGroundUpdated() = 0;
    virtual bool& HasWalkMovedSinceLastJump() = 0;
    virtual void HasWalkMovedSinceLastJumpUpdated() = 0;
    virtual bool& InStuckTest() = 0;
    virtual void InStuckTestUpdated() = 0;
    virtual int32_t& TraceCount() = 0;
    virtual void TraceCountUpdated() = 0;
    virtual int32_t& StuckLast() = 0;
    virtual void StuckLastUpdated() = 0;
    virtual bool& SpeedCropped() = 0;
    virtual void SpeedCroppedUpdated() = 0;
    virtual int32_t& OldWaterLevel() = 0;
    virtual void OldWaterLevelUpdated() = 0;
    virtual float& WaterEntryTime() = 0;
    virtual void WaterEntryTimeUpdated() = 0;
    virtual Vector& Forward() = 0;
    virtual void ForwardUpdated() = 0;
    virtual Vector& Left() = 0;
    virtual void LeftUpdated() = 0;
    virtual Vector& Up() = 0;
    virtual void UpUpdated() = 0;
    virtual int32_t& GameCodeHasMovedPlayerAfterCommand() = 0;
    virtual void GameCodeHasMovedPlayerAfterCommandUpdated() = 0;
    virtual bool& MadeFootstepNoise() = 0;
    virtual void MadeFootstepNoiseUpdated() = 0;
    virtual int32_t& Footsteps() = 0;
    virtual void FootstepsUpdated() = 0;
    virtual float& StashGrenadeParameterWhen() = 0;
    virtual void StashGrenadeParameterWhenUpdated() = 0;
    virtual uint64_t& ButtonDownMaskPrev() = 0;
    virtual void ButtonDownMaskPrevUpdated() = 0;
    virtual bool& UseFrictionStashedSpeed() = 0;
    virtual void UseFrictionStashedSpeedUpdated() = 0;
    virtual float& UseFrictionStashedSpeedUntilFrac() = 0;
    virtual void UseFrictionStashedSpeedUntilFracUpdated() = 0;
    virtual float& FrictionStashedSpeed() = 0;
    virtual void FrictionStashedSpeedUpdated() = 0;
    virtual float& Stamina() = 0;
    virtual void StaminaUpdated() = 0;
    virtual float& HeightAtJumpStart() = 0;
    virtual void HeightAtJumpStartUpdated() = 0;
    virtual float& MaxJumpHeightThisJump() = 0;
    virtual void MaxJumpHeightThisJumpUpdated() = 0;
    virtual float& MaxJumpHeightLastJump() = 0;
    virtual void MaxJumpHeightLastJumpUpdated() = 0;
    virtual float& StaminaAtJumpStart() = 0;
    virtual void StaminaAtJumpStartUpdated() = 0;
    virtual float& VelMulAtJumpStart() = 0;
    virtual void VelMulAtJumpStartUpdated() = 0;
    virtual float& AccumulatedJumpError() = 0;
    virtual void AccumulatedJumpErrorUpdated() = 0;
    virtual ::CCSPlayerLegacyJump& LegacyJump() = 0;
    virtual void LegacyJumpUpdated() = 0;
    virtual ::CCSPlayerModernJump& ModernJump() = 0;
    virtual void ModernJumpUpdated() = 0;
    virtual int32_t& LastJumpTick() = 0;
    virtual void LastJumpTickUpdated() = 0;
    virtual float& LastJumpFrac() = 0;
    virtual void LastJumpFracUpdated() = 0;
    virtual float& LastJumpVelocityZ() = 0;
    virtual void LastJumpVelocityZUpdated() = 0;
    virtual bool& JumpApexPending() = 0;
    virtual void JumpApexPendingUpdated() = 0;
    virtual float& TicksSinceLastSurfingDetected() = 0;
    virtual void TicksSinceLastSurfingDetectedUpdated() = 0;
    virtual bool& WasSurfing() = 0;
    virtual void WasSurfingUpdated() = 0;
    virtual Vector2D& WalkWishVel() = 0;
    virtual void WalkWishVelUpdated() = 0;
    virtual bool& HasEverProcessedCommand() = 0;
    virtual void HasEverProcessedCommandUpdated() = 0;
    static ICSPlayer_MovementServices* FromOriginal(CCSPlayer_MovementServices* p);
};

#endif // _INCLUDE_ICSPLAYER_MOVEMENTSERVICES_H
