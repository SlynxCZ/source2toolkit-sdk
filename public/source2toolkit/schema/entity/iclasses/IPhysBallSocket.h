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

#ifndef _INCLUDE_IPHYSBALLSOCKET_H
#define _INCLUDE_IPHYSBALLSOCKET_H

#pragma once

#include <cstdint>

#include "IPhysConstraint.h"

class IPhysBallSocket : public virtual IPhysConstraint
{
public:
    virtual ~IPhysBallSocket() = default;

    virtual float& JointFriction() = 0;
    virtual void JointFrictionUpdated() = 0;
    virtual bool& EnableSwingLimit() = 0;
    virtual void EnableSwingLimitUpdated() = 0;
    virtual float& SwingLimit() = 0;
    virtual void SwingLimitUpdated() = 0;
    virtual bool& EnableTwistLimit() = 0;
    virtual void EnableTwistLimitUpdated() = 0;
    virtual float& MinTwistAngle() = 0;
    virtual void MinTwistAngleUpdated() = 0;
    virtual float& MaxTwistAngle() = 0;
    virtual void MaxTwistAngleUpdated() = 0;
};

#endif // _INCLUDE_IPHYSBALLSOCKET_H
