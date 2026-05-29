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

#ifndef _INCLUDE_ISCRIPTEDSEQUENCE_H
#define _INCLUDE_ISCRIPTEDSEQUENCE_H

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

#include "IBaseEntity.h"

#include "../enums/ForcedCrouchState_t.h"
#include "../enums/ScriptedConflictResponse_t.h"
#include "../enums/ScriptedHeldWeaponBehavior_t.h"
#include "../enums/ScriptedMoveTo_t.h"
#include "../enums/ScriptedOnDeath_t.h"
#include "../enums/SharedMovementGait_t.h"

class CBaseAnimGraph;
class CBaseEntity;
class CScriptedSequence;

class IScriptedSequence : public virtual IBaseEntity
{
public:
    virtual ~IScriptedSequence() = default;

    virtual CUtlSymbolLarge& Entry() = 0;
    virtual void EntryUpdated() = 0;
    virtual CUtlSymbolLarge& PreIdle() = 0;
    virtual void PreIdleUpdated() = 0;
    virtual CUtlSymbolLarge& Play() = 0;
    virtual void PlayUpdated() = 0;
    virtual CUtlSymbolLarge& PostIdle() = 0;
    virtual void PostIdleUpdated() = 0;
    virtual CUtlSymbolLarge& ModifierToAddOnPlay() = 0;
    virtual void ModifierToAddOnPlayUpdated() = 0;
    virtual CUtlSymbolLarge& NextScript() = 0;
    virtual void NextScriptUpdated() = 0;
    virtual CUtlSymbolLarge& Entity() = 0;
    virtual void EntityUpdated() = 0;
    virtual CUtlSymbolLarge& SyncGroup() = 0;
    virtual void SyncGroupUpdated() = 0;
    virtual ::ScriptedMoveTo_t& MoveTo() = 0;
    virtual void MoveToUpdated() = 0;
    virtual ::SharedMovementGait_t& MoveToGait() = 0;
    virtual void MoveToGaitUpdated() = 0;
    virtual ::ScriptedHeldWeaponBehavior_t& HeldWeaponBehavior() = 0;
    virtual void HeldWeaponBehaviorUpdated() = 0;
    virtual ::ForcedCrouchState_t& ForcedCrouchState() = 0;
    virtual void ForcedCrouchStateUpdated() = 0;
    virtual bool& IsPlayingPreIdle() = 0;
    virtual void IsPlayingPreIdleUpdated() = 0;
    virtual bool& IsPlayingEntry() = 0;
    virtual void IsPlayingEntryUpdated() = 0;
    virtual bool& IsPlayingAction() = 0;
    virtual void IsPlayingActionUpdated() = 0;
    virtual bool& IsPlayingPostIdle() = 0;
    virtual void IsPlayingPostIdleUpdated() = 0;
    virtual bool& DontRotateOther() = 0;
    virtual void DontRotateOtherUpdated() = 0;
    virtual bool& IsRepeatable() = 0;
    virtual void IsRepeatableUpdated() = 0;
    virtual bool& ShouldLeaveCorpse() = 0;
    virtual void ShouldLeaveCorpseUpdated() = 0;
    virtual bool& StartOnSpawn() = 0;
    virtual void StartOnSpawnUpdated() = 0;
    virtual bool& DisallowInterrupts() = 0;
    virtual void DisallowInterruptsUpdated() = 0;
    virtual bool& CanOverrideNPCState() = 0;
    virtual void CanOverrideNPCStateUpdated() = 0;
    virtual bool& DontTeleportAtEnd() = 0;
    virtual void DontTeleportAtEndUpdated() = 0;
    virtual bool& HighPriority() = 0;
    virtual void HighPriorityUpdated() = 0;
    virtual bool& HideDebugComplaints() = 0;
    virtual void HideDebugComplaintsUpdated() = 0;
    virtual bool& ContinueOnDeath() = 0;
    virtual void ContinueOnDeathUpdated() = 0;
    virtual bool& LoopPreIdleSequence() = 0;
    virtual void LoopPreIdleSequenceUpdated() = 0;
    virtual bool& LoopActionSequence() = 0;
    virtual void LoopActionSequenceUpdated() = 0;
    virtual bool& LoopPostIdleSequence() = 0;
    virtual void LoopPostIdleSequenceUpdated() = 0;
    virtual bool& SynchPostIdles() = 0;
    virtual void SynchPostIdlesUpdated() = 0;
    virtual bool& IgnoreLookAt() = 0;
    virtual void IgnoreLookAtUpdated() = 0;
    virtual bool& IgnoreGravity() = 0;
    virtual void IgnoreGravityUpdated() = 0;
    virtual bool& DisableNPCCollisions() = 0;
    virtual void DisableNPCCollisionsUpdated() = 0;
    virtual bool& KeepAnimgraphLockedPost() = 0;
    virtual void KeepAnimgraphLockedPostUpdated() = 0;
    virtual bool& DontAddModifiers() = 0;
    virtual void DontAddModifiersUpdated() = 0;
    virtual bool& DisableAimingWhileMoving() = 0;
    virtual void DisableAimingWhileMovingUpdated() = 0;
    virtual bool& IgnoreRotation() = 0;
    virtual void IgnoreRotationUpdated() = 0;
    virtual float& Radius() = 0;
    virtual void RadiusUpdated() = 0;
    virtual float& Repeat() = 0;
    virtual void RepeatUpdated() = 0;
    virtual float& PlayAnimFadeInTime() = 0;
    virtual void PlayAnimFadeInTimeUpdated() = 0;
    virtual float& MoveInterpTime() = 0;
    virtual void MoveInterpTimeUpdated() = 0;
    virtual float& AngRate() = 0;
    virtual void AngRateUpdated() = 0;
    virtual float& MoveSpeed() = 0;
    virtual void MoveSpeedUpdated() = 0;
    virtual bool& WaitUntilMoveCompletesToStartAnimation() = 0;
    virtual void WaitUntilMoveCompletesToStartAnimationUpdated() = 0;
    virtual int32_t& NotReadySequenceCount() = 0;
    virtual void NotReadySequenceCountUpdated() = 0;
    virtual float& StartTime() = 0;
    virtual void StartTimeUpdated() = 0;
    virtual bool& WaitForBeginSequence() = 0;
    virtual void WaitForBeginSequenceUpdated() = 0;
    virtual int32_t& Saved_effects() = 0;
    virtual void Saved_effectsUpdated() = 0;
    virtual int32_t& SavedFlags() = 0;
    virtual void SavedFlagsUpdated() = 0;
    virtual int32_t& SavedCollisionGroup() = 0;
    virtual void SavedCollisionGroupUpdated() = 0;
    virtual bool& Interruptable() = 0;
    virtual void InterruptableUpdated() = 0;
    virtual bool& SequenceStarted() = 0;
    virtual void SequenceStartedUpdated() = 0;
    virtual bool& PositionRelativeToOtherEntity() = 0;
    virtual void PositionRelativeToOtherEntityUpdated() = 0;
    virtual CHandle<CBaseEntity>& TargetEnt() = 0;
    virtual void TargetEntUpdated() = 0;
    virtual CHandle<CScriptedSequence>& NextCine() = 0;
    virtual void NextCineUpdated() = 0;
    virtual bool& Thinking() = 0;
    virtual void ThinkingUpdated() = 0;
    virtual bool& InitiatedSelfDelete() = 0;
    virtual void InitiatedSelfDeleteUpdated() = 0;
    virtual bool& IsTeleportingDueToMoveTo() = 0;
    virtual void IsTeleportingDueToMoveToUpdated() = 0;
    virtual bool& AllowCustomInterruptConditions() = 0;
    virtual void AllowCustomInterruptConditionsUpdated() = 0;
    virtual CHandle<CBaseAnimGraph>& ForcedTarget() = 0;
    virtual void ForcedTargetUpdated() = 0;
    virtual bool& DontCancelOtherSequences() = 0;
    virtual void DontCancelOtherSequencesUpdated() = 0;
    virtual bool& ForceSynch() = 0;
    virtual void ForceSynchUpdated() = 0;
    virtual bool& PreventUpdateYawOnFinish() = 0;
    virtual void PreventUpdateYawOnFinishUpdated() = 0;
    virtual bool& EnsureOnNavmeshOnFinish() = 0;
    virtual void EnsureOnNavmeshOnFinishUpdated() = 0;
    virtual ::ScriptedOnDeath_t& OnDeathBehavior() = 0;
    virtual void OnDeathBehaviorUpdated() = 0;
    virtual ::ScriptedConflictResponse_t& ConflictResponse() = 0;
    virtual void ConflictResponseUpdated() = 0;
    virtual ::CEntityIOOutput& OnBeginSequence() = 0;
    virtual void OnBeginSequenceUpdated() = 0;
    virtual ::CEntityIOOutput& OnActionStartOrLoop() = 0;
    virtual void OnActionStartOrLoopUpdated() = 0;
    virtual ::CEntityIOOutput& OnEndSequence() = 0;
    virtual void OnEndSequenceUpdated() = 0;
    virtual ::CEntityIOOutput& OnPostIdleEndSequence() = 0;
    virtual void OnPostIdleEndSequenceUpdated() = 0;
    virtual ::CEntityIOOutput& OnCancelSequence() = 0;
    virtual void OnCancelSequenceUpdated() = 0;
    virtual ::CEntityIOOutput& OnCancelFailedSequence() = 0;
    virtual void OnCancelFailedSequenceUpdated() = 0;
    virtual CEntityIOOutput* OnScriptEvent() = 0;
    virtual CTransform& MatOtherToMain() = 0;
    virtual void MatOtherToMainUpdated() = 0;
    virtual CHandle<CBaseEntity>& InteractionMainEntity() = 0;
    virtual void InteractionMainEntityUpdated() = 0;
    virtual int32_t& PlayerDeathBehavior() = 0;
    virtual void PlayerDeathBehaviorUpdated() = 0;
    virtual bool& SkipFadeIn() = 0;
    virtual void SkipFadeInUpdated() = 0;
    static IScriptedSequence* FromOriginal(CScriptedSequence* p);
};

#endif // _INCLUDE_ISCRIPTEDSEQUENCE_H
