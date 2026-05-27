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

#ifndef _INCLUDE_IPHYSBOX_H
#define _INCLUDE_IPHYSBOX_H

#pragma once

#include <cstdint>

#include "IBreakable.h"

#include "../enums/HoverPoseFlags_t.h"

class CBasePlayerPawn;

class IPhysBox : public virtual IBreakable
{
public:
    virtual ~IPhysBox() = default;

    virtual int32_t& DamageType() = 0;
    virtual void DamageTypeUpdated() = 0;
    virtual int32_t& DamageToEnableMotion() = 0;
    virtual void DamageToEnableMotionUpdated() = 0;
    virtual float& ForceToEnableMotion() = 0;
    virtual void ForceToEnableMotionUpdated() = 0;
    virtual Vector& HoverPosePosition() = 0;
    virtual void HoverPosePositionUpdated() = 0;
    virtual QAngle& HoverPoseAngles() = 0;
    virtual void HoverPoseAnglesUpdated() = 0;
    virtual bool& NotSolidToWorld() = 0;
    virtual void NotSolidToWorldUpdated() = 0;
    virtual bool& EnableUseOutput() = 0;
    virtual void EnableUseOutputUpdated() = 0;
    virtual HoverPoseFlags_t& HoverPoseFlags() = 0;
    virtual void HoverPoseFlagsUpdated() = 0;
    virtual float& TouchOutputPerEntityDelay() = 0;
    virtual void TouchOutputPerEntityDelayUpdated() = 0;
    virtual CEntityIOOutput& OnDamaged() = 0;
    virtual void OnDamagedUpdated() = 0;
    virtual CEntityIOOutput& OnAwakened() = 0;
    virtual void OnAwakenedUpdated() = 0;
    virtual CEntityIOOutput& OnMotionEnabled() = 0;
    virtual void OnMotionEnabledUpdated() = 0;
    virtual CEntityIOOutput& OnPlayerUse() = 0;
    virtual void OnPlayerUseUpdated() = 0;
    virtual CEntityIOOutput& OnStartTouch() = 0;
    virtual void OnStartTouchUpdated() = 0;
    virtual CHandle<CBasePlayerPawn>& CarryingPlayer() = 0;
    virtual void CarryingPlayerUpdated() = 0;
};

#endif // _INCLUDE_IPHYSBOX_H
