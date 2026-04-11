//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_ADDRESSES_H
#define _INCLUDE_ITOOLKIT_ADDRESSES_H

#pragma once
#include "IToolkitTypes.h"

#include "igameevents.h"
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Forward declarations
   ========================= */

class CEntityInstance;
class CEntityIOOutput;
class CEntitySystem;
class CEntityKeyValues;
class CBaseEntity;
class CBasePlayerWeapon;
class CBaseModelEntity;
class CBasePlayerPawn;
class CBasePlayerController;
class CGameRules;
class CCSPlayerController;
class IGameEventListener2;
class IGameEventManager2;
class IEntityFindFilter;

using CBaseEntity_CreateEntityByName_t = CBaseEntity* (FASTCALL*)(const char*, int);
using CBaseEntity_DispatchSpawn_t = void (FASTCALL*)(CBaseEntity*, CEntityKeyValues*);
using CBaseModelEntity_SetModel_t = void (FASTCALL*)(CBaseModelEntity*, const char*);
using CBasePlayerController_SetPawn_t = void (FASTCALL*)(CBasePlayerController*, CBasePlayerPawn*, bool, bool, bool, bool);
using CBasePlayerPawn_RemovePlayerItem_t = void (FASTCALL*)(CBasePlayerPawn*, CBasePlayerWeapon*);
using CGameRules_TerminateRound_t = void (FASTCALL*)(CGameRules*, float, unsigned int, int64, unsigned int);
using CCSPlayerController_LegacyGameEventListener_t = IGameEventListener2* (FASTCALL*)(CPlayerSlot);
using CCSPlayerController_SwitchTeam_t = void (FASTCALL*)(CCSPlayerController*, unsigned char);
using CEntityInstance_AcceptInput_t = void (FASTCALL*)(CEntityInstance*, const char*, CEntityInstance*, CEntityInstance*, const variant_t&, int, void*);
using CEntityIOOutput_FireOutputInternal_t = void (FASTCALL*)(CEntityIOOutput*, CEntityInstance*, CEntityInstance*, void*, float, void*, void*);
using CEntitySystem_AddEntityIOEvent_t = void (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*, CEntityInstance*, CEntityInstance*, const variant_t&, float, int, void*, void*);
using CGameEntitySystem_FindEntityByClassName_t = CBaseEntity* (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*);
using CGameEntitySystem_FindEntityByName_t = CBaseEntity* (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*, CEntityInstance*, CEntityInstance*, CEntityInstance*, IEntityFindFilter*);
using CGameEventManager_Init_t = void (FASTCALL*)(IGameEventManager2*);

/* =========================
   Core Toolkit Addresses
   ========================= */

class IToolkitAddresses
{
public:
    virtual ~IToolkitAddresses() = default;

    virtual void* GetModuleHandle(const char* moduleName) = 0;
    virtual uintptr_t GetModuleBase(const char* moduleName) = 0;

    virtual uintptr_t FindPattern(const char* moduleName, const char* pattern) = 0;
    virtual uintptr_t FindPatternInSection(const char* moduleName, const char* section, const char* pattern) = 0;

    virtual uintptr_t GetFunctionByName(const char* moduleName, const char* symbol) = 0;
    virtual uintptr_t GetVirtualTableByName(const char* moduleName, const char* name) = 0;

    virtual uintptr_t Offset(uintptr_t address, ptrdiff_t offset) = 0;
    virtual uintptr_t OffsetSelf(uintptr_t& address, ptrdiff_t offset) = 0;

    virtual uintptr_t Deref(uintptr_t address, int count = 1) = 0;
    virtual uintptr_t DerefSelf(uintptr_t& address, int count = 1) = 0;

    virtual uintptr_t ResolveRelativeAddress(uintptr_t address, ptrdiff_t offset = 0x0, ptrdiff_t size = 0x4) = 0;
    virtual uintptr_t FollowNearCall(uintptr_t address, ptrdiff_t offset = 0x1, ptrdiff_t size = 0x5) = 0;

    virtual CBaseEntity_CreateEntityByName_t CBaseEntity_CreateEntityByName() = 0;
    virtual CBaseEntity_DispatchSpawn_t CBaseEntity_DispatchSpawn() = 0;
    virtual CBaseModelEntity_SetModel_t CBaseModelEntity_SetModel() = 0;
    virtual CBasePlayerController_SetPawn_t CBasePlayerController_SetPawn() = 0;
    virtual CBasePlayerPawn_RemovePlayerItem_t CBasePlayerPawn_RemovePlayerItem() = 0;
    virtual CGameRules_TerminateRound_t CGameRules_TerminateRound() = 0;
    virtual CCSPlayerController_LegacyGameEventListener_t CCSPlayerController_LegacyGameEventListener() = 0;
    virtual CCSPlayerController_SwitchTeam_t CCSPlayerController_SwitchTeam() = 0;
    virtual CEntityInstance_AcceptInput_t CEntityInstance_AcceptInput() = 0;
    virtual CEntityIOOutput_FireOutputInternal_t CEntityIOOutput_FireOutputInternal() = 0;
    virtual CEntitySystem_AddEntityIOEvent_t CEntitySystem_AddEntityIOEvent() = 0;
    virtual CGameEntitySystem_FindEntityByClassName_t CGameEntitySystem_FindEntityByClassName() = 0;
    virtual CGameEntitySystem_FindEntityByName_t CGameEntitySystem_FindEntityByName() = 0;
    virtual CGameEventManager_Init_t CGameEventManager_Init() = 0;
};

#endif //_INCLUDE_ITOOLKIT_ADDRESSES_H
