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

#ifndef _INCLUDE_ICSPLAYERCONTROLLER_H
#define _INCLUDE_ICSPLAYERCONTROLLER_H

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

#include "IBasePlayerController.h"

#include "../enums/DamageTypes_t.h"
#include "../enums/QuestProgress__Reason.h"

class CCSObserverPawn;
class CCSPlayerController;
class CCSPlayerController_ActionTrackingServices;
class CCSPlayerController_DamageServices;
class CCSPlayerController_InGameMoneyServices;
class CCSPlayerController_InventoryServices;
class CCSPlayerPawn;
class ICSObserverPawn;
class ICSPlayerController;
class ICSPlayerPawn;
class IGameEvent;
class IP;
class IntervalTimer;

class ICSPlayerController : public virtual IBasePlayerController
{
public:
    virtual ~ICSPlayerController() = default;

    virtual CCSPlayerController_InGameMoneyServices*& InGameMoneyServices() = 0;
    virtual void InGameMoneyServicesUpdated() = 0;
    virtual CCSPlayerController_InventoryServices*& InventoryServices() = 0;
    virtual void InventoryServicesUpdated() = 0;
    virtual CCSPlayerController_ActionTrackingServices*& ActionTrackingServices() = 0;
    virtual void ActionTrackingServicesUpdated() = 0;
    virtual CCSPlayerController_DamageServices*& DamageServices() = 0;
    virtual void DamageServicesUpdated() = 0;
    virtual uint32_t& Ping() = 0;
    virtual void PingUpdated() = 0;
    virtual bool& HasCommunicationAbuseMute() = 0;
    virtual void HasCommunicationAbuseMuteUpdated() = 0;
    virtual uint32_t& UiCommunicationMuteFlags() = 0;
    virtual void UiCommunicationMuteFlagsUpdated() = 0;
    virtual CUtlSymbolLarge& CrosshairCodes() = 0;
    virtual void CrosshairCodesUpdated() = 0;
    virtual uint8_t& PendingTeamNum() = 0;
    virtual void PendingTeamNumUpdated() = 0;
    virtual float& ForceTeamTime() = 0;
    virtual void ForceTeamTimeUpdated() = 0;
    virtual int32_t& CompTeammateColor() = 0;
    virtual void CompTeammateColorUpdated() = 0;
    virtual bool& EverPlayedOnTeam() = 0;
    virtual void EverPlayedOnTeamUpdated() = 0;
    virtual bool& AttemptedToGetColor() = 0;
    virtual void AttemptedToGetColorUpdated() = 0;
    virtual int32_t& TeammatePreferredColor() = 0;
    virtual void TeammatePreferredColorUpdated() = 0;
    virtual bool& TeamChanged() = 0;
    virtual void TeamChangedUpdated() = 0;
    virtual bool& InSwitchTeam() = 0;
    virtual void InSwitchTeamUpdated() = 0;
    virtual bool& HasSeenJoinGame() = 0;
    virtual void HasSeenJoinGameUpdated() = 0;
    virtual bool& JustBecameSpectator() = 0;
    virtual void JustBecameSpectatorUpdated() = 0;
    virtual bool& SwitchTeamsOnNextRoundReset() = 0;
    virtual void SwitchTeamsOnNextRoundResetUpdated() = 0;
    virtual bool& RemoveAllItemsOnNextRoundReset() = 0;
    virtual void RemoveAllItemsOnNextRoundResetUpdated() = 0;
    virtual float& LastJoinTeamTime() = 0;
    virtual void LastJoinTeamTimeUpdated() = 0;
    virtual CUtlSymbolLarge& Clan() = 0;
    virtual void ClanUpdated() = 0;
    virtual int32_t& CoachingTeam() = 0;
    virtual void CoachingTeamUpdated() = 0;
    virtual uint64_t& PlayerDominated() = 0;
    virtual void PlayerDominatedUpdated() = 0;
    virtual uint64_t& PlayerDominatingMe() = 0;
    virtual void PlayerDominatingMeUpdated() = 0;
    virtual int32_t& CompetitiveRanking() = 0;
    virtual void CompetitiveRankingUpdated() = 0;
    virtual int32_t& CompetitiveWins() = 0;
    virtual void CompetitiveWinsUpdated() = 0;
    virtual int8_t& CompetitiveRankType() = 0;
    virtual void CompetitiveRankTypeUpdated() = 0;
    virtual int32_t& CompetitiveRankingPredicted_Win() = 0;
    virtual void CompetitiveRankingPredicted_WinUpdated() = 0;
    virtual int32_t& CompetitiveRankingPredicted_Loss() = 0;
    virtual void CompetitiveRankingPredicted_LossUpdated() = 0;
    virtual int32_t& CompetitiveRankingPredicted_Tie() = 0;
    virtual void CompetitiveRankingPredicted_TieUpdated() = 0;
    virtual int32_t& EndMatchNextMapVote() = 0;
    virtual void EndMatchNextMapVoteUpdated() = 0;
    virtual uint16_t& ActiveQuestId() = 0;
    virtual void ActiveQuestIdUpdated() = 0;
    virtual uint32_t& RtActiveMissionPeriod() = 0;
    virtual void RtActiveMissionPeriodUpdated() = 0;
    virtual ::QuestProgress__Reason& QuestProgressReason() = 0;
    virtual void QuestProgressReasonUpdated() = 0;
    virtual uint32_t& PlayerTvControlFlags() = 0;
    virtual void PlayerTvControlFlagsUpdated() = 0;
    virtual int32_t& DraftIndex() = 0;
    virtual void DraftIndexUpdated() = 0;
    virtual uint32_t& MsQueuedModeDisconnectionTimestamp() = 0;
    virtual void MsQueuedModeDisconnectionTimestampUpdated() = 0;
    virtual uint32_t& UiAbandonRecordedReason() = 0;
    virtual void UiAbandonRecordedReasonUpdated() = 0;
    virtual uint32_t& NetworkDisconnectionReason() = 0;
    virtual void NetworkDisconnectionReasonUpdated() = 0;
    virtual bool& CannotBeKicked() = 0;
    virtual void CannotBeKickedUpdated() = 0;
    virtual bool& EverFullyConnected() = 0;
    virtual void EverFullyConnectedUpdated() = 0;
    virtual bool& AbandonAllowsSurrender() = 0;
    virtual void AbandonAllowsSurrenderUpdated() = 0;
    virtual bool& AbandonOffersInstantSurrender() = 0;
    virtual void AbandonOffersInstantSurrenderUpdated() = 0;
    virtual bool& Disconnection1MinWarningPrinted() = 0;
    virtual void Disconnection1MinWarningPrintedUpdated() = 0;
    virtual bool& ScoreReported() = 0;
    virtual void ScoreReportedUpdated() = 0;
    virtual int32_t& DisconnectionTick() = 0;
    virtual void DisconnectionTickUpdated() = 0;
    virtual bool& ControllingBot() = 0;
    virtual void ControllingBotUpdated() = 0;
    virtual bool& HasControlledBotThisRound() = 0;
    virtual void HasControlledBotThisRoundUpdated() = 0;
    virtual bool& HasBeenControlledByPlayerThisRound() = 0;
    virtual void HasBeenControlledByPlayerThisRoundUpdated() = 0;
    virtual int32_t& BotsControlledThisRound() = 0;
    virtual void BotsControlledThisRoundUpdated() = 0;
    virtual bool& CanControlObservedBot() = 0;
    virtual void CanControlObservedBotUpdated() = 0;
    virtual CHandle<CCSPlayerPawn>& PlayerPawn() = 0;
    virtual void PlayerPawnUpdated() = 0;
    virtual CHandle<CCSObserverPawn>& ObserverPawn() = 0;
    virtual void ObserverPawnUpdated() = 0;
    virtual int32_t& DesiredObserverMode() = 0;
    virtual void DesiredObserverModeUpdated() = 0;
    virtual CEntityHandle& DesiredObserverTarget() = 0;
    virtual void DesiredObserverTargetUpdated() = 0;
    virtual bool& PawnIsAlive() = 0;
    virtual void PawnIsAliveUpdated() = 0;
    virtual uint32_t& PawnHealth() = 0;
    virtual void PawnHealthUpdated() = 0;
    virtual int32_t& PawnArmor() = 0;
    virtual void PawnArmorUpdated() = 0;
    virtual bool& PawnHasDefuser() = 0;
    virtual void PawnHasDefuserUpdated() = 0;
    virtual bool& PawnHasHelmet() = 0;
    virtual void PawnHasHelmetUpdated() = 0;
    virtual uint16_t& PawnCharacterDefIndex() = 0;
    virtual void PawnCharacterDefIndexUpdated() = 0;
    virtual int32_t& PawnLifetimeStart() = 0;
    virtual void PawnLifetimeStartUpdated() = 0;
    virtual int32_t& PawnLifetimeEnd() = 0;
    virtual void PawnLifetimeEndUpdated() = 0;
    virtual int32_t& PawnBotDifficulty() = 0;
    virtual void PawnBotDifficultyUpdated() = 0;
    virtual CHandle<CCSPlayerController>& OriginalControllerOfCurrentPawn() = 0;
    virtual void OriginalControllerOfCurrentPawnUpdated() = 0;
    virtual int32_t& Score() = 0;
    virtual void ScoreUpdated() = 0;
    virtual int32_t& RoundScore() = 0;
    virtual void RoundScoreUpdated() = 0;
    virtual int32_t& RoundsWon() = 0;
    virtual void RoundsWonUpdated() = 0;
    virtual uint8_t* RecentKillQueue() = 0;
    virtual uint8_t& FirstKill() = 0;
    virtual void FirstKillUpdated() = 0;
    virtual uint8_t& KillCount() = 0;
    virtual void KillCountUpdated() = 0;
    virtual bool& MvpNoMusic() = 0;
    virtual void MvpNoMusicUpdated() = 0;
    virtual int32_t& MvpReason() = 0;
    virtual void MvpReasonUpdated() = 0;
    virtual int32_t& MusicKitID() = 0;
    virtual void MusicKitIDUpdated() = 0;
    virtual int32_t& MusicKitMVPs() = 0;
    virtual void MusicKitMVPsUpdated() = 0;
    virtual int32_t& MVPs() = 0;
    virtual void MVPsUpdated() = 0;
    virtual int32_t& UpdateCounter() = 0;
    virtual void UpdateCounterUpdated() = 0;
    virtual float& SmoothedPing() = 0;
    virtual void SmoothedPingUpdated() = 0;
    virtual ::IntervalTimer& LastHeldVoteTimer() = 0;
    virtual void LastHeldVoteTimerUpdated() = 0;
    virtual bool& ShowHints() = 0;
    virtual void ShowHintsUpdated() = 0;
    virtual int32_t& NextTimeCheck() = 0;
    virtual void NextTimeCheckUpdated() = 0;
    virtual bool& JustDidTeamKill() = 0;
    virtual void JustDidTeamKillUpdated() = 0;
    virtual bool& PunishForTeamKill() = 0;
    virtual void PunishForTeamKillUpdated() = 0;
    virtual bool& GaveTeamDamageWarning() = 0;
    virtual void GaveTeamDamageWarningUpdated() = 0;
    virtual bool& GaveTeamDamageWarningThisRound() = 0;
    virtual void GaveTeamDamageWarningThisRoundUpdated() = 0;
    virtual double& DblLastReceivedPacketPlatFloatTime() = 0;
    virtual void DblLastReceivedPacketPlatFloatTimeUpdated() = 0;
    virtual float& LastTeamDamageWarningTime() = 0;
    virtual void LastTeamDamageWarningTimeUpdated() = 0;
    virtual float& LastTimePlayerWasDisconnectedForPawnsRemove() = 0;
    virtual void LastTimePlayerWasDisconnectedForPawnsRemoveUpdated() = 0;
    virtual uint32_t& SuspiciousHitCount() = 0;
    virtual void SuspiciousHitCountUpdated() = 0;
    virtual uint32_t& NonSuspiciousHitStreak() = 0;
    virtual void NonSuspiciousHitStreakUpdated() = 0;
    virtual bool& FireBulletsSeedSynchronized() = 0;
    virtual void FireBulletsSeedSynchronizedUpdated() = 0;

