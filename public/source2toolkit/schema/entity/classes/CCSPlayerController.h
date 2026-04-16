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

#include "CBasePlayerController.h"
#include "IntervalTimer.h"

class CCSObserverPawn;
class CCSPlayerController_ActionTrackingServices;
class CCSPlayerController_DamageServices;
class CCSPlayerController_InGameMoneyServices;
class CCSPlayerController_InventoryServices;
class CCSPlayerPawn;

class CCSPlayerController : public CBasePlayerController
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerController);

    SCHEMA_FIELD(CCSPlayerController_InGameMoneyServices*, m_pInGameMoneyServices);
    SCHEMA_FIELD(CCSPlayerController_InventoryServices*, m_pInventoryServices);
    SCHEMA_FIELD(CCSPlayerController_ActionTrackingServices*, m_pActionTrackingServices);
    SCHEMA_FIELD(CCSPlayerController_DamageServices*, m_pDamageServices);
    SCHEMA_FIELD(uint32_t, m_iPing);
    SCHEMA_FIELD(bool, m_bHasCommunicationAbuseMute);
    SCHEMA_FIELD(uint32_t, m_uiCommunicationMuteFlags);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szCrosshairCodes);
    SCHEMA_FIELD(uint8_t, m_iPendingTeamNum);
    SCHEMA_FIELD(float, m_flForceTeamTime);
    SCHEMA_FIELD(int32_t, m_iCompTeammateColor);
    SCHEMA_FIELD(bool, m_bEverPlayedOnTeam);
    SCHEMA_FIELD(bool, m_bAttemptedToGetColor);
    SCHEMA_FIELD(int32_t, m_iTeammatePreferredColor);
    SCHEMA_FIELD(bool, m_bTeamChanged);
    SCHEMA_FIELD(bool, m_bInSwitchTeam);
    SCHEMA_FIELD(bool, m_bHasSeenJoinGame);
    SCHEMA_FIELD(bool, m_bJustBecameSpectator);
    SCHEMA_FIELD(bool, m_bSwitchTeamsOnNextRoundReset);
    SCHEMA_FIELD(bool, m_bRemoveAllItemsOnNextRoundReset);
    SCHEMA_FIELD(float, m_flLastJoinTeamTime);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szClan);
    SCHEMA_FIELD(int32_t, m_iCoachingTeam);
    SCHEMA_FIELD(uint64_t, m_nPlayerDominated);
    SCHEMA_FIELD(uint64_t, m_nPlayerDominatingMe);
    SCHEMA_FIELD(int32_t, m_iCompetitiveRanking);
    SCHEMA_FIELD(int32_t, m_iCompetitiveWins);
    SCHEMA_FIELD(int8_t, m_iCompetitiveRankType);
    SCHEMA_FIELD(int32_t, m_iCompetitiveRankingPredicted_Win);
    SCHEMA_FIELD(int32_t, m_iCompetitiveRankingPredicted_Loss);
    SCHEMA_FIELD(int32_t, m_iCompetitiveRankingPredicted_Tie);
    SCHEMA_FIELD(int32_t, m_nEndMatchNextMapVote);
    SCHEMA_FIELD(uint16_t, m_unActiveQuestId);
    SCHEMA_FIELD(uint32_t, m_rtActiveMissionPeriod);
    SCHEMA_FIELD(uint32_t, m_unPlayerTvControlFlags);
    SCHEMA_FIELD(int32_t, m_iDraftIndex);
    SCHEMA_FIELD(uint32_t, m_msQueuedModeDisconnectionTimestamp);
    SCHEMA_FIELD(uint32_t, m_uiAbandonRecordedReason);
    SCHEMA_FIELD(uint32_t, m_eNetworkDisconnectionReason);
    SCHEMA_FIELD(bool, m_bCannotBeKicked);
    SCHEMA_FIELD(bool, m_bEverFullyConnected);
    SCHEMA_FIELD(bool, m_bAbandonAllowsSurrender);
    SCHEMA_FIELD(bool, m_bAbandonOffersInstantSurrender);
    SCHEMA_FIELD(bool, m_bDisconnection1MinWarningPrinted);
    SCHEMA_FIELD(bool, m_bScoreReported);
    SCHEMA_FIELD(int32_t, m_nDisconnectionTick);
    SCHEMA_FIELD(bool, m_bControllingBot);
    SCHEMA_FIELD(bool, m_bHasControlledBotThisRound);
    SCHEMA_FIELD(bool, m_bHasBeenControlledByPlayerThisRound);
    SCHEMA_FIELD(int32_t, m_nBotsControlledThisRound);
    SCHEMA_FIELD(bool, m_bCanControlObservedBot);
    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_hPlayerPawn);
    SCHEMA_FIELD(CHandle<CCSObserverPawn>, m_hObserverPawn);
    SCHEMA_FIELD(int32_t, m_DesiredObserverMode);
    SCHEMA_FIELD(CEntityHandle, m_hDesiredObserverTarget);
    SCHEMA_FIELD(bool, m_bPawnIsAlive);
    SCHEMA_FIELD(uint32_t, m_iPawnHealth);
    SCHEMA_FIELD(int32_t, m_iPawnArmor);
    SCHEMA_FIELD(bool, m_bPawnHasDefuser);
    SCHEMA_FIELD(bool, m_bPawnHasHelmet);
    SCHEMA_FIELD(uint16_t, m_nPawnCharacterDefIndex);
    SCHEMA_FIELD(int32_t, m_iPawnLifetimeStart);
    SCHEMA_FIELD(int32_t, m_iPawnLifetimeEnd);
    SCHEMA_FIELD(int32_t, m_iPawnBotDifficulty);
    SCHEMA_FIELD(CHandle<CCSPlayerController>, m_hOriginalControllerOfCurrentPawn);
    SCHEMA_FIELD(int32_t, m_iScore);
    SCHEMA_FIELD(int32_t, m_iRoundScore);
    SCHEMA_FIELD(int32_t, m_iRoundsWon);
    SCHEMA_FIELD_POINTER(uint8_t, m_recentKillQueue);
    SCHEMA_FIELD(uint8_t, m_nFirstKill);
    SCHEMA_FIELD(uint8_t, m_nKillCount);
    SCHEMA_FIELD(bool, m_bMvpNoMusic);
    SCHEMA_FIELD(int32_t, m_eMvpReason);
    SCHEMA_FIELD(int32_t, m_iMusicKitID);
    SCHEMA_FIELD(int32_t, m_iMusicKitMVPs);
    SCHEMA_FIELD(int32_t, m_iMVPs);
    SCHEMA_FIELD(int32_t, m_nUpdateCounter);
    SCHEMA_FIELD(float, m_flSmoothedPing);
    SCHEMA_FIELD(IntervalTimer, m_lastHeldVoteTimer);
    SCHEMA_FIELD(bool, m_bShowHints);
    SCHEMA_FIELD(int32_t, m_iNextTimeCheck);
    SCHEMA_FIELD(bool, m_bJustDidTeamKill);
    SCHEMA_FIELD(bool, m_bPunishForTeamKill);
    SCHEMA_FIELD(bool, m_bGaveTeamDamageWarning);
    SCHEMA_FIELD(bool, m_bGaveTeamDamageWarningThisRound);
    SCHEMA_FIELD(double, m_dblLastReceivedPacketPlatFloatTime);
    SCHEMA_FIELD(float, m_LastTeamDamageWarningTime);
    SCHEMA_FIELD(float, m_LastTimePlayerWasDisconnectedForPawnsRemove);
    SCHEMA_FIELD(uint32_t, m_nSuspiciousHitCount);
    SCHEMA_FIELD(uint32_t, m_nNonSuspiciousHitStreak);
    SCHEMA_FIELD(bool, m_bFireBulletsSeedSynchronized);

