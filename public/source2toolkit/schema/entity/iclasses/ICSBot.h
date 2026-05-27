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

#ifndef _INCLUDE_ICSBOT_H
#define _INCLUDE_ICSBOT_H

#pragma once

#include <cstdint>

#include "IBot.h"

#include "CountdownTimer.h"
#include "IntervalTimer.h"

class CBaseEntity;
class CCSPlayerPawn;

class ICSBot : public virtual IBot
{
public:
    virtual ~ICSBot() = default;

    virtual Vector& EyePosition() = 0;
    virtual void EyePositionUpdated() = 0;
    virtual char* Name() = 0;
    virtual float& CombatRange() = 0;
    virtual void CombatRangeUpdated() = 0;
    virtual bool& IsRogue() = 0;
    virtual void IsRogueUpdated() = 0;
    virtual CountdownTimer& RogueTimer() = 0;
    virtual void RogueTimerUpdated() = 0;
    virtual bool& DiedLastRound() = 0;
    virtual void DiedLastRoundUpdated() = 0;
    virtual float& SafeTime() = 0;
    virtual void SafeTimeUpdated() = 0;
    virtual bool& WasSafe() = 0;
    virtual void WasSafeUpdated() = 0;
    virtual bool& BlindFire() = 0;
    virtual void BlindFireUpdated() = 0;
    virtual CountdownTimer& SurpriseTimer() = 0;
    virtual void SurpriseTimerUpdated() = 0;
    virtual bool& AllowActive() = 0;
    virtual void AllowActiveUpdated() = 0;
    virtual bool& IsFollowing() = 0;
    virtual void IsFollowingUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& Leader() = 0;
    virtual void LeaderUpdated() = 0;
    virtual float& FollowTimestamp() = 0;
    virtual void FollowTimestampUpdated() = 0;
    virtual float& AllowAutoFollowTime() = 0;
    virtual void AllowAutoFollowTimeUpdated() = 0;
    virtual CountdownTimer& HurryTimer() = 0;
    virtual void HurryTimerUpdated() = 0;
    virtual CountdownTimer& AlertTimer() = 0;
    virtual void AlertTimerUpdated() = 0;
    virtual CountdownTimer& SneakTimer() = 0;
    virtual void SneakTimerUpdated() = 0;
    virtual CountdownTimer& PanicTimer() = 0;
    virtual void PanicTimerUpdated() = 0;
    virtual float& StateTimestamp() = 0;
    virtual void StateTimestampUpdated() = 0;
    virtual bool& IsAttacking() = 0;
    virtual void IsAttackingUpdated() = 0;
    virtual bool& IsOpeningDoor() = 0;
    virtual void IsOpeningDoorUpdated() = 0;
    virtual CHandle<CBaseEntity>& TaskEntity() = 0;
    virtual void TaskEntityUpdated() = 0;
    virtual Vector& GoalPosition() = 0;
    virtual void GoalPositionUpdated() = 0;
    virtual CHandle<CBaseEntity>& GoalEntity() = 0;
    virtual void GoalEntityUpdated() = 0;
    virtual CHandle<CBaseEntity>& Avoid() = 0;
    virtual void AvoidUpdated() = 0;
    virtual float& AvoidTimestamp() = 0;
    virtual void AvoidTimestampUpdated() = 0;
    virtual bool& IsStopping() = 0;
    virtual void IsStoppingUpdated() = 0;
    virtual bool& HasVisitedEnemySpawn() = 0;
    virtual void HasVisitedEnemySpawnUpdated() = 0;
    virtual IntervalTimer& StillTimer() = 0;
    virtual void StillTimerUpdated() = 0;
    virtual bool& EyeAnglesUnderPathFinderControl() = 0;
    virtual void EyeAnglesUnderPathFinderControlUpdated() = 0;
    virtual int32_t& PathIndex() = 0;
    virtual void PathIndexUpdated() = 0;
    virtual float& AreaEnteredTimestamp() = 0;
    virtual void AreaEnteredTimestampUpdated() = 0;
    virtual CountdownTimer& RepathTimer() = 0;
    virtual void RepathTimerUpdated() = 0;
    virtual CountdownTimer& AvoidFriendTimer() = 0;
    virtual void AvoidFriendTimerUpdated() = 0;
    virtual bool& IsFriendInTheWay() = 0;
    virtual void IsFriendInTheWayUpdated() = 0;
    virtual CountdownTimer& PoliteTimer() = 0;
    virtual void PoliteTimerUpdated() = 0;
    virtual bool& IsWaitingBehindFriend() = 0;
    virtual void IsWaitingBehindFriendUpdated() = 0;
    virtual float& PathLadderEnd() = 0;
    virtual void PathLadderEndUpdated() = 0;
    virtual CountdownTimer& MustRunTimer() = 0;
    virtual void MustRunTimerUpdated() = 0;
    virtual CountdownTimer& WaitTimer() = 0;
    virtual void WaitTimerUpdated() = 0;
    virtual CountdownTimer& UpdateTravelDistanceTimer() = 0;
    virtual void UpdateTravelDistanceTimerUpdated() = 0;
    virtual float* PlayerTravelDistance() = 0;
    virtual uint8_t& TravelDistancePhase() = 0;
    virtual void TravelDistancePhaseUpdated() = 0;
    virtual uint8_t& HostageEscortCount() = 0;
    virtual void HostageEscortCountUpdated() = 0;
    virtual float& HostageEscortCountTimestamp() = 0;
    virtual void HostageEscortCountTimestampUpdated() = 0;
    virtual int32_t& DesiredTeam() = 0;
    virtual void DesiredTeamUpdated() = 0;
    virtual bool& HasJoined() = 0;
    virtual void HasJoinedUpdated() = 0;
    virtual bool& IsWaitingForHostage() = 0;
    virtual void IsWaitingForHostageUpdated() = 0;
    virtual CountdownTimer& InhibitWaitingForHostageTimer() = 0;
    virtual void InhibitWaitingForHostageTimerUpdated() = 0;
    virtual CountdownTimer& WaitForHostageTimer() = 0;
    virtual void WaitForHostageTimerUpdated() = 0;
    virtual Vector& NoisePosition() = 0;
    virtual void NoisePositionUpdated() = 0;
    virtual float& NoiseTravelDistance() = 0;
    virtual void NoiseTravelDistanceUpdated() = 0;
    virtual float& NoiseTimestamp() = 0;
    virtual void NoiseTimestampUpdated() = 0;
    virtual CCSPlayerPawn*& NoiseSource() = 0;
    virtual void NoiseSourceUpdated() = 0;
    virtual CountdownTimer& NoiseBendTimer() = 0;
    virtual void NoiseBendTimerUpdated() = 0;
    virtual Vector& BentNoisePosition() = 0;
    virtual void BentNoisePositionUpdated() = 0;
    virtual bool& BendNoisePositionValid() = 0;
    virtual void BendNoisePositionValidUpdated() = 0;
    virtual float& LookAroundStateTimestamp() = 0;
    virtual void LookAroundStateTimestampUpdated() = 0;
    virtual float& LookAheadAngle() = 0;
    virtual void LookAheadAngleUpdated() = 0;
    virtual float& LookUpAngle() = 0;
    virtual void LookUpAngleUpdated() = 0;
    virtual float& ForwardAngle() = 0;
    virtual void ForwardAngleUpdated() = 0;
    virtual float& InhibitLookAroundTimestamp() = 0;
    virtual void InhibitLookAroundTimestampUpdated() = 0;
    virtual Vector& LookAtSpot() = 0;
    virtual void LookAtSpotUpdated() = 0;
    virtual float& LookAtSpotDuration() = 0;
    virtual void LookAtSpotDurationUpdated() = 0;
    virtual float& LookAtSpotTimestamp() = 0;
    virtual void LookAtSpotTimestampUpdated() = 0;
    virtual float& LookAtSpotAngleTolerance() = 0;
    virtual void LookAtSpotAngleToleranceUpdated() = 0;
    virtual bool& LookAtSpotClearIfClose() = 0;
    virtual void LookAtSpotClearIfCloseUpdated() = 0;
    virtual bool& LookAtSpotAttack() = 0;
    virtual void LookAtSpotAttackUpdated() = 0;
    virtual char*& LookAtDesc() = 0;
    virtual void LookAtDescUpdated() = 0;
    virtual float& PeripheralTimestamp() = 0;
    virtual void PeripheralTimestampUpdated() = 0;
    virtual uint8_t& ApproachPointCount() = 0;
    virtual void ApproachPointCountUpdated() = 0;
    virtual Vector& ApproachPointViewPosition() = 0;
    virtual void ApproachPointViewPositionUpdated() = 0;
    virtual IntervalTimer& ViewSteadyTimer() = 0;
    virtual void ViewSteadyTimerUpdated() = 0;
    virtual CountdownTimer& TossGrenadeTimer() = 0;
    virtual void TossGrenadeTimerUpdated() = 0;
    virtual CountdownTimer& IsAvoidingGrenade() = 0;
    virtual void IsAvoidingGrenadeUpdated() = 0;
    virtual float& SpotCheckTimestamp() = 0;
    virtual void SpotCheckTimestampUpdated() = 0;
    virtual int32_t& CheckedHidingSpotCount() = 0;
    virtual void CheckedHidingSpotCountUpdated() = 0;
    virtual float& LookPitch() = 0;
    virtual void LookPitchUpdated() = 0;
    virtual float& LookPitchVel() = 0;
    virtual void LookPitchVelUpdated() = 0;
    virtual float& LookYaw() = 0;
    virtual void LookYawUpdated() = 0;
    virtual float& LookYawVel() = 0;
    virtual void LookYawVelUpdated() = 0;
    virtual Vector& TargetSpot() = 0;
    virtual void TargetSpotUpdated() = 0;
    virtual Vector& TargetSpotVelocity() = 0;
    virtual void TargetSpotVelocityUpdated() = 0;
    virtual Vector& TargetSpotPredicted() = 0;
    virtual void TargetSpotPredictedUpdated() = 0;
    virtual QAngle& AimError() = 0;
    virtual void AimErrorUpdated() = 0;
    virtual QAngle& AimGoal() = 0;
    virtual void AimGoalUpdated() = 0;
    virtual float& TargetSpotTime() = 0;
    virtual void TargetSpotTimeUpdated() = 0;
    virtual float& AimFocus() = 0;
    virtual void AimFocusUpdated() = 0;
    virtual float& AimFocusInterval() = 0;
    virtual void AimFocusIntervalUpdated() = 0;
    virtual float& AimFocusNextUpdate() = 0;
    virtual void AimFocusNextUpdateUpdated() = 0;
    virtual CountdownTimer& IgnoreEnemiesTimer() = 0;
    virtual void IgnoreEnemiesTimerUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& Enemy() = 0;
    virtual void EnemyUpdated() = 0;
    virtual bool& IsEnemyVisible() = 0;
    virtual void IsEnemyVisibleUpdated() = 0;
    virtual uint8_t& VisibleEnemyParts() = 0;
    virtual void VisibleEnemyPartsUpdated() = 0;
    virtual Vector& LastEnemyPosition() = 0;
    virtual void LastEnemyPositionUpdated() = 0;
    virtual float& LastSawEnemyTimestamp() = 0;
    virtual void LastSawEnemyTimestampUpdated() = 0;
    virtual float& FirstSawEnemyTimestamp() = 0;
    virtual void FirstSawEnemyTimestampUpdated() = 0;
    virtual float& CurrentEnemyAcquireTimestamp() = 0;
    virtual void CurrentEnemyAcquireTimestampUpdated() = 0;
    virtual float& EnemyDeathTimestamp() = 0;
    virtual void EnemyDeathTimestampUpdated() = 0;
    virtual float& FriendDeathTimestamp() = 0;
    virtual void FriendDeathTimestampUpdated() = 0;
    virtual bool& IsLastEnemyDead() = 0;
    virtual void IsLastEnemyDeadUpdated() = 0;
    virtual int32_t& NearbyEnemyCount() = 0;
    virtual void NearbyEnemyCountUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& Bomber() = 0;
    virtual void BomberUpdated() = 0;
    virtual int32_t& NearbyFriendCount() = 0;
    virtual void NearbyFriendCountUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& ClosestVisibleFriend() = 0;
    virtual void ClosestVisibleFriendUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& ClosestVisibleHumanFriend() = 0;
    virtual void ClosestVisibleHumanFriendUpdated() = 0;
    virtual IntervalTimer& AttentionInterval() = 0;
    virtual void AttentionIntervalUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& Attacker() = 0;
    virtual void AttackerUpdated() = 0;
    virtual float& AttackedTimestamp() = 0;
    virtual void AttackedTimestampUpdated() = 0;
    virtual IntervalTimer& BurnedByFlamesTimer() = 0;
    virtual void BurnedByFlamesTimerUpdated() = 0;
    virtual int32_t& LastVictimID() = 0;
    virtual void LastVictimIDUpdated() = 0;
    virtual bool& IsAimingAtEnemy() = 0;
    virtual void IsAimingAtEnemyUpdated() = 0;
    virtual bool& IsRapidFiring() = 0;
    virtual void IsRapidFiringUpdated() = 0;
    virtual IntervalTimer& EquipTimer() = 0;
    virtual void EquipTimerUpdated() = 0;
    virtual CountdownTimer& ZoomTimer() = 0;
    virtual void ZoomTimerUpdated() = 0;
    virtual float& FireWeaponTimestamp() = 0;
    virtual void FireWeaponTimestampUpdated() = 0;
    virtual CountdownTimer& LookForWeaponsOnGroundTimer() = 0;
    virtual void LookForWeaponsOnGroundTimerUpdated() = 0;
    virtual bool& IsSleeping() = 0;
    virtual void IsSleepingUpdated() = 0;
    virtual bool& IsEnemySniperVisible() = 0;
    virtual void IsEnemySniperVisibleUpdated() = 0;
    virtual CountdownTimer& SawEnemySniperTimer() = 0;
    virtual void SawEnemySniperTimerUpdated() = 0;
    virtual uint8_t& EnemyQueueIndex() = 0;
    virtual void EnemyQueueIndexUpdated() = 0;
    virtual uint8_t& EnemyQueueCount() = 0;
    virtual void EnemyQueueCountUpdated() = 0;
    virtual uint8_t& EnemyQueueAttendIndex() = 0;
    virtual void EnemyQueueAttendIndexUpdated() = 0;
    virtual bool& IsStuck() = 0;
    virtual void IsStuckUpdated() = 0;
    virtual float& StuckTimestamp() = 0;
    virtual void StuckTimestampUpdated() = 0;
    virtual Vector& StuckSpot() = 0;
    virtual void StuckSpotUpdated() = 0;
    virtual CountdownTimer& WiggleTimer() = 0;
    virtual void WiggleTimerUpdated() = 0;
    virtual CountdownTimer& StuckJumpTimer() = 0;
    virtual void StuckJumpTimerUpdated() = 0;
    virtual float& NextCleanupCheckTimestamp() = 0;
    virtual void NextCleanupCheckTimestampUpdated() = 0;
    virtual float* AvgVel() = 0;
    virtual int32_t& AvgVelIndex() = 0;
    virtual void AvgVelIndexUpdated() = 0;
    virtual int32_t& AvgVelCount() = 0;
    virtual void AvgVelCountUpdated() = 0;
    virtual Vector& LastOrigin() = 0;
    virtual void LastOriginUpdated() = 0;
    virtual float& LastRadioRecievedTimestamp() = 0;
    virtual void LastRadioRecievedTimestampUpdated() = 0;
    virtual float& LastRadioSentTimestamp() = 0;
    virtual void LastRadioSentTimestampUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& RadioSubject() = 0;
    virtual void RadioSubjectUpdated() = 0;
    virtual Vector& RadioPosition() = 0;
    virtual void RadioPositionUpdated() = 0;
    virtual float& VoiceEndTimestamp() = 0;
    virtual void VoiceEndTimestampUpdated() = 0;
    virtual int32_t& LastValidReactionQueueFrame() = 0;
    virtual void LastValidReactionQueueFrameUpdated() = 0;
};

#endif // _INCLUDE_ICSBOT_H
