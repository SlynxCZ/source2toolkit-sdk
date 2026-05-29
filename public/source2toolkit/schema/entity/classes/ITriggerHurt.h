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

#ifndef _INCLUDE_ITRIGGERHURT_H
#define _INCLUDE_ITRIGGERHURT_H

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

#include "../enums/DamageTypes_t.h"

class CBaseEntity;
class CTriggerHurt;

class ITriggerHurt : public virtual IBaseTrigger
{
public:
    virtual ~ITriggerHurt() = default;

    virtual float& OriginalDamage() = 0;
    virtual void OriginalDamageUpdated() = 0;
    virtual float& Damage() = 0;
    virtual void DamageUpdated() = 0;
    virtual float& DamageCap() = 0;
    virtual void DamageCapUpdated() = 0;
    virtual float& LastDmgTime() = 0;
    virtual void LastDmgTimeUpdated() = 0;
    virtual float& ForgivenessDelay() = 0;
    virtual void ForgivenessDelayUpdated() = 0;
    virtual ::DamageTypes_t& BitsDamageInflict() = 0;
    virtual void BitsDamageInflictUpdated() = 0;
    virtual int32_t& DamageModel() = 0;
    virtual void DamageModelUpdated() = 0;
    virtual bool& NoDmgForce() = 0;
    virtual void NoDmgForceUpdated() = 0;
    virtual Vector& DamageForce() = 0;
    virtual void DamageForceUpdated() = 0;
    virtual bool& ThinkAlways() = 0;
    virtual void ThinkAlwaysUpdated() = 0;
    virtual float& HurtThinkPeriod() = 0;
    virtual void HurtThinkPeriodUpdated() = 0;
    virtual ::CEntityIOOutput& OnHurt() = 0;
    virtual void OnHurtUpdated() = 0;
    virtual ::CEntityIOOutput& OnHurtPlayer() = 0;
    virtual void OnHurtPlayerUpdated() = 0;
    virtual CUtlVector<CHandle<CBaseEntity>>& HurtEntities() = 0;
    virtual void HurtEntitiesUpdated() = 0;
    static ITriggerHurt* FromOriginal(CTriggerHurt* p);
    static ITriggerHurt* FromRaw(CEntityInstance* p);
};

#endif // _INCLUDE_ITRIGGERHURT_H
