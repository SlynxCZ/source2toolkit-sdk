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

#ifndef _INCLUDE_IFISH_H
#define _INCLUDE_IFISH_H

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

#include "IBaseAnimGraph.h"

class CFish;
class CFishPool;
class CountdownTimer;

class IFish : public virtual IBaseAnimGraph
{
public:
    virtual ~IFish() = default;

    virtual CHandle<CFishPool>& Pool() = 0;
    virtual void PoolUpdated() = 0;
    virtual uint32_t& Id() = 0;
    virtual void IdUpdated() = 0;
    virtual float& X() = 0;
    virtual void XUpdated() = 0;
    virtual float& Y() = 0;
    virtual void YUpdated() = 0;
    virtual float& Z() = 0;
    virtual void ZUpdated() = 0;
    virtual float& Angle() = 0;
    virtual void AngleUpdated() = 0;
    virtual float& AngleChange() = 0;
    virtual void AngleChangeUpdated() = 0;
    virtual Vector& Forward() = 0;
    virtual void ForwardUpdated() = 0;
    virtual Vector& Perp() = 0;
    virtual void PerpUpdated() = 0;
    virtual Vector& PoolOrigin() = 0;
    virtual void PoolOriginUpdated() = 0;
    virtual float& WaterLevel() = 0;
    virtual void WaterLevelUpdated() = 0;
    virtual float& Speed() = 0;
    virtual void SpeedUpdated() = 0;
    virtual float& DesiredSpeed() = 0;
    virtual void DesiredSpeedUpdated() = 0;
    virtual float& CalmSpeed() = 0;
    virtual void CalmSpeedUpdated() = 0;
    virtual float& PanicSpeed() = 0;
    virtual void PanicSpeedUpdated() = 0;
    virtual float& AvoidRange() = 0;
    virtual void AvoidRangeUpdated() = 0;
    virtual ::CountdownTimer& TurnTimer() = 0;
    virtual void TurnTimerUpdated() = 0;
    virtual bool& TurnClockwise() = 0;
    virtual void TurnClockwiseUpdated() = 0;
    virtual ::CountdownTimer& GoTimer() = 0;
    virtual void GoTimerUpdated() = 0;
    virtual ::CountdownTimer& MoveTimer() = 0;
    virtual void MoveTimerUpdated() = 0;
    virtual ::CountdownTimer& PanicTimer() = 0;
    virtual void PanicTimerUpdated() = 0;
    virtual ::CountdownTimer& DisperseTimer() = 0;
    virtual void DisperseTimerUpdated() = 0;
    virtual ::CountdownTimer& ProximityTimer() = 0;
    virtual void ProximityTimerUpdated() = 0;
    virtual CUtlVector<CFish*>& Visible() = 0;
    virtual void VisibleUpdated() = 0;
    static IFish* FromOriginal(CFish* p);
    static IFish* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IFISH_H
