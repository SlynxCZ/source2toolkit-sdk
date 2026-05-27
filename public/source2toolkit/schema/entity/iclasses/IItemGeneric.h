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

#ifndef _INCLUDE_IITEMGENERIC_H
#define _INCLUDE_IITEMGENERIC_H

#pragma once

#include <cstdint>

#include "IItem.h"

class CBaseFilter;
class CItemGenericTriggerHelper;
class InfoForResourceTypeIParticleSystemDefinition;

class IItemGeneric : public virtual IItem
{
public:
    virtual ~IItemGeneric() = default;

    virtual bool& HasTriggerRadius() = 0;
    virtual void HasTriggerRadiusUpdated() = 0;
    virtual bool& HasPickupRadius() = 0;
    virtual void HasPickupRadiusUpdated() = 0;
    virtual float& PickupRadiusSqr() = 0;
    virtual void PickupRadiusSqrUpdated() = 0;
    virtual float& TriggerRadiusSqr() = 0;
    virtual void TriggerRadiusSqrUpdated() = 0;
    virtual float& LastPickupCheck() = 0;
    virtual void LastPickupCheckUpdated() = 0;
    virtual bool& PlayerCounterListenerAdded() = 0;
    virtual void PlayerCounterListenerAddedUpdated() = 0;
    virtual bool& PlayerInTriggerRadius() = 0;
    virtual void PlayerInTriggerRadiusUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>& SpawnParticleEffect() = 0;
    virtual void SpawnParticleEffectUpdated() = 0;
    virtual CUtlSymbolLarge& AmbientSoundEffect() = 0;
    virtual void AmbientSoundEffectUpdated() = 0;
    virtual bool& AutoStartAmbientSound() = 0;
    virtual void AutoStartAmbientSoundUpdated() = 0;
    virtual CUtlSymbolLarge& SpawnScriptFunction() = 0;
    virtual void SpawnScriptFunctionUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>& PickupParticleEffect() = 0;
    virtual void PickupParticleEffectUpdated() = 0;
    virtual CUtlSymbolLarge& PickupSoundEffect() = 0;
    virtual void PickupSoundEffectUpdated() = 0;
    virtual CUtlSymbolLarge& PickupScriptFunction() = 0;
    virtual void PickupScriptFunctionUpdated() = 0;
    virtual CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>& TimeoutParticleEffect() = 0;
    virtual void TimeoutParticleEffectUpdated() = 0;
    virtual CUtlSymbolLarge& TimeoutSoundEffect() = 0;
    virtual void TimeoutSoundEffectUpdated() = 0;
    virtual CUtlSymbolLarge& TimeoutScriptFunction() = 0;
    virtual void TimeoutScriptFunctionUpdated() = 0;
    virtual CUtlSymbolLarge& PickupFilterName() = 0;
    virtual void PickupFilterNameUpdated() = 0;
    virtual CHandle<CBaseFilter>& PickupFilter() = 0;
    virtual void PickupFilterUpdated() = 0;
    virtual CEntityIOOutput& OnPickup() = 0;
    virtual void OnPickupUpdated() = 0;
    virtual CEntityIOOutput& OnTimeout() = 0;
    virtual void OnTimeoutUpdated() = 0;
    virtual CEntityIOOutput& OnTriggerStartTouch() = 0;
    virtual void OnTriggerStartTouchUpdated() = 0;
    virtual CEntityIOOutput& OnTriggerTouch() = 0;
    virtual void OnTriggerTouchUpdated() = 0;
    virtual CEntityIOOutput& OnTriggerEndTouch() = 0;
    virtual void OnTriggerEndTouchUpdated() = 0;
    virtual CUtlSymbolLarge& AllowPickupScriptFunction() = 0;
    virtual void AllowPickupScriptFunctionUpdated() = 0;
    virtual float& PickupRadius() = 0;
    virtual void PickupRadiusUpdated() = 0;
    virtual float& TriggerRadius() = 0;
    virtual void TriggerRadiusUpdated() = 0;
    virtual CUtlSymbolLarge& TriggerSoundEffect() = 0;
    virtual void TriggerSoundEffectUpdated() = 0;
    virtual bool& GlowWhenInTrigger() = 0;
    virtual void GlowWhenInTriggerUpdated() = 0;
    virtual Color& GlowColor() = 0;
    virtual void GlowColorUpdated() = 0;
    virtual bool& Useable() = 0;
    virtual void UseableUpdated() = 0;
    virtual CHandle<CItemGenericTriggerHelper>& TriggerHelper() = 0;
    virtual void TriggerHelperUpdated() = 0;
};

#endif // _INCLUDE_IITEMGENERIC_H
