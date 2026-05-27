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

#ifndef _INCLUDE_IPLANTEDC4_H
#define _INCLUDE_IPLANTEDC4_H

#pragma once

#include <cstdint>

#include "IBaseAnimGraph.h"

#include "CAttributeContainer.h"
#include "EntitySpottedState_t.h"

class CCSPlayerPawn;

class IPlantedC4 : public virtual IBaseAnimGraph
{
public:
    virtual ~IPlantedC4() = default;

    virtual bool& BombTicking() = 0;
    virtual void BombTickingUpdated() = 0;
    virtual float& C4Blow() = 0;
    virtual void C4BlowUpdated() = 0;
    virtual int32_t& BombSite() = 0;
    virtual void BombSiteUpdated() = 0;
    virtual int32_t& SourceSoundscapeHash() = 0;
    virtual void SourceSoundscapeHashUpdated() = 0;
    virtual bool& AbortDetonationBecauseWorldIsFrozen() = 0;
    virtual void AbortDetonationBecauseWorldIsFrozenUpdated() = 0;
    virtual CAttributeContainer& AttributeManager() = 0;
    virtual void AttributeManagerUpdated() = 0;
    virtual CEntityIOOutput& OnBombDefused() = 0;
    virtual void OnBombDefusedUpdated() = 0;
    virtual CEntityIOOutput& OnBombBeginDefuse() = 0;
    virtual void OnBombBeginDefuseUpdated() = 0;
    virtual CEntityIOOutput& OnBombDefuseAborted() = 0;
    virtual void OnBombDefuseAbortedUpdated() = 0;
    virtual bool& CannotBeDefused() = 0;
    virtual void CannotBeDefusedUpdated() = 0;
    virtual EntitySpottedState_t& EntitySpottedState() = 0;
    virtual void EntitySpottedStateUpdated() = 0;
    virtual int32_t& SpotRules() = 0;
    virtual void SpotRulesUpdated() = 0;
    virtual bool& HasExploded() = 0;
    virtual void HasExplodedUpdated() = 0;
    virtual bool& BombDefused() = 0;
    virtual void BombDefusedUpdated() = 0;
    virtual bool& TrainingPlacedByPlayer() = 0;
    virtual void TrainingPlacedByPlayerUpdated() = 0;
    virtual float& TimerLength() = 0;
    virtual void TimerLengthUpdated() = 0;
    virtual bool& BeingDefused() = 0;
    virtual void BeingDefusedUpdated() = 0;
    virtual float& LastDefuseTime() = 0;
    virtual void LastDefuseTimeUpdated() = 0;
    virtual float& DefuseLength() = 0;
    virtual void DefuseLengthUpdated() = 0;
    virtual float& DefuseCountDown() = 0;
    virtual void DefuseCountDownUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& BombDefuser() = 0;
    virtual void BombDefuserUpdated() = 0;
    virtual int32_t& ProgressBarTime() = 0;
    virtual void ProgressBarTimeUpdated() = 0;
    virtual bool& VoiceAlertFired() = 0;
    virtual void VoiceAlertFiredUpdated() = 0;
    virtual bool* VoiceAlertPlayed() = 0;
    virtual float& NextBotBeepTime() = 0;
    virtual void NextBotBeepTimeUpdated() = 0;
    virtual QAngle& CatchUpToPlayerEye() = 0;
    virtual void CatchUpToPlayerEyeUpdated() = 0;
    virtual float& LastSpinDetectionTime() = 0;
    virtual void LastSpinDetectionTimeUpdated() = 0;
};

#endif // _INCLUDE_IPLANTEDC4_H
