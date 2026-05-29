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

#ifndef _INCLUDE_IENVSHAKE_H
#define _INCLUDE_IENVSHAKE_H

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

#include "IPointEntity.h"

class CEnvShake;
class CPhysicsShake;
class IPhysicsMotionController;

class IEnvShake : public virtual IPointEntity
{
public:
    virtual ~IEnvShake() = default;

    virtual CUtlSymbolLarge& LimitToEntity() = 0;
    virtual void LimitToEntityUpdated() = 0;
    virtual float& Amplitude() = 0;
    virtual void AmplitudeUpdated() = 0;
    virtual float& Frequency() = 0;
    virtual void FrequencyUpdated() = 0;
    virtual float& Duration() = 0;
    virtual void DurationUpdated() = 0;
    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual float& StopTime() = 0;
    virtual void StopTimeUpdated() = 0;
    virtual float& NextShake() = 0;
    virtual void NextShakeUpdated() = 0;
    virtual float& CurrentAmp() = 0;
    virtual void CurrentAmpUpdated() = 0;
    virtual Vector& MaxForce() = 0;
    virtual void MaxForceUpdated() = 0;
    virtual IPhysicsMotionController*& ShakeController() = 0;
    virtual void ShakeControllerUpdated() = 0;
    virtual ::CPhysicsShake& ShakeCallback() = 0;
    virtual void ShakeCallbackUpdated() = 0;
    static IEnvShake* FromOriginal(CEnvShake* p);
    static IEnvShake* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_IENVSHAKE_H