public:
    /// <summary>Get controller from pawn.</summary>
    static CCSPlayerController* FromPawn(CCSPlayerPawn* pPawn);
    /// <summary>Get controller from slot.</summary>
    static CCSPlayerController* FromSlot(int iSlot);
    /// <summary>Get controller from slot.</summary>
    static CCSPlayerController* FromSlot(CPlayerSlot slot);
    /// <summary>Get controller from user id.</summary>
    static CCSPlayerController* FromUserId(int iUserId);
    /// <summary>Get controller from user id.</summary>
    static CCSPlayerController* FromUserId(CPlayerUserId userId);
    /// <summary>Get controller from steam id.</summary>
    static CCSPlayerController* FromSteamId(uint64 uSteamId);
    /// <summary>Get controller from steam id.</summary>
    static CCSPlayerController* FromSteamId(CSteamID steamId);
    /// <summary>Print to console.</summary>
    void PrintToConsole(const char* pszMessage);
    /// <summary>Print to chat.</summary>
    void PrintToChat(const char* pszMessage);
    /// <summary>Print to center.</summary>
    void PrintToCenter(const char* pszMessage);
    /// <summary>Print alert.</summary>
    void PrintToCenterAlert(const char* pszMessage);
    /// <summary>Print to center in HTML.</summary>
    void PrintToCenterHtml(const char* pszMessage, int iDuration = 5);
    /// <summary>Respawn player.</summary>
    void Respawn();
    /// <summary>Switch team without killing.</summary>
    void SwitchTeam(int nTeam);
    /// <summary>Change team like jointeam.</summary>
    void ChangeTeam(int nTeam);
    /// <summary>Is bot.</summary>
    bool IsBot();
    /// <summary>Disconnect player.</summary>
    void Disconnect(ENetworkDisconnectionReason eReason);
    /// <summary>Execute client command.</summary>
    void ExecuteClientCommand(const char* pszCommand);
    /// <summary>Execute command from server.</summary>
    void ExecuteClientCommandFromServer(const char* pszCommand);
    /// <summary>Get pawn.</summary>
    CCSPlayerPawn* GetPawn();
    /// <summary>Get player pawn.</summary>
    CCSPlayerPawn* GetPlayerPawn();
    /// <summary>Get observer pawn.</summary>
    CCSObserverPawn* GetObserverPawn();
    /// <summary>Get player index.</summary>
    CEntityIndex GetPlayerIndex();
    /// <summary>Get slot.</summary>
    int GetSlot();
    /// <summary>Get player slot.</summary>
    CPlayerSlot GetPlayerSlot();
    /// <summary>Get steamid.</summary>
    int GetUserID();
    /// <summary>Get player userid.</summary>
    CPlayerUserId GetPlayerUserID();
    /// <summary>Get steamid.</summary>
    uint64 GetSteamID();
    /// <summary>Get player steamid.</summary>
    CSteamID GetPlayerSteamID();
    /// <summary>Get player name.</summary>
    const char* GetPlayerName();
    /// <summary>Get IP address.</summary>
    CUtlString GetIpAddress();
    /// <summary>Replicate convar.</summary>
    void ReplicateConVar(const char* pszConVar, const char* pszValue);
    /// <summary>Fires gameEvent to client's legacy listener.</summary>
    void FireEventToClient(IGameEvent* pEvent);

public:
    static CCSPlayerController* New(const char* className)
    {
        return CBaseEntity::New<CCSPlayerController>(className);
    }

    static CCSPlayerController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPlayerController>(iIndex);
    }

    static CCSPlayerController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
