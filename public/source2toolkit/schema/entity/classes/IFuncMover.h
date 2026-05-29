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

#ifndef _INCLUDE_IFUNCMOVER_H
#define _INCLUDE_IFUNCMOVER_H

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

#include "../enums/CFuncMover__FollowConstraint_t.h"
#include "../enums/CFuncMover__FollowEntityDirection_t.h"
#include "../enums/CFuncMover__Move_t.h"
#include "../enums/CFuncMover__OrientationUpdate_t.h"
#include "../enums/CFuncMover__TransitionToPathNodeAction_t.h"

class CBaseEntity;
class CFuncMover;
class CMoverPathNode;
class CPathMover;
class FuncMoverMovementSummary_t;

class IFuncMover : public virtual IBaseModelEntity
{
public:
    virtual ~IFuncMover() = default;

    virtual CUtlSymbolLarge& PathName() = 0;
    virtual void PathNameUpdated() = 0;
    virtual CHandle<CPathMover>& PathMover() = 0;
    virtual void PathMoverUpdated() = 0;
    virtual CHandle<CPathMover>& PrevPathMover() = 0;
    virtual void PrevPathMoverUpdated() = 0;
    virtual CUtlSymbolLarge& PathNodeStart() = 0;
    virtual void PathNodeStartUpdated() = 0;
    virtual CUtlSymbolLarge& PathNodeEnd() = 0;
    virtual void PathNodeEndUpdated() = 0;
    virtual bool& IgnoreEndNode() = 0;
    virtual void IgnoreEndNodeUpdated() = 0;
    virtual ::CFuncMover__Move_t& MoveType() = 0;
    virtual void MoveTypeUpdated() = 0;
    virtual bool& IsReversing() = 0;
    virtual void IsReversingUpdated() = 0;
    virtual float& StartSpeed() = 0;
    virtual void StartSpeedUpdated() = 0;
    virtual float& PathLocation() = 0;
    virtual void PathLocationUpdated() = 0;
    virtual float& T() = 0;
    virtual void TUpdated() = 0;
    virtual int32_t& CurrentNodeIndex() = 0;
    virtual void CurrentNodeIndexUpdated() = 0;
    virtual int32_t& PreviousNodeIndex() = 0;
    virtual void PreviousNodeIndexUpdated() = 0;
    virtual ::SolidType_t& SolidType() = 0;
    virtual void SolidTypeUpdated() = 0;
    virtual bool& IsMoving() = 0;
    virtual void IsMovingUpdated() = 0;
    virtual float& TimeToReachMaxSpeed() = 0;
    virtual void TimeToReachMaxSpeedUpdated() = 0;
    virtual float& DistanceToReachMaxSpeed() = 0;
    virtual void DistanceToReachMaxSpeedUpdated() = 0;
    virtual float& TimeToReachZeroSpeed() = 0;
    virtual void TimeToReachZeroSpeedUpdated() = 0;
    virtual float& ComputedDistanceToReachMaxSpeed() = 0;
    virtual void ComputedDistanceToReachMaxSpeedUpdated() = 0;
    virtual float& ComputedDistanceToReachZeroSpeed() = 0;
    virtual void ComputedDistanceToReachZeroSpeedUpdated() = 0;
    virtual float& StartCurveScale() = 0;
    virtual void StartCurveScaleUpdated() = 0;
    virtual float& StopCurveScale() = 0;
    virtual void StopCurveScaleUpdated() = 0;
    virtual float& DistanceToReachZeroSpeed() = 0;
    virtual void DistanceToReachZeroSpeedUpdated() = 0;
    virtual float& TimeMovementStart() = 0;
    virtual void TimeMovementStartUpdated() = 0;
    virtual float& TimeMovementStop() = 0;
    virtual void TimeMovementStopUpdated() = 0;
    virtual CHandle<CMoverPathNode>& StopAtNode() = 0;
    virtual void StopAtNodeUpdated() = 0;
    virtual float& PathLocationToBeginStop() = 0;
    virtual void PathLocationToBeginStopUpdated() = 0;
    virtual float& PathLocationStart() = 0;
    virtual void PathLocationStartUpdated() = 0;
    virtual float& BeginStopT() = 0;
    virtual void BeginStopTUpdated() = 0;
    virtual CUtlSymbolLarge& StartForwardSound() = 0;
    virtual void StartForwardSoundUpdated() = 0;
    virtual CUtlSymbolLarge& LoopForwardSound() = 0;
    virtual void LoopForwardSoundUpdated() = 0;
    virtual CUtlSymbolLarge& StopForwardSound() = 0;
    virtual void StopForwardSoundUpdated() = 0;
    virtual CUtlSymbolLarge& StartReverseSound() = 0;
    virtual void StartReverseSoundUpdated() = 0;
    virtual CUtlSymbolLarge& LoopReverseSound() = 0;
    virtual void LoopReverseSoundUpdated() = 0;
    virtual CUtlSymbolLarge& StopReverseSound() = 0;
    virtual void StopReverseSoundUpdated() = 0;
    virtual CUtlSymbolLarge& ArriveAtDestinationSound() = 0;
    virtual void ArriveAtDestinationSoundUpdated() = 0;
    virtual ::CEntityIOOutput& OnMovementEnd() = 0;
    virtual void OnMovementEndUpdated() = 0;
    virtual bool& StartAtClosestPoint() = 0;
    virtual void StartAtClosestPointUpdated() = 0;
    virtual bool& StartAtEnd() = 0;
    virtual void StartAtEndUpdated() = 0;
    virtual bool& StartFollowingClosestMover() = 0;
    virtual void StartFollowingClosestMoverUpdated() = 0;
    virtual ::CFuncMover__OrientationUpdate_t& OrientationUpdate() = 0;
    virtual void OrientationUpdateUpdated() = 0;
    virtual float& TimeStartOrientationChange() = 0;
    virtual void TimeStartOrientationChangeUpdated() = 0;
    virtual float& TimeToBlendToNewOrientation() = 0;
    virtual void TimeToBlendToNewOrientationUpdated() = 0;
    virtual float& DurationBlendToNewOrientationRan() = 0;
    virtual void DurationBlendToNewOrientationRanUpdated() = 0;
    virtual bool& CreateMovableNavMesh() = 0;
    virtual void CreateMovableNavMeshUpdated() = 0;
    virtual bool& AllowMovableNavMeshDockingOnEntireEntity() = 0;
    virtual void AllowMovableNavMeshDockingOnEntireEntityUpdated() = 0;
    virtual CUtlSymbolLarge& OrientationMatchEntityName() = 0;
    virtual void OrientationMatchEntityNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& OrientationMatchEntity() = 0;
    virtual void OrientationMatchEntityUpdated() = 0;
    virtual float& TimeToTraverseToNextNode() = 0;
    virtual void TimeToTraverseToNextNodeUpdated() = 0;
    virtual Vector& LerpToNewPosStartInPathEntitySpace() = 0;
    virtual void LerpToNewPosStartInPathEntitySpaceUpdated() = 0;
    virtual Vector& LerpToNewPosEndInPathEntitySpace() = 0;
    virtual void LerpToNewPosEndInPathEntitySpaceUpdated() = 0;
    virtual float& LerpToPositionT() = 0;
    virtual void LerpToPositionTUpdated() = 0;
    virtual float& LerpToPositionDeltaT() = 0;
    virtual void LerpToPositionDeltaTUpdated() = 0;
    virtual ::CEntityIOOutput& OnLerpToPositionComplete() = 0;
    virtual void OnLerpToPositionCompleteUpdated() = 0;
    virtual bool& IsPaused() = 0;
    virtual void IsPausedUpdated() = 0;
    virtual ::CFuncMover__TransitionToPathNodeAction_t& TransitionedToPathNodeAction() = 0;
    virtual void TransitionedToPathNodeActionUpdated() = 0;
    virtual Quaternion& TransitionSourceOrientation() = 0;
    virtual void TransitionSourceOrientationUpdated() = 0;
    virtual int32_t& DelayedTeleportToNode() = 0;
    virtual void DelayedTeleportToNodeUpdated() = 0;
    virtual bool& IsImGuiLogging() = 0;
    virtual void IsImGuiLoggingUpdated() = 0;
    virtual CHandle<CBaseEntity>& FollowEntity() = 0;
    virtual void FollowEntityUpdated() = 0;
    virtual float& FollowDistance() = 0;
    virtual void FollowDistanceUpdated() = 0;
    virtual float& FollowMinimumSpeed() = 0;
    virtual void FollowMinimumSpeedUpdated() = 0;
    virtual float& CurFollowEntityT() = 0;
    virtual void CurFollowEntityTUpdated() = 0;
    virtual float& CurFollowSpeed() = 0;
    virtual void CurFollowSpeedUpdated() = 0;
    virtual CUtlSymbolLarge& StrOrientationFaceEntityName() = 0;
    virtual void StrOrientationFaceEntityNameUpdated() = 0;
    virtual CHandle<CBaseEntity>& OrientationFaceEntity() = 0;
    virtual void OrientationFaceEntityUpdated() = 0;
    virtual ::CEntityIOOutput& OnStart() = 0;
    virtual void OnStartUpdated() = 0;
    virtual ::CEntityIOOutput& OnStartForward() = 0;
    virtual void OnStartForwardUpdated() = 0;
    virtual ::CEntityIOOutput& OnStartReverse() = 0;
    virtual void OnStartReverseUpdated() = 0;
    virtual ::CEntityIOOutput& OnStop() = 0;
    virtual void OnStopUpdated() = 0;
    virtual ::CEntityIOOutput& OnStopped() = 0;
    virtual void OnStoppedUpdated() = 0;
    virtual bool& NextNodeReturnsCurrent() = 0;
    virtual void NextNodeReturnsCurrentUpdated() = 0;
    virtual bool& StartedMoving() = 0;
    virtual void StartedMovingUpdated() = 0;
    virtual ::CFuncMover__FollowEntityDirection_t& FollowEntityDirection() = 0;
    virtual void FollowEntityDirectionUpdated() = 0;
    virtual CHandle<CFuncMover>& FollowMover() = 0;
    virtual void FollowMoverUpdated() = 0;
    virtual CUtlSymbolLarge& FollowMoverEntityName() = 0;
    virtual void FollowMoverEntityNameUpdated() = 0;
    virtual float& FollowMoverDistance() = 0;
    virtual void FollowMoverDistanceUpdated() = 0;
    virtual float& FollowMoverRatio() = 0;
    virtual void FollowMoverRatioUpdated() = 0;
    virtual float& FollowMoverCalculatedDistance() = 0;
    virtual void FollowMoverCalculatedDistanceUpdated() = 0;
    virtual float& FollowMoverSpringStrength() = 0;
    virtual void FollowMoverSpringStrengthUpdated() = 0;
    virtual int32_t& FollowMoverConstraintPriority() = 0;
    virtual void FollowMoverConstraintPriorityUpdated() = 0;
    virtual bool& FollowConstraintsInitialized() = 0;
    virtual void FollowConstraintsInitializedUpdated() = 0;
    virtual ::CFuncMover__FollowConstraint_t& FollowConstraint() = 0;
    virtual void FollowConstraintUpdated() = 0;
    virtual float& FollowMoverSpeed() = 0;
    virtual void FollowMoverSpeedUpdated() = 0;
    virtual float& FollowMoverVelocity() = 0;
    virtual void FollowMoverVelocityUpdated() = 0;
    virtual int32_t& TickMovementRan() = 0;
    virtual void TickMovementRanUpdated() = 0;
    virtual ::FuncMoverMovementSummary_t& MovementSummary() = 0;
    virtual void MovementSummaryUpdated() = 0;
    virtual bool& StopFromBeginStopTarget() = 0;
    virtual void StopFromBeginStopTargetUpdated() = 0;
    virtual bool& QueueStop() = 0;
    virtual void QueueStopUpdated() = 0;
    virtual bool& QueueStopMoving() = 0;
    virtual void QueueStopMovingUpdated() = 0;
    static IFuncMover* FromOriginal(CFuncMover* p);
};

#endif // _INCLUDE_IFUNCMOVER_H
