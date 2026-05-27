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

#ifndef _INCLUDE_ITRIGGERLOOK_H
#define _INCLUDE_ITRIGGERLOOK_H

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
#include <cstdint>

#include "ITriggerOnce.h"

class CBaseEntity;

class ITriggerLook : public virtual ITriggerOnce
{
public:
    virtual ~ITriggerLook() = default;

    virtual CHandle<CBaseEntity>& LookTarget() = 0;
    virtual void LookTargetUpdated() = 0;
    virtual float& FieldOfView() = 0;
    virtual void FieldOfViewUpdated() = 0;
    virtual float& LookTime() = 0;
    virtual void LookTimeUpdated() = 0;
    virtual float& LookTimeTotal() = 0;
    virtual void LookTimeTotalUpdated() = 0;
    virtual float& LookTimeLast() = 0;
    virtual void LookTimeLastUpdated() = 0;
    virtual float& TimeoutDuration() = 0;
    virtual void TimeoutDurationUpdated() = 0;
    virtual bool& TimeoutFired() = 0;
    virtual void TimeoutFiredUpdated() = 0;
    virtual bool& IsLooking() = 0;
    virtual void IsLookingUpdated() = 0;
    virtual bool& B2DFOV() = 0;
    virtual void B2DFOVUpdated() = 0;
    virtual bool& UseVelocity() = 0;
    virtual void UseVelocityUpdated() = 0;
    virtual bool& TestOcclusion() = 0;
    virtual void TestOcclusionUpdated() = 0;
    virtual bool& TestAllVisibleOcclusion() = 0;
    virtual void TestAllVisibleOcclusionUpdated() = 0;
    virtual CEntityIOOutput& OnTimeout() = 0;
    virtual void OnTimeoutUpdated() = 0;
    virtual CEntityIOOutput& OnStartLook() = 0;
    virtual void OnStartLookUpdated() = 0;
    virtual CEntityIOOutput& OnEndLook() = 0;
    virtual void OnEndLookUpdated() = 0;
};

#endif // _INCLUDE_ITRIGGERLOOK_H