    /// <summary>Print to console.</summary>
    virtual void PrintToConsole(const char* pszMessage) = 0;
    /// <summary>Print to chat.</summary>
    virtual void PrintToChat(const char* pszMessage) = 0;
    /// <summary>Print to center.</summary>
    virtual void PrintToCenter(const char* pszMessage) = 0;
    /// <summary>Print alert.</summary>
    virtual void PrintToCenterAlert(const char* pszMessage) = 0;
    /// <summary>Print to center in HTML.</summary>
    virtual void PrintToCenterHtml(const char* pszMessage, int iDuration = 5) = 0;
    /// <summary>Take damage from player</summary>
    virtual void TakeDamage(ICSPlayerController* pAttacker, int iDamage, DamageTypes_t bitsDamageType) = 0;
    /// <summary>Respawn player.</summary>
    virtual void Respawn() = 0;
    /// <summary>Switch team without killing.</summary>
    virtual void SwitchTeam(int nTeam) = 0;
    /// <summary>Change team like jointeam.</summary>
    virtual void ChangeTeam(int nTeam) = 0;
    /// <summary>Is bot.</summary>
    virtual bool IsBot() = 0;
    /// <summary>Disconnect player.</summary>
    virtual void Disconnect(ENetworkDisconnectionReason eReason) = 0;
    /// <summary>Execute client command.</summary>
    virtual void ExecuteClientCommand(const char* pszCommand) = 0;
    /// <summary>Execute command from server.</summary>
    virtual void ExecuteClientCommandFromServer(const char* pszCommand) = 0;
    /// <summary>Get pawn.</summary>
    virtual ICSPlayerPawn* GetPawn() = 0;
    /// <summary>Get player pawn.</summary>
    virtual ICSPlayerPawn* GetPlayerPawn() = 0;
    /// <summary>Get observer pawn.</summary>
    virtual ICSObserverPawn* GetObserverPawn() = 0;
    /// <summary>Get player index.</summary>
    virtual CEntityIndex GetPlayerIndex() = 0;
    /// <summary>Get slot.</summary>
    virtual int GetSlot() = 0;
    /// <summary>Get player slot.</summary>
    virtual CPlayerSlot GetPlayerSlot() = 0;
    /// <summary>Get steamid.</summary>
    virtual int GetUserID() = 0;
    /// <summary>Get player userid.</summary>
    virtual CPlayerUserId GetPlayerUserID() = 0;
    /// <summary>Get steamid.</summary>
    virtual uint64 GetSteamID() = 0;
    /// <summary>Get player steamid.</summary>
    virtual CSteamID GetPlayerSteamID() = 0;
    /// <summary>Get player name.</summary>
    virtual const char* GetPlayerName() = 0;
    /// <summary>Get IP address.</summary>
    virtual CUtlString GetIpAddress() = 0;
    /// <summary>Replicate convar.</summary>
    virtual void ReplicateConVar(const char* pszConVar, const char* pszValue) = 0;
    /// <summary>Fires gameEvent to client's legacy listener.</summary>
    virtual void FireEventToClient(IGameEvent* pEvent) = 0;

    /// <summary>Get controller from pawn.</summary>
    static ICSPlayerController* FromPawn(ICSPlayerPawn* pPawn);
    /// <summary>Get controller from slot.</summary>
    static ICSPlayerController* FromSlot(int iSlot);
    /// <summary>Get controller from slot.</summary>
    static ICSPlayerController* FromSlot(CPlayerSlot slot);
    /// <summary>Get controller from user id.</summary>
    static ICSPlayerController* FromUserId(int iUserId);
    /// <summary>Get controller from user id.</summary>
    static ICSPlayerController* FromUserId(CPlayerUserId userId);
    /// <summary>Get controller from steam id.</summary>
    static ICSPlayerController* FromSteamId(uint64 uSteamId);
    /// <summary>Get controller from steam id.</summary>
    static ICSPlayerController* FromSteamId(CSteamID steamId);
    static ICSPlayerController* FromOriginal(CCSPlayerController* p);
};

#endif // _INCLUDE_ICSPLAYERCONTROLLER_H
