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

#include "inetchannel.h"
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
class NetMessageSplitscreenUserChanged_t :   public CNetMessagePB< NetMessageSplitscreenUserChanged > {};
class NetMessagePacketStart_t :              public CNetMessagePB< NetMessagePacketStart > {};
class NetMessagePacketEnd_t :                public CNetMessagePB< NetMessagePacketEnd > {};
class NetMessageConnectionClosed_t :         public CNetMessagePB< NetMessageConnectionClosed > {};
class NetMessageConnectionCrashed_t :        public CNetMessagePB< NetMessageConnectionCrashed > {};

/* =========================
Engine (net_*)
========================= */

/**

* @brief Core engine network messages.
  */
class CNETMsg_Tick_t :                       public CNetMessagePB< CNETMsg_Tick  > {};
class CNETMsg_StringCmd_t :                  public CNetMessagePB< CNETMsg_StringCmd > {};
class CNETMsg_SetConVar_t :                  public CNetMessagePB< CNETMsg_SetConVar > {};
class CNETMsg_SignonState_t :                public CNetMessagePB< CNETMsg_SignonState > {};

/* =========================
Spawn groups
========================= */

class CNETMsg_SpawnGroup_Load_t :            public CNetMessagePB< CNETMsg_SpawnGroup_Load > {};
class CNETMsg_SpawnGroup_ManifestUpdate_t :  public CNetMessagePB< CNETMsg_SpawnGroup_ManifestUpdate > {};
class CNETMsg_SpawnGroup_SetCreationTick_t : public CNetMessagePB< CNETMsg_SpawnGroup_SetCreationTick > {};
class CNETMsg_SpawnGroup_Unload_t :          public CNetMessagePB< CNETMsg_SpawnGroup_Unload > {};
class CNETMsg_SpawnGroup_LoadCompleted_t :   public CNetMessagePB< CNETMsg_SpawnGroup_LoadCompleted > {};

/* =========================
Client → Server (clc_*)
========================= */

/**

* @brief Messages sent from client to server.
  */
class CCLCMsg_ClientInfo_t :                 public CNetMessagePB< CCLCMsg_ClientInfo > {};
class CCLCMsg_Move_t :                       public CNetMessagePB< CCLCMsg_Move > {};
class CCLCMsg_VoiceData_t :                  public CNetMessagePB< CCLCMsg_VoiceData > {};
class CCLCMsg_BaselineAck_t :                public CNetMessagePB< CCLCMsg_BaselineAck > {};
class CCLCMsg_LoadingProgress_t :            public CNetMessagePB< CCLCMsg_LoadingProgress > {};
class CCLCMsg_CmdKeyValues_t :               public CNetMessagePB< CCLCMsg_CmdKeyValues > {};

/* =========================
Server → Client (svc_*)
========================= */

/**

* @brief Messages sent from server to client.
  */
class CSVCMsg_ServerInfo_t :                 public CNetMessagePB< CSVCMsg_ServerInfo > {};
class CSVCMsg_ClassInfo_t :                  public CNetMessagePB< CSVCMsg_ClassInfo > {};
class CSVCMsg_CreateStringTable_t :          public CNetMessagePB< CSVCMsg_CreateStringTable > {};
class CSVCMsg_UpdateStringTable_t :          public CNetMessagePB< CSVCMsg_UpdateStringTable > {};
class CSVCMsg_Print_t :                      public CNetMessagePB< CSVCMsg_Print > {};
class CSVCMsg_Sounds_t :                     public CNetMessagePB< CSVCMsg_Sounds > {};
class CSVCMsg_SetView_t :                    public CNetMessagePB< CSVCMsg_SetView > {};
class CSVCMsg_PacketEntities_t :             public CNetMessagePB< CSVCMsg_PacketEntities > {};
class CSVCMsg_UserMessage_t :                public CNetMessagePB< CSVCMsg_UserMessage > {};

#endif // NETMESSAGES_H
