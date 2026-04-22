/**

* @file IToolkitAddresses.h
* @brief Low-level address and symbol resolution interface for Source2Toolkit.
*
* This interface provides utilities for:
* * Module inspection (base, handle)
* * Pattern scanning
* * Symbol resolution
* * Pointer manipulation (offsets, dereferencing)
* * Access to resolved engine functions
*
* @note This is a low-level API. Most users should prefer higher-level helpers (UTIL_*).
  */

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

#ifdef _WIN32
#undef GetModuleHandle
#endif

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

/* =========================
Function typedefs
========================= */

/**

* @brief Creates an entity by classname.
  */
using CBaseEntity_CreateEntityByName_t = CBaseEntity* (FASTCALL*)(const char*, int);

/**

* @brief Dispatches spawn on an entity.
  */
using CBaseEntity_DispatchSpawn_t = void (FASTCALL*)(CBaseEntity*, CEntityKeyValues*);

/**

* @brief Sets model on entity.
  */
using CBaseModelEntity_SetModel_t = void (FASTCALL*)(CBaseModelEntity*, const char*);

/**

* @brief Assigns pawn to player controller.
  */
using CBasePlayerController_SetPawn_t = void (FASTCALL*)(CBasePlayerController*, CBasePlayerPawn*, bool, bool, bool,
                                                         bool);

/**

* @brief Removes weapon from player pawn.
  */
using CBasePlayerPawn_RemovePlayerItem_t = void (FASTCALL*)(CBasePlayerPawn*, CBasePlayerWeapon*);

/**

* @brief Terminates current round.
  */
using CGameRules_TerminateRound_t = void (FASTCALL*)(CGameRules*, float, unsigned int, int64, unsigned int);

/**

* @brief Retrieves legacy game event listener.
  */
using CCSPlayerController_LegacyGameEventListener_t = IGameEventListener2* (FASTCALL*)(CPlayerSlot);

/**

* @brief Switches player team.
  */
using CCSPlayerController_SwitchTeam_t = void (FASTCALL*)(CCSPlayerController*, unsigned char);

/**

* @brief Accepts entity input.
  */
using CEntityInstance_AcceptInput_t = void (FASTCALL*)(CEntityInstance*, const char*, CEntityInstance*,
                                                       CEntityInstance*, const variant_t&, int, void*);

/**

* @brief Fires entity output internally.
  */
using CEntityIOOutput_FireOutputInternal_t = void (FASTCALL*)(CEntityIOOutput*, CEntityInstance*, CEntityInstance*,
                                                              void*, float, void*, void*);

/**

* @brief Adds entity IO event.
  */
using CEntitySystem_AddEntityIOEvent_t = void (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*,
                                                          CEntityInstance*, CEntityInstance*, const variant_t&, float,
                                                          int, void*, void*);

/**

* @brief Finds entity by classname.
  */
using CGameEntitySystem_FindEntityByClassName_t = CBaseEntity* (FASTCALL*)(
    CEntitySystem*, CEntityInstance*, const char*);

/**

* @brief Finds entity by name.
  */
using CGameEntitySystem_FindEntityByName_t = CBaseEntity* (FASTCALL*)(CEntitySystem*, CEntityInstance*, const char*,
                                                                      CEntityInstance*, CEntityInstance*,
                                                                      CEntityInstance*, IEntityFindFilter*);

/* =========================
Core Toolkit Addresses
========================= */

/**

* @brief Interface for resolving engine addresses, symbols and functions.
*
* This interface abstracts:
* * Pattern scanning
* * Symbol lookup
* * Virtual table access
* * Pointer manipulation
*
* It also exposes resolved engine functions as callable function pointers.
  */
class IToolkitAddresses
{
public:
    virtual ~IToolkitAddresses() = default;

    /* =========================
    Module utilities
    ========================= */

    /**

    * @brief Gets OS-specific module handle.
    * @param modulePtr Module identifier or pointer.
    * @return Native module handle.
      */
    virtual void* GetModuleHandle(void* modulePtr) = 0;

    /**

    * @brief Gets module base address.
      */
    virtual uintptr_t GetModuleBase(void* modulePtr) = 0;

    /**

    * @brief Gets module absolute path.
      */
    virtual const char* GetModulePath(void* modulePtr) = 0;

    /* =========================
    Pattern scanning
    ========================= */

    /**

    * @brief Finds pattern in module memory.
      */
    virtual uintptr_t FindPattern(void* modulePtr, const char* pattern) = 0;

    /**

    * @brief Finds pattern in a specific section.
      */
    virtual uintptr_t FindPatternInSection(void* modulePtr, const char* section, const char* pattern) = 0;

    /* =========================
    Symbol / VTable
    ========================= */

    /**

    * @brief Gets function address by exported symbol name.
      */
    virtual uintptr_t GetFunctionByName(void* modulePtr, const char* symbol) = 0;

    /**

    * @brief Gets virtual table address by class name.
      */
    virtual uintptr_t GetVirtualTableByName(void* modulePtr, const char* name) = 0;

    /* =========================
    Pointer utilities
    ========================= */

    /**

    * @brief Applies offset to address.
      */
    virtual uintptr_t Offset(uintptr_t address, ptrdiff_t offset) = 0;

    /**

    * @brief Applies offset directly to variable.
      */
    virtual uintptr_t OffsetSelf(uintptr_t& address, ptrdiff_t offset) = 0;

    /**

    * @brief Dereferences pointer N times.
      */
    virtual uintptr_t Deref(uintptr_t address, int count = 1) = 0;

    /**

    * @brief Dereferences pointer in-place.
      */
    virtual uintptr_t DerefSelf(uintptr_t& address, int count = 1) = 0;

    /**

    * @brief Resolves relative address (RIP-relative).
      */
    virtual uintptr_t ResolveRelativeAddress(uintptr_t address, ptrdiff_t offset = 0x0, ptrdiff_t size = 0x4) = 0;

    /**

    * @brief Follows near CALL instruction.
      */
    virtual uintptr_t FollowNearCall(uintptr_t address, ptrdiff_t offset = 0x1, ptrdiff_t size = 0x5) = 0;

public:
    /* =========================
    Resolved engine functions
    ========================= */

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
};

#endif //_INCLUDE_ITOOLKIT_ADDRESSES_H
