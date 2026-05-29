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

#ifndef _INCLUDE_ITRIGGERFAN_H
#define _INCLUDE_ITRIGGERFAN_H

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

#include "IBaseTrigger.h"

class CInfoFan;
class CTriggerFan;
class CountdownTimer;

class ITriggerFan : public virtual IBaseTrigger
{
public:
    virtual ~ITriggerFan() = default;
    CTriggerFan* GetOriginal() { return reinterpret_cast<CTriggerFan*>(IEntityInstance::GetOriginal()); }

    virtual Vector& FanOriginOffset() = 0;
    virtual void FanOriginOffsetUpdated() = 0;
    virtual Vector& Direction() = 0;
    virtual void DirectionUpdated() = 0;
    virtual bool& PushTowardsInfoTarget() = 0;
    virtual void PushTowardsInfoTargetUpdated() = 0;
    virtual bool& PushAwayFromInfoTarget() = 0;
    virtual void PushAwayFromInfoTargetUpdated() = 0;
    virtual Quaternion& NoiseDelta() = 0;
    virtual void NoiseDeltaUpdated() = 0;
    virtual CHandle<CInfoFan>& InfoFan() = 0;
    virtual void InfoFanUpdated() = 0;
    virtual float& Force() = 0;
    virtual void ForceUpdated() = 0;
    virtual bool& Falloff() = 0;
    virtual void FalloffUpdated() = 0;
    virtual ::CountdownTimer& RampTimer() = 0;
    virtual void RampTimerUpdated() = 0;
    virtual Vector& FanOriginWS() = 0;
    virtual void FanOriginWSUpdated() = 0;
    virtual Vector& FanOriginLS() = 0;
    virtual void FanOriginLSUpdated() = 0;
    virtual Vector& FanEndLS() = 0;
    virtual void FanEndLSUpdated() = 0;
    virtual Vector& NoiseDirectionTarget() = 0;
    virtual void NoiseDirectionTargetUpdated() = 0;
    virtual CUtlSymbolLarge& InfoFan() = 0;
    virtual void InfoFanUpdated() = 0;
    virtual float& RopeForceScale() = 0;
    virtual void RopeForceScaleUpdated() = 0;
    virtual float& ParticleForceScale() = 0;
    virtual void ParticleForceScaleUpdated() = 0;
    virtual float& PlayerForce() = 0;
    virtual void PlayerForceUpdated() = 0;
    virtual bool& PlayerWindblock() = 0;
    virtual void PlayerWindblockUpdated() = 0;
    virtual float& NPCForce() = 0;
    virtual void NPCForceUpdated() = 0;
    virtual float& RampTime() = 0;
    virtual void RampTimeUpdated() = 0;
    virtual float& NoiseDegrees() = 0;
    virtual void NoiseDegreesUpdated() = 0;
    virtual float& NoiseSpeed() = 0;
    virtual void NoiseSpeedUpdated() = 0;
    virtual bool& PushPlayer() = 0;
    virtual void PushPlayerUpdated() = 0;
    virtual bool& RampDown() = 0;
    virtual void RampDownUpdated() = 0;
    virtual int32_t& ManagerFanIdx() = 0;
    virtual void ManagerFanIdxUpdated() = 0;
    static ITriggerFan* FromOriginal(CTriggerFan* p);
};

#endif // _INCLUDE_ITRIGGERFAN_H
