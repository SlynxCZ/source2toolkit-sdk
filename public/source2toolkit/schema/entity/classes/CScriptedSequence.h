#pragma once
#include "CBaseEntity.h"
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

#include "CBaseEntity.h"
#include "../enums/ForcedCrouchState_t.h"
#include "../enums/ScriptedConflictResponse_t.h"
#include "../enums/ScriptedHeldWeaponBehavior_t.h"
#include "../enums/ScriptedMoveTo_t.h"
#include "../enums/ScriptedOnDeath_t.h"
#include "../enums/SharedMovementGait_t.h"

class CBaseAnimGraph;

class CScriptedSequence : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CScriptedSequence);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEntry);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPreIdle);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPlay);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPostIdle);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszModifierToAddOnPlay);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszNextScript);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEntity);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSyncGroup);
    SCHEMA_FIELD(ScriptedMoveTo_t, m_nMoveTo);
    SCHEMA_FIELD(SharedMovementGait_t, m_nMoveToGait);
    SCHEMA_FIELD(ScriptedHeldWeaponBehavior_t, m_nHeldWeaponBehavior);
    SCHEMA_FIELD(ForcedCrouchState_t, m_nForcedCrouchState);
    SCHEMA_FIELD(bool, m_bIsPlayingPreIdle);
    SCHEMA_FIELD(bool, m_bIsPlayingEntry);
    SCHEMA_FIELD(bool, m_bIsPlayingAction);
    SCHEMA_FIELD(bool, m_bIsPlayingPostIdle);
    SCHEMA_FIELD(bool, m_bDontRotateOther);
    SCHEMA_FIELD(bool, m_bIsRepeatable);
    SCHEMA_FIELD(bool, m_bShouldLeaveCorpse);
    SCHEMA_FIELD(bool, m_bStartOnSpawn);
    SCHEMA_FIELD(bool, m_bDisallowInterrupts);
    SCHEMA_FIELD(bool, m_bCanOverrideNPCState);
    SCHEMA_FIELD(bool, m_bDontTeleportAtEnd);
    SCHEMA_FIELD(bool, m_bHighPriority);
    SCHEMA_FIELD(bool, m_bHideDebugComplaints);
    SCHEMA_FIELD(bool, m_bContinueOnDeath);
    SCHEMA_FIELD(bool, m_bLoopPreIdleSequence);
    SCHEMA_FIELD(bool, m_bLoopActionSequence);
    SCHEMA_FIELD(bool, m_bLoopPostIdleSequence);
    SCHEMA_FIELD(bool, m_bSynchPostIdles);
    SCHEMA_FIELD(bool, m_bIgnoreLookAt);
    SCHEMA_FIELD(bool, m_bIgnoreGravity);
    SCHEMA_FIELD(bool, m_bDisableNPCCollisions);
    SCHEMA_FIELD(bool, m_bKeepAnimgraphLockedPost);
    SCHEMA_FIELD(bool, m_bDontAddModifiers);
    SCHEMA_FIELD(bool, m_bDisableAimingWhileMoving);
    SCHEMA_FIELD(bool, m_bIgnoreRotation);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(float, m_flRepeat);
    SCHEMA_FIELD(float, m_flPlayAnimFadeInTime);
    SCHEMA_FIELD(float, m_flMoveInterpTime);
    SCHEMA_FIELD(float, m_flAngRate);
    SCHEMA_FIELD(float, m_flMoveSpeed);
    SCHEMA_FIELD(bool, m_bWaitUntilMoveCompletesToStartAnimation);
    SCHEMA_FIELD(int32_t, m_nNotReadySequenceCount);
    SCHEMA_FIELD(float, m_startTime);
    SCHEMA_FIELD(bool, m_bWaitForBeginSequence);
    SCHEMA_FIELD(int32_t, m_saved_effects);
    SCHEMA_FIELD(int32_t, m_savedFlags);
    SCHEMA_FIELD(int32_t, m_savedCollisionGroup);
    SCHEMA_FIELD(bool, m_bInterruptable);
    SCHEMA_FIELD(bool, m_sequenceStarted);
    SCHEMA_FIELD(bool, m_bPositionRelativeToOtherEntity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetEnt);
    SCHEMA_FIELD(CHandle<CScriptedSequence>, m_hNextCine);
    SCHEMA_FIELD(bool, m_bThinking);
    SCHEMA_FIELD(bool, m_bInitiatedSelfDelete);
    SCHEMA_FIELD(bool, m_bIsTeleportingDueToMoveTo);
    SCHEMA_FIELD(bool, m_bAllowCustomInterruptConditions);
    SCHEMA_FIELD(CHandle<CBaseAnimGraph>, m_hForcedTarget);
    SCHEMA_FIELD(bool, m_bDontCancelOtherSequences);
    SCHEMA_FIELD(bool, m_bForceSynch);
    SCHEMA_FIELD(bool, m_bPreventUpdateYawOnFinish);
    SCHEMA_FIELD(bool, m_bEnsureOnNavmeshOnFinish);
    SCHEMA_FIELD(ScriptedOnDeath_t, m_onDeathBehavior);
    SCHEMA_FIELD(ScriptedConflictResponse_t, m_ConflictResponse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBeginSequence);
    SCHEMA_FIELD(CEntityIOOutput, m_OnActionStartOrLoop);
    SCHEMA_FIELD(CEntityIOOutput, m_OnEndSequence);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPostIdleEndSequence);
    SCHEMA_FIELD(CEntityIOOutput, m_OnCancelSequence);
    SCHEMA_FIELD(CEntityIOOutput, m_OnCancelFailedSequence);
    SCHEMA_FIELD_POINTER(CEntityIOOutput, m_OnScriptEvent);
    SCHEMA_FIELD(CTransform, m_matOtherToMain);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hInteractionMainEntity);
    SCHEMA_FIELD(int32_t, m_iPlayerDeathBehavior);
    SCHEMA_FIELD(bool, m_bSkipFadeIn);

public:
    static CScriptedSequence* New(const char* className)
    {
        return CBaseEntity::New<CScriptedSequence>(className);
    }

    static CScriptedSequence* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CScriptedSequence>(iIndex);
    }

    static CScriptedSequence* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
