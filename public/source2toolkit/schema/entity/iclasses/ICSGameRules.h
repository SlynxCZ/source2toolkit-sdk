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

#ifndef _INCLUDE_ICSGAMERULES_H
#define _INCLUDE_ICSGAMERULES_H

#pragma once

#include <cstdint>

#include "ITeamplayRules.h"

#include "CRetakeGameRules.h"

class CBaseEntity;
class CCSGameModeRules;
class SpawnPoint;

class ICSGameRules : public virtual ITeamplayRules
{
public:
    virtual ~ICSGameRules() = default;

    virtual bool& FreezePeriod() = 0;
    virtual void FreezePeriodUpdated() = 0;
    virtual bool& WarmupPeriod() = 0;
    virtual void WarmupPeriodUpdated() = 0;
    virtual float& WarmupPeriodEnd() = 0;
    virtual void WarmupPeriodEndUpdated() = 0;
    virtual float& WarmupPeriodStart() = 0;
    virtual void WarmupPeriodStartUpdated() = 0;
    virtual bool& TerroristTimeOutActive() = 0;
    virtual void TerroristTimeOutActiveUpdated() = 0;
    virtual bool& CTTimeOutActive() = 0;
    virtual void CTTimeOutActiveUpdated() = 0;
    virtual float& TerroristTimeOutRemaining() = 0;
    virtual void TerroristTimeOutRemainingUpdated() = 0;
    virtual float& CTTimeOutRemaining() = 0;
    virtual void CTTimeOutRemainingUpdated() = 0;
    virtual int32_t& TerroristTimeOuts() = 0;
    virtual void TerroristTimeOutsUpdated() = 0;
    virtual int32_t& CTTimeOuts() = 0;
    virtual void CTTimeOutsUpdated() = 0;
    virtual bool& TechnicalTimeOut() = 0;
    virtual void TechnicalTimeOutUpdated() = 0;
    virtual bool& MatchWaitingForResume() = 0;
    virtual void MatchWaitingForResumeUpdated() = 0;
    virtual int32_t& FreezeTime() = 0;
    virtual void FreezeTimeUpdated() = 0;
    virtual int32_t& RoundTime() = 0;
    virtual void RoundTimeUpdated() = 0;
    virtual float& MatchStartTime() = 0;
    virtual void MatchStartTimeUpdated() = 0;
    virtual float& RoundStartTime() = 0;
    virtual void RoundStartTimeUpdated() = 0;
    virtual float& RestartRoundTime() = 0;
    virtual void RestartRoundTimeUpdated() = 0;
    virtual bool& GameRestart() = 0;
    virtual void GameRestartUpdated() = 0;
    virtual float& GameStartTime() = 0;
    virtual void GameStartTimeUpdated() = 0;
    virtual float& TimeUntilNextPhaseStarts() = 0;
    virtual void TimeUntilNextPhaseStartsUpdated() = 0;
    virtual int32_t& GamePhase() = 0;
    virtual void GamePhaseUpdated() = 0;
    virtual int32_t& TotalRoundsPlayed() = 0;
    virtual void TotalRoundsPlayedUpdated() = 0;
    virtual int32_t& RoundsPlayedThisPhase() = 0;
    virtual void RoundsPlayedThisPhaseUpdated() = 0;
    virtual int32_t& OvertimePlaying() = 0;
    virtual void OvertimePlayingUpdated() = 0;
    virtual int32_t& HostagesRemaining() = 0;
    virtual void HostagesRemainingUpdated() = 0;
    virtual bool& AnyHostageReached() = 0;
    virtual void AnyHostageReachedUpdated() = 0;
    virtual bool& MapHasBombTarget() = 0;
    virtual void MapHasBombTargetUpdated() = 0;
    virtual bool& MapHasRescueZone() = 0;
    virtual void MapHasRescueZoneUpdated() = 0;
    virtual bool& MapHasBuyZone() = 0;
    virtual void MapHasBuyZoneUpdated() = 0;
    virtual bool& IsQueuedMatchmaking() = 0;
    virtual void IsQueuedMatchmakingUpdated() = 0;
    virtual int32_t& QueuedMatchmakingMode() = 0;
    virtual void QueuedMatchmakingModeUpdated() = 0;
    virtual bool& IsValveDS() = 0;
    virtual void IsValveDSUpdated() = 0;
    virtual bool& LogoMap() = 0;
    virtual void LogoMapUpdated() = 0;
    virtual bool& PlayAllStepSoundsOnServer() = 0;
    virtual void PlayAllStepSoundsOnServerUpdated() = 0;
    virtual int32_t& SpectatorSlotCount() = 0;
    virtual void SpectatorSlotCountUpdated() = 0;
    virtual int32_t& MatchDevice() = 0;
    virtual void MatchDeviceUpdated() = 0;
    virtual bool& HasMatchStarted() = 0;
    virtual void HasMatchStartedUpdated() = 0;
    virtual int32_t& NextMapInMapgroup() = 0;
    virtual void NextMapInMapgroupUpdated() = 0;
    virtual char* TournamentEventName() = 0;
    virtual char* TournamentEventStage() = 0;
    virtual char* MatchStatTxt() = 0;
    virtual char* TournamentPredictionsTxt() = 0;
    virtual int32_t& TournamentPredictionsPct() = 0;
    virtual void TournamentPredictionsPctUpdated() = 0;
    virtual float& CMMItemDropRevealStartTime() = 0;
    virtual void CMMItemDropRevealStartTimeUpdated() = 0;
    virtual float& CMMItemDropRevealEndTime() = 0;
    virtual void CMMItemDropRevealEndTimeUpdated() = 0;
    virtual bool& IsDroppingItems() = 0;
    virtual void IsDroppingItemsUpdated() = 0;
    virtual bool& IsQuestEligible() = 0;
    virtual void IsQuestEligibleUpdated() = 0;
    virtual bool& IsHltvActive() = 0;
    virtual void IsHltvActiveUpdated() = 0;
    virtual bool& BombPlanted() = 0;
    virtual void BombPlantedUpdated() = 0;
    virtual uint16_t* ProhibitedItemIndices() = 0;
    virtual uint32_t* TournamentActiveCasterAccounts() = 0;
    virtual int32_t& NumBestOfMaps() = 0;
    virtual void NumBestOfMapsUpdated() = 0;
    virtual int32_t& HalloweenMaskListSeed() = 0;
    virtual void HalloweenMaskListSeedUpdated() = 0;
    virtual bool& BombDropped() = 0;
    virtual void BombDroppedUpdated() = 0;
    virtual int32_t& RoundWinStatus() = 0;
    virtual void RoundWinStatusUpdated() = 0;
    virtual int32_t& RoundWinReason() = 0;
    virtual void RoundWinReasonUpdated() = 0;
    virtual bool& TCantBuy() = 0;
    virtual void TCantBuyUpdated() = 0;
    virtual bool& CTCantBuy() = 0;
    virtual void CTCantBuyUpdated() = 0;
    virtual int32_t* MatchStats_RoundResults() = 0;
    virtual int32_t* MatchStats_PlayersAlive_CT() = 0;
    virtual int32_t* MatchStats_PlayersAlive_T() = 0;
    virtual float* TeamRespawnWaveTimes() = 0;
    virtual float* NextRespawnWave() = 0;
    virtual Vector& MinimapMins() = 0;
    virtual void MinimapMinsUpdated() = 0;
    virtual Vector& MinimapMaxs() = 0;
    virtual void MinimapMaxsUpdated() = 0;
    virtual float* MinimapVerticalSectionHeights() = 0;
    virtual uint64_t& UllLocalMatchID() = 0;
    virtual void UllLocalMatchIDUpdated() = 0;
    virtual int32_t* EndMatchMapGroupVoteTypes() = 0;
    virtual int32_t* EndMatchMapGroupVoteOptions() = 0;
    virtual int32_t& EndMatchMapVoteWinner() = 0;
    virtual void EndMatchMapVoteWinnerUpdated() = 0;
    virtual int32_t& NumConsecutiveCTLoses() = 0;
    virtual void NumConsecutiveCTLosesUpdated() = 0;
    virtual int32_t& NumConsecutiveTerroristLoses() = 0;
    virtual void NumConsecutiveTerroristLosesUpdated() = 0;
    virtual bool& HasHostageBeenTouched() = 0;
    virtual void HasHostageBeenTouchedUpdated() = 0;
    virtual float& IntermissionStartTime() = 0;
    virtual void IntermissionStartTimeUpdated() = 0;
    virtual float& IntermissionEndTime() = 0;
    virtual void IntermissionEndTimeUpdated() = 0;
    virtual bool& LevelInitialized() = 0;
    virtual void LevelInitializedUpdated() = 0;
    virtual int32_t& TotalRoundsPlayed() = 0;
    virtual void TotalRoundsPlayedUpdated() = 0;
    virtual int32_t& UnBalancedRounds() = 0;
    virtual void UnBalancedRoundsUpdated() = 0;
    virtual bool& EndMatchOnRoundReset() = 0;
    virtual void EndMatchOnRoundResetUpdated() = 0;
    virtual bool& EndMatchOnThink() = 0;
    virtual void EndMatchOnThinkUpdated() = 0;
    virtual int32_t& NumTerrorist() = 0;
    virtual void NumTerroristUpdated() = 0;
    virtual int32_t& NumCT() = 0;
    virtual void NumCTUpdated() = 0;
    virtual int32_t& NumSpawnableTerrorist() = 0;
    virtual void NumSpawnableTerroristUpdated() = 0;
    virtual int32_t& NumSpawnableCT() = 0;
    virtual void NumSpawnableCTUpdated() = 0;
    virtual CUtlVector<int32_t>& SelectedHostageSpawnIndices() = 0;
    virtual void SelectedHostageSpawnIndicesUpdated() = 0;
    virtual int32_t& SpawnPointsRandomSeed() = 0;
    virtual void SpawnPointsRandomSeedUpdated() = 0;
    virtual bool& FirstConnected() = 0;
    virtual void FirstConnectedUpdated() = 0;
    virtual bool& CompleteReset() = 0;
    virtual void CompleteResetUpdated() = 0;
    virtual bool& PickNewTeamsOnReset() = 0;
    virtual void PickNewTeamsOnResetUpdated() = 0;
    virtual bool& ScrambleTeamsOnRestart() = 0;
    virtual void ScrambleTeamsOnRestartUpdated() = 0;
    virtual bool& SwapTeamsOnRestart() = 0;
    virtual void SwapTeamsOnRestartUpdated() = 0;
    virtual CUtlVector<int32_t>& EndMatchTiedVotes() = 0;
    virtual void EndMatchTiedVotesUpdated() = 0;
    virtual bool& NeedToAskPlayersForContinueVote() = 0;
    virtual void NeedToAskPlayersForContinueVoteUpdated() = 0;
    virtual uint32_t& NumQueuedMatchmakingAccounts() = 0;
    virtual void NumQueuedMatchmakingAccountsUpdated() = 0;
    virtual float& AvgPlayerRank() = 0;
    virtual void AvgPlayerRankUpdated() = 0;
    virtual char*& QueuedMatchmakingReservationString() = 0;
    virtual void QueuedMatchmakingReservationStringUpdated() = 0;
    virtual uint32_t& NumTotalTournamentDrops() = 0;
    virtual void NumTotalTournamentDropsUpdated() = 0;
    virtual uint32_t& NumSpectatorsCountMax() = 0;
    virtual void NumSpectatorsCountMaxUpdated() = 0;
    virtual uint32_t& NumSpectatorsCountMaxTV() = 0;
    virtual void NumSpectatorsCountMaxTVUpdated() = 0;
    virtual uint32_t& NumSpectatorsCountMaxLnk() = 0;
    virtual void NumSpectatorsCountMaxLnkUpdated() = 0;
    virtual int32_t& CTsAliveAtFreezetimeEnd() = 0;
    virtual void CTsAliveAtFreezetimeEndUpdated() = 0;
    virtual int32_t& TerroristsAliveAtFreezetimeEnd() = 0;
    virtual void TerroristsAliveAtFreezetimeEndUpdated() = 0;
    virtual bool& ForceTeamChangeSilent() = 0;
    virtual void ForceTeamChangeSilentUpdated() = 0;
    virtual bool& LoadingRoundBackupData() = 0;
    virtual void LoadingRoundBackupDataUpdated() = 0;
    virtual int32_t& MatchInfoShowType() = 0;
    virtual void MatchInfoShowTypeUpdated() = 0;
    virtual float& MatchInfoDecidedTime() = 0;
    virtual void MatchInfoDecidedTimeUpdated() = 0;
    virtual int32_t& MTeamDMLastWinningTeamNumber() = 0;
    virtual void MTeamDMLastWinningTeamNumberUpdated() = 0;
    virtual float& MTeamDMLastThinkTime() = 0;
    virtual void MTeamDMLastThinkTimeUpdated() = 0;
    virtual float& TeamDMLastAnnouncementTime() = 0;
    virtual void TeamDMLastAnnouncementTimeUpdated() = 0;
    virtual int32_t& AccountTerrorist() = 0;
    virtual void AccountTerroristUpdated() = 0;
    virtual int32_t& AccountCT() = 0;
    virtual void AccountCTUpdated() = 0;
    virtual int32_t& SpawnPointCount_Terrorist() = 0;
    virtual void SpawnPointCount_TerroristUpdated() = 0;
    virtual int32_t& SpawnPointCount_CT() = 0;
    virtual void SpawnPointCount_CTUpdated() = 0;
    virtual int32_t& MaxNumTerrorists() = 0;
    virtual void MaxNumTerroristsUpdated() = 0;
    virtual int32_t& MaxNumCTs() = 0;
    virtual void MaxNumCTsUpdated() = 0;
    virtual int32_t& LoserBonusMostRecentTeam() = 0;
    virtual void LoserBonusMostRecentTeamUpdated() = 0;
    virtual float& TmNextPeriodicThink() = 0;
    virtual void TmNextPeriodicThinkUpdated() = 0;
    virtual bool& VoiceWonMatchBragFired() = 0;
    virtual void VoiceWonMatchBragFiredUpdated() = 0;
    virtual float& WarmupNextChatNoticeTime() = 0;
    virtual void WarmupNextChatNoticeTimeUpdated() = 0;
    virtual int32_t& HostagesRescued() = 0;
    virtual void HostagesRescuedUpdated() = 0;
    virtual int32_t& HostagesTouched() = 0;
    virtual void HostagesTouchedUpdated() = 0;
    virtual float& NextHostageAnnouncement() = 0;
    virtual void NextHostageAnnouncementUpdated() = 0;
    virtual bool& NoTerroristsKilled() = 0;
    virtual void NoTerroristsKilledUpdated() = 0;
    virtual bool& NoCTsKilled() = 0;
    virtual void NoCTsKilledUpdated() = 0;
    virtual bool& NoEnemiesKilled() = 0;
    virtual void NoEnemiesKilledUpdated() = 0;
    virtual bool& CanDonateWeapons() = 0;
    virtual void CanDonateWeaponsUpdated() = 0;
    virtual float& FirstKillTime() = 0;
    virtual void FirstKillTimeUpdated() = 0;
    virtual float& FirstBloodTime() = 0;
    virtual void FirstBloodTimeUpdated() = 0;
    virtual bool& HostageWasInjured() = 0;
    virtual void HostageWasInjuredUpdated() = 0;
    virtual bool& HostageWasKilled() = 0;
    virtual void HostageWasKilledUpdated() = 0;
    virtual bool& VoteCalled() = 0;
    virtual void VoteCalledUpdated() = 0;
    virtual bool& ServerVoteOnReset() = 0;
    virtual void ServerVoteOnResetUpdated() = 0;
    virtual float& VoteCheckThrottle() = 0;
    virtual void VoteCheckThrottleUpdated() = 0;
    virtual bool& BuyTimeEnded() = 0;
    virtual void BuyTimeEndedUpdated() = 0;
    virtual int32_t& LastFreezeEndBeep() = 0;
    virtual void LastFreezeEndBeepUpdated() = 0;
    virtual bool& TargetBombed() = 0;
    virtual void TargetBombedUpdated() = 0;
    virtual bool& BombDefused() = 0;
    virtual void BombDefusedUpdated() = 0;
    virtual bool& MapHasBombZone() = 0;
    virtual void MapHasBombZoneUpdated() = 0;
    virtual Vector& MainCTSpawnPos() = 0;
    virtual void MainCTSpawnPosUpdated() = 0;
    virtual CUtlVector<CHandle<SpawnPoint>>& CTSpawnPointsMasterList() = 0;
    virtual void CTSpawnPointsMasterListUpdated() = 0;
    virtual CUtlVector<CHandle<SpawnPoint>>& TerroristSpawnPointsMasterList() = 0;
    virtual void TerroristSpawnPointsMasterListUpdated() = 0;
    virtual bool& RespawningAllRespawnablePlayers() = 0;
    virtual void RespawningAllRespawnablePlayersUpdated() = 0;
    virtual int32_t& NextCTSpawnPoint() = 0;
    virtual void NextCTSpawnPointUpdated() = 0;
    virtual float& CTSpawnPointUsedTime() = 0;
    virtual void CTSpawnPointUsedTimeUpdated() = 0;
    virtual int32_t& NextTerroristSpawnPoint() = 0;
    virtual void NextTerroristSpawnPointUpdated() = 0;
    virtual float& TerroristSpawnPointUsedTime() = 0;
    virtual void TerroristSpawnPointUsedTimeUpdated() = 0;
    virtual CUtlVector<CHandle<SpawnPoint>>& CTSpawnPoints() = 0;
    virtual void CTSpawnPointsUpdated() = 0;
    virtual CUtlVector<CHandle<SpawnPoint>>& TerroristSpawnPoints() = 0;
    virtual void TerroristSpawnPointsUpdated() = 0;
    virtual bool& IsUnreservedGameServer() = 0;
    virtual void IsUnreservedGameServerUpdated() = 0;
    virtual float& AutobalanceDisplayTime() = 0;
    virtual void AutobalanceDisplayTimeUpdated() = 0;
    virtual bool& AllowWeaponSwitch() = 0;
    virtual void AllowWeaponSwitchUpdated() = 0;
    virtual bool& RoundTimeWarningTriggered() = 0;
    virtual void RoundTimeWarningTriggeredUpdated() = 0;
    virtual float& PhaseChangeAnnouncementTime() = 0;
    virtual void PhaseChangeAnnouncementTimeUpdated() = 0;
    virtual float& NextUpdateTeamClanNamesTime() = 0;
    virtual void NextUpdateTeamClanNamesTimeUpdated() = 0;
    virtual float& LastThinkTime() = 0;
    virtual void LastThinkTimeUpdated() = 0;
    virtual float& AccumulatedRoundOffDamage() = 0;
    virtual void AccumulatedRoundOffDamageUpdated() = 0;
    virtual int32_t& ShorthandedBonusLastEvalRound() = 0;
    virtual void ShorthandedBonusLastEvalRoundUpdated() = 0;
    virtual int32_t& MatchAbortedEarlyReason() = 0;
    virtual void MatchAbortedEarlyReasonUpdated() = 0;
    virtual bool& HasTriggeredRoundStartMusic() = 0;
    virtual void HasTriggeredRoundStartMusicUpdated() = 0;
    virtual bool& SwitchingTeamsAtRoundReset() = 0;
    virtual void SwitchingTeamsAtRoundResetUpdated() = 0;
    virtual CCSGameModeRules*& GameModeRules() = 0;
    virtual void GameModeRulesUpdated() = 0;
    virtual CHandle<CBaseEntity>& PlayerResource() = 0;
    virtual void PlayerResourceUpdated() = 0;
    virtual CRetakeGameRules& RetakeRules() = 0;
    virtual void RetakeRulesUpdated() = 0;
    virtual CUtlVector<int32_t>* TeamUniqueKillWeaponsMatch() = 0;
    virtual bool* TeamLastKillUsedUniqueWeaponMatch() = 0;
    virtual uint8_t& MatchEndCount() = 0;
    virtual void MatchEndCountUpdated() = 0;
    virtual int32_t& TTeamIntroVariant() = 0;
    virtual void TTeamIntroVariantUpdated() = 0;
    virtual int32_t& CTTeamIntroVariant() = 0;
    virtual void CTTeamIntroVariantUpdated() = 0;
    virtual bool& TeamIntroPeriod() = 0;
    virtual void TeamIntroPeriodUpdated() = 0;
    virtual float& TeamIntroPeriodEnd() = 0;
    virtual void TeamIntroPeriodEndUpdated() = 0;
    virtual bool& PlayedTeamIntroVO() = 0;
    virtual void PlayedTeamIntroVOUpdated() = 0;
    virtual int32_t& RoundEndWinnerTeam() = 0;
    virtual void RoundEndWinnerTeamUpdated() = 0;
    virtual int32_t& RoundEndReason() = 0;
    virtual void RoundEndReasonUpdated() = 0;
    virtual bool& RoundEndShowTimerDefend() = 0;
    virtual void RoundEndShowTimerDefendUpdated() = 0;
    virtual int32_t& RoundEndTimerTime() = 0;
    virtual void RoundEndTimerTimeUpdated() = 0;
    virtual CUtlString& RoundEndFunFactToken() = 0;
    virtual void RoundEndFunFactTokenUpdated() = 0;
    virtual int32_t& RoundEndFunFactPlayerSlot() = 0;
    virtual void RoundEndFunFactPlayerSlotUpdated() = 0;
    virtual int32_t& RoundEndFunFactData1() = 0;
    virtual void RoundEndFunFactData1Updated() = 0;
    virtual int32_t& RoundEndFunFactData2() = 0;
    virtual void RoundEndFunFactData2Updated() = 0;
    virtual int32_t& RoundEndFunFactData3() = 0;
    virtual void RoundEndFunFactData3Updated() = 0;
    virtual CUtlString& RoundEndMessage() = 0;
    virtual void RoundEndMessageUpdated() = 0;
    virtual int32_t& RoundEndPlayerCount() = 0;
    virtual void RoundEndPlayerCountUpdated() = 0;
    virtual bool& RoundEndNoMusic() = 0;
    virtual void RoundEndNoMusicUpdated() = 0;
    virtual int32_t& RoundEndLegacy() = 0;
    virtual void RoundEndLegacyUpdated() = 0;
    virtual uint8_t& RoundEndCount() = 0;
    virtual void RoundEndCountUpdated() = 0;
    virtual int32_t& RoundStartRoundNumber() = 0;
    virtual void RoundStartRoundNumberUpdated() = 0;
    virtual uint8_t& RoundStartCount() = 0;
    virtual void RoundStartCountUpdated() = 0;
    virtual double& LastPerfSampleTime() = 0;
    virtual void LastPerfSampleTimeUpdated() = 0;
};

#endif // _INCLUDE_ICSGAMERULES_H
