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

#ifndef _INCLUDE_IBREAKABLEPROP_H
#define _INCLUDE_IBREAKABLEPROP_H

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

#include "IBaseProp.h"

#include "../enums/BreakableContentsType_t.h"
#include "../enums/PerformanceMode_t.h"

class CBaseEntity;
class CBasePlayerPawn;
class CBreakableProp;
class CPropDataComponent;

class IBreakableProp : public virtual IBaseProp
{
public:
    virtual ~IBreakableProp() = default;
    CBreakableProp* GetOriginal() { return reinterpret_cast<CBreakableProp*>(IEntityInstance::GetOriginal()); }

    virtual ::CPropDataComponent& PropDataComponent() = 0;
    virtual void PropDataComponentUpdated() = 0;
    virtual ::CEntityIOOutput& OnStartDeath() = 0;
    virtual void OnStartDeathUpdated() = 0;
    virtual ::CEntityIOOutput& OnBreak() = 0;
    virtual void OnBreakUpdated() = 0;
    virtual ::CEntityIOOutput& OnTakeDamage() = 0;
    virtual void OnTakeDamageUpdated() = 0;
    virtual float& ImpactEnergyScale() = 0;
    virtual void ImpactEnergyScaleUpdated() = 0;
    virtual int32_t& MinHealthDmg() = 0;
    virtual void MinHealthDmgUpdated() = 0;
    virtual QAngle& PreferredCarryAngles() = 0;
    virtual void PreferredCarryAnglesUpdated() = 0;
    virtual float& PressureDelay() = 0;
    virtual void PressureDelayUpdated() = 0;
    virtual float& DefBurstScale() = 0;
    virtual void DefBurstScaleUpdated() = 0;
    virtual Vector& DefBurstOffset() = 0;
    virtual void DefBurstOffsetUpdated() = 0;
    virtual CHandle<CBaseEntity>& Breaker() = 0;
    virtual void BreakerUpdated() = 0;
    virtual ::PerformanceMode_t& PerformanceMode() = 0;
    virtual void PerformanceModeUpdated() = 0;
    virtual float& PreventDamageBeforeTime() = 0;
    virtual void PreventDamageBeforeTimeUpdated() = 0;
    virtual ::BreakableContentsType_t& BreakableContentsType() = 0;
    virtual void BreakableContentsTypeUpdated() = 0;
    virtual CUtlString& StrBreakableContentsPropGroupOverride() = 0;
    virtual void StrBreakableContentsPropGroupOverrideUpdated() = 0;
    virtual CUtlString& StrBreakableContentsParticleOverride() = 0;
    virtual void StrBreakableContentsParticleOverrideUpdated() = 0;
    virtual bool& HasBreakPiecesOrCommands() = 0;
    virtual void HasBreakPiecesOrCommandsUpdated() = 0;
    virtual float& ExplodeDamage() = 0;
    virtual void ExplodeDamageUpdated() = 0;
    virtual float& ExplodeRadius() = 0;
    virtual void ExplodeRadiusUpdated() = 0;
    virtual CGlobalSymbol& ExplosionType() = 0;
    virtual void ExplosionTypeUpdated() = 0;
    virtual float& ExplosionDelay() = 0;
    virtual void ExplosionDelayUpdated() = 0;
    virtual CUtlSymbolLarge& ExplosionBuildupSound() = 0;
    virtual void ExplosionBuildupSoundUpdated() = 0;
    virtual CUtlSymbolLarge& ExplosionCustomEffect() = 0;
    virtual void ExplosionCustomEffectUpdated() = 0;
    virtual CUtlSymbolLarge& ExplosionCustomSound() = 0;
    virtual void ExplosionCustomSoundUpdated() = 0;
    virtual CUtlSymbolLarge& ExplosionModifier() = 0;
    virtual void ExplosionModifierUpdated() = 0;
    virtual CHandle<CBasePlayerPawn>& PhysicsAttacker() = 0;
    virtual void PhysicsAttackerUpdated() = 0;
    virtual float& LastPhysicsInfluenceTime() = 0;
    virtual void LastPhysicsInfluenceTimeUpdated() = 0;
    virtual float& DefaultFadeScale() = 0;
    virtual void DefaultFadeScaleUpdated() = 0;
    virtual CHandle<CBaseEntity>& LastAttacker() = 0;
    virtual void LastAttackerUpdated() = 0;
    virtual CUtlSymbolLarge& PuntSound() = 0;
    virtual void PuntSoundUpdated() = 0;
    virtual bool& UsePuntSound() = 0;
    virtual void UsePuntSoundUpdated() = 0;
    virtual bool& OriginalBlockLOS() = 0;
    virtual void OriginalBlockLOSUpdated() = 0;
    static IBreakableProp* FromOriginal(CBreakableProp* p);
};

#endif // _INCLUDE_IBREAKABLEPROP_H
