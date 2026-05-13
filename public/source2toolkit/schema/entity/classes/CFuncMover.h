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

#ifndef _INCLUDE_CFUNCMOVER_H
#define _INCLUDE_CFUNCMOVER_H

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

#include "CBaseModelEntity.h"
#include "../enums/CFuncMover__FollowConstraint_t.h"
#include "../enums/CFuncMover__FollowEntityDirection_t.h"
#include "../enums/CFuncMover__Move_t.h"
#include "../enums/CFuncMover__OrientationUpdate_t.h"
#include "../enums/CFuncMover__TransitionToPathNodeAction_t.h"
#include "FuncMoverMovementSummary_t.h"

class CBaseEntity;
class CMoverPathNode;
class CPathMover;

class CFuncMover : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncMover);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPathName);
    SCHEMA_FIELD(CHandle<CPathMover>, m_hPathMover);
    SCHEMA_FIELD(CHandle<CPathMover>, m_hPrevPathMover);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPathNodeStart);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPathNodeEnd);
    SCHEMA_FIELD(bool, m_bIgnoreEndNode);
    SCHEMA_FIELD(CFuncMover__Move_t, m_eMoveType);
    SCHEMA_FIELD(bool, m_bIsReversing);
    SCHEMA_FIELD(float, m_flStartSpeed);
    SCHEMA_FIELD(float, m_flPathLocation);
    SCHEMA_FIELD(float, m_flT);
    SCHEMA_FIELD(int32_t, m_nCurrentNodeIndex);
    SCHEMA_FIELD(int32_t, m_nPreviousNodeIndex);
    SCHEMA_FIELD(SolidType_t, m_eSolidType);
    SCHEMA_FIELD(bool, m_bIsMoving);
    SCHEMA_FIELD(float, m_flTimeToReachMaxSpeed);
    SCHEMA_FIELD(float, m_flDistanceToReachMaxSpeed);
    SCHEMA_FIELD(float, m_flTimeToReachZeroSpeed);
    SCHEMA_FIELD(float, m_flComputedDistanceToReachMaxSpeed);
    SCHEMA_FIELD(float, m_flComputedDistanceToReachZeroSpeed);
    SCHEMA_FIELD(float, m_flStartCurveScale);
    SCHEMA_FIELD(float, m_flStopCurveScale);
    SCHEMA_FIELD(float, m_flDistanceToReachZeroSpeed);
    SCHEMA_FIELD(float, m_flTimeMovementStart);
    SCHEMA_FIELD(float, m_flTimeMovementStop);
    SCHEMA_FIELD(CHandle<CMoverPathNode>, m_hStopAtNode);
    SCHEMA_FIELD(float, m_flPathLocationToBeginStop);
    SCHEMA_FIELD(float, m_flPathLocationStart);
    SCHEMA_FIELD(float, m_flBeginStopT);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStartForwardSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLoopForwardSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStopForwardSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStartReverseSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLoopReverseSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStopReverseSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszArriveAtDestinationSound);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMovementEnd);
    SCHEMA_FIELD(bool, m_bStartAtClosestPoint);
    SCHEMA_FIELD(bool, m_bStartAtEnd);
    SCHEMA_FIELD(bool, m_bStartFollowingClosestMover);
    SCHEMA_FIELD(CFuncMover__OrientationUpdate_t, m_eOrientationUpdate);
    SCHEMA_FIELD(float, m_flTimeStartOrientationChange);
    SCHEMA_FIELD(float, m_flTimeToBlendToNewOrientation);
    SCHEMA_FIELD(float, m_flDurationBlendToNewOrientationRan);
    SCHEMA_FIELD(bool, m_bCreateMovableNavMesh);
    SCHEMA_FIELD(bool, m_bAllowMovableNavMeshDockingOnEntireEntity);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOrientationMatchEntityName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOrientationMatchEntity);
    SCHEMA_FIELD(float, m_flTimeToTraverseToNextNode);
    SCHEMA_FIELD(Vector, m_vLerpToNewPosStartInPathEntitySpace);
    SCHEMA_FIELD(Vector, m_vLerpToNewPosEndInPathEntitySpace);
    SCHEMA_FIELD(float, m_flLerpToPositionT);
    SCHEMA_FIELD(float, m_flLerpToPositionDeltaT);
    SCHEMA_FIELD(CEntityIOOutput, m_OnLerpToPositionComplete);
    SCHEMA_FIELD(bool, m_bIsPaused);
    SCHEMA_FIELD(CFuncMover__TransitionToPathNodeAction_t, m_eTransitionedToPathNodeAction);
    SCHEMA_FIELD(Quaternion, m_qTransitionSourceOrientation);
    SCHEMA_FIELD(int32_t, m_nDelayedTeleportToNode);
    SCHEMA_FIELD(bool, m_bIsImGuiLogging);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hFollowEntity);
    SCHEMA_FIELD(float, m_flFollowDistance);
    SCHEMA_FIELD(float, m_flFollowMinimumSpeed);
    SCHEMA_FIELD(float, m_flCurFollowEntityT);
    SCHEMA_FIELD(float, m_flCurFollowSpeed);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strOrientationFaceEntityName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOrientationFaceEntity);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStart);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartForward);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartReverse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStop);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStopped);
    SCHEMA_FIELD(bool, m_bNextNodeReturnsCurrent);
    SCHEMA_FIELD(bool, m_bStartedMoving);
    SCHEMA_FIELD(CFuncMover__FollowEntityDirection_t, m_eFollowEntityDirection);
    SCHEMA_FIELD(CHandle<CFuncMover>, m_hFollowMover);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszFollowMoverEntityName);
    SCHEMA_FIELD(float, m_flFollowMoverDistance);
    SCHEMA_FIELD(float, m_flFollowMoverRatio);
    SCHEMA_FIELD(float, m_flFollowMoverCalculatedDistance);
    SCHEMA_FIELD(float, m_flFollowMoverSpringStrength);
    SCHEMA_FIELD(int32_t, m_nFollowMoverConstraintPriority);
    SCHEMA_FIELD(bool, m_bFollowConstraintsInitialized);
    SCHEMA_FIELD(CFuncMover__FollowConstraint_t, m_eFollowConstraint);
    SCHEMA_FIELD(float, m_flFollowMoverSpeed);
    SCHEMA_FIELD(float, m_flFollowMoverVelocity);
    SCHEMA_FIELD(int32_t, m_nTickMovementRan);
    SCHEMA_FIELD(FuncMoverMovementSummary_t, m_movementSummary);
    SCHEMA_FIELD(bool, m_bStopFromBeginStopTarget);
    SCHEMA_FIELD(bool, m_bQueueStop);
    SCHEMA_FIELD(bool, m_bQueueStopMoving);

public:
    static CFuncMover* New(const char* className)
    {
        return CBaseEntity::New<CFuncMover>(className);
    }

    static CFuncMover* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncMover>(iIndex);
    }

    static CFuncMover* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};

#endif // _INCLUDE_CFUNCMOVER_H
