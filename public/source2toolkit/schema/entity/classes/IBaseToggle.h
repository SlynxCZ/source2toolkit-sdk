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

#ifndef _INCLUDE_IBASETOGGLE_H
#define _INCLUDE_IBASETOGGLE_H

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

#include "IBaseModelEntity.h"

#include "../enums/TOGGLE_STATE.h"

class CBaseEntity;
class CBaseToggle;

class IBaseToggle : public virtual IBaseModelEntity
{
public:
    virtual ~IBaseToggle() = default;
    CBaseToggle* GetOriginal() { return reinterpret_cast<CBaseToggle*>(IEntityInstance::GetOriginal()); }

    virtual ::TOGGLE_STATE& Toggle_state() = 0;
    virtual void Toggle_stateUpdated() = 0;
    virtual float& MoveDistance() = 0;
    virtual void MoveDistanceUpdated() = 0;
    virtual float& Wait() = 0;
    virtual void WaitUpdated() = 0;
    virtual float& Lip() = 0;
    virtual void LipUpdated() = 0;
    virtual bool& AlwaysFireBlockedOutputs() = 0;
    virtual void AlwaysFireBlockedOutputsUpdated() = 0;
    virtual Vector& Position1() = 0;
    virtual void Position1Updated() = 0;
    virtual Vector& Position2() = 0;
    virtual void Position2Updated() = 0;
    virtual QAngle& MoveAng() = 0;
    virtual void MoveAngUpdated() = 0;
    virtual QAngle& Angle1() = 0;
    virtual void Angle1Updated() = 0;
    virtual QAngle& Angle2() = 0;
    virtual void Angle2Updated() = 0;
    virtual float& Height() = 0;
    virtual void HeightUpdated() = 0;
    virtual CHandle<CBaseEntity>& Activator() = 0;
    virtual void ActivatorUpdated() = 0;
    virtual Vector& FinalDest() = 0;
    virtual void FinalDestUpdated() = 0;
    virtual QAngle& FinalAngle() = 0;
    virtual void FinalAngleUpdated() = 0;
    virtual int32_t& MovementType() = 0;
    virtual void MovementTypeUpdated() = 0;
    virtual CUtlSymbolLarge& Master() = 0;
    virtual void MasterUpdated() = 0;
    static IBaseToggle* FromOriginal(CBaseToggle* p);
};

#endif // _INCLUDE_IBASETOGGLE_H
