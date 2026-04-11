/**

* @file netmessages.h
* @brief Network message wrappers for Source2 networking system.
*
* This file defines strongly-typed wrappers around protobuf-based
* network messages used by the engine.
*
* Messages are grouped into categories:
* * net_* → core networking
* * clc_* → client → server
* * svc_* → server → client
*
* @note All classes inherit from CNetMessagePB.
* @note Template parameters define message ID, protobuf type, group and flags.
  */

#pragma once

#ifndef NETMESSAGES_H
#define NETMESSAGES_H

#include "netchannel.h"
#include "networksystem/netmessage.h"
#include "netmessages.pb.h"
#include "networkbasetypes.pb.h"
#include "networksystem_protomessages.pb.h"

#undef min
#undef max

/* =========================
System messages
========================= */

/**

* @brief Internal engine/system messages.
  */
class NetMessageSplitscreenUserChanged_t :   public CNetMessagePB< -1, NetMessageSplitscreenUserChanged, SG_SYSTEM > {};
class NetMessagePacketStart_t :              public CNetMessagePB< -1, NetMessagePacketStart, SG_SYSTEM > {};
class NetMessagePacketEnd_t :                public CNetMessagePB< -1, NetMessagePacketEnd, SG_SYSTEM > {};
class NetMessageConnectionClosed_t :         public CNetMessagePB< -1, NetMessageConnectionClosed, SG_SYSTEM > {};
class NetMessageConnectionCrashed_t :        public CNetMessagePB< -1, NetMessageConnectionCrashed, SG_SYSTEM > {};

/* =========================
Engine (net_*)
========================= */

/**

* @brief Core engine network messages.
  */
class CNETMsg_Tick_t :                       public CNetMessagePB< net_Tick, CNETMsg_Tick, SG_ENGINE, BUF_UNRELIABLE > {};
class CNETMsg_StringCmd_t :                  public CNetMessagePB< net_StringCmd, CNETMsg_StringCmd, SG_STRINGCMD > {};
class CNETMsg_SetConVar_t :                  public CNetMessagePB< net_SetConVar, CNETMsg_SetConVar, SG_STRINGCMD > {};
class CNETMsg_SignonState_t :                public CNetMessagePB< net_SignonState, CNETMsg_SignonState, SG_SIGNON > {};

/* =========================
Spawn groups
========================= */

class CNETMsg_SpawnGroup_Load_t :            public CNetMessagePB< net_SpawnGroup_Load, CNETMsg_SpawnGroup_Load, SG_SPAWNGROUPS > {};
class CNETMsg_SpawnGroup_ManifestUpdate_t :  public CNetMessagePB< net_SpawnGroup_ManifestUpdate, CNETMsg_SpawnGroup_ManifestUpdate, SG_SPAWNGROUPS > {};
class CNETMsg_SpawnGroup_SetCreationTick_t : public CNetMessagePB< net_SpawnGroup_SetCreationTick, CNETMsg_SpawnGroup_SetCreationTick, SG_SPAWNGROUPS > {};
class CNETMsg_SpawnGroup_Unload_t :          public CNetMessagePB< net_SpawnGroup_Unload, CNETMsg_SpawnGroup_Unload, SG_SPAWNGROUPS > {};
class CNETMsg_SpawnGroup_LoadCompleted_t :   public CNetMessagePB< net_SpawnGroup_LoadCompleted, CNETMsg_SpawnGroup_LoadCompleted, SG_SPAWNGROUPS > {};

/* =========================
Client → Server (clc_*)
========================= */

/**

* @brief Messages sent from client to server.
  */
class CCLCMsg_ClientInfo_t :                 public CNetMessagePB< clc_ClientInfo, CCLCMsg_ClientInfo, SG_SIGNON > {};
class CCLCMsg_Move_t :                       public CNetMessagePB< clc_Move, CCLCMsg_Move, SG_MOVE, BUF_UNRELIABLE > {};
class CCLCMsg_VoiceData_t :                  public CNetMessagePB< clc_VoiceData, CCLCMsg_VoiceData, SG_VOICE > {};
class CCLCMsg_BaselineAck_t :                public CNetMessagePB< clc_BaselineAck, CCLCMsg_BaselineAck, SG_ENGINE > {};
class CCLCMsg_LoadingProgress_t :            public CNetMessagePB< clc_LoadingProgress, CCLCMsg_LoadingProgress, SG_SIGNON > {};
class CCLCMsg_CmdKeyValues_t :               public CNetMessagePB< clc_CmdKeyValues, CCLCMsg_CmdKeyValues, SG_STRINGCMD > {};

/* =========================
Server → Client (svc_*)
========================= */

/**

* @brief Messages sent from server to client.
  */
class CSVCMsg_ServerInfo_t :                 public CNetMessagePB< svc_ServerInfo, CSVCMsg_ServerInfo, SG_SIGNON > {};
class CSVCMsg_ClassInfo_t :                  public CNetMessagePB< svc_ClassInfo, CSVCMsg_ClassInfo, SG_SIGNON > {};
class CSVCMsg_CreateStringTable_t :          public CNetMessagePB< svc_CreateStringTable, CSVCMsg_CreateStringTable, SG_SIGNON > {};
class CSVCMsg_UpdateStringTable_t :          public CNetMessagePB< svc_UpdateStringTable, CSVCMsg_UpdateStringTable, SG_STRINGTABLE > {};
class CSVCMsg_Print_t :                      public CNetMessagePB< svc_Print, CSVCMsg_Print > {};
class CSVCMsg_Sounds_t :                     public CNetMessagePB< svc_Sounds, CSVCMsg_Sounds, SG_SOUNDS > {};
class CSVCMsg_SetView_t :                    public CNetMessagePB< svc_SetView, CSVCMsg_SetView > {};
class CSVCMsg_PacketEntities_t :             public CNetMessagePB< svc_PacketEntities, CSVCMsg_PacketEntities, SG_INVALID > {};
class CSVCMsg_UserMessage_t :                public CNetMessagePB< svc_UserMessage, CSVCMsg_UserMessage, SG_USERMSG > {};

#endif // NETMESSAGES_H
