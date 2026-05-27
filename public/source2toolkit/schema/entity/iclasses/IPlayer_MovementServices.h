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

#ifndef _INCLUDE_IPLAYER_MOVEMENTSERVICES_H
#define _INCLUDE_IPLAYER_MOVEMENTSERVICES_H

#pragma once

#include <cstdint>

#include "IPlayerPawnComponent.h"

#include "CInButtonState.h"

class IPlayer_MovementServices : public virtual IPlayerPawnComponent
{
public:
    virtual ~IPlayer_MovementServices() = default;

    virtual int32_t& Impulse() = 0;
    virtual void ImpulseUpdated() = 0;
    virtual CInButtonState& Buttons() = 0;
    virtual void ButtonsUpdated() = 0;
    virtual uint64_t& QueuedButtonDownMask() = 0;
    virtual void QueuedButtonDownMaskUpdated() = 0;
    virtual uint64_t& QueuedButtonChangeMask() = 0;
    virtual void QueuedButtonChangeMaskUpdated() = 0;
    virtual uint64_t& ButtonDoublePressed() = 0;
    virtual void ButtonDoublePressedUpdated() = 0;
    virtual uint32_t* ButtonPressedCmdNumber() = 0;
    virtual uint32_t& LastCommandNumberProcessed() = 0;
    virtual void LastCommandNumberProcessedUpdated() = 0;
    virtual uint64_t& ToggleButtonDownMask() = 0;
    virtual void ToggleButtonDownMaskUpdated() = 0;
    virtual float& CmdForwardMove() = 0;
    virtual void CmdForwardMoveUpdated() = 0;
    virtual float& CmdLeftMove() = 0;
    virtual void CmdLeftMoveUpdated() = 0;
    virtual float& CmdUpMove() = 0;
    virtual void CmdUpMoveUpdated() = 0;
    virtual float& Maxspeed() = 0;
    virtual void MaxspeedUpdated() = 0;
    virtual float* ForceSubtickMoveWhen() = 0;
    virtual float& ForwardMove() = 0;
    virtual void ForwardMoveUpdated() = 0;
    virtual float& LeftMove() = 0;
    virtual void LeftMoveUpdated() = 0;
    virtual float& UpMove() = 0;
    virtual void UpMoveUpdated() = 0;
    virtual Vector& LastMovementImpulses() = 0;
    virtual void LastMovementImpulsesUpdated() = 0;
    virtual QAngle& OldViewAngles() = 0;
    virtual void OldViewAnglesUpdated() = 0;
};

#endif // _INCLUDE_IPLAYER_MOVEMENTSERVICES_H
