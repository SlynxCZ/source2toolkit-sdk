/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

/**

* @file IToolkitAddresses.h
* @brief Resolved engine-function accessors for Source2Toolkit.
*
* Exposes pre-resolved function pointers for common engine operations.
* Module inspection, pattern scanning, symbol lookup, and pointer
* arithmetic are available via IToolkitModule and IToolkitMemory.
  */

#ifndef _INCLUDE_ITOOLKIT_ADDRESSES_H
#define _INCLUDE_ITOOLKIT_ADDRESSES_H

#pragma once
#include "IToolkitTypes.h"

#include "igameevents.h"
#include "eiface.h"

/* =========================
Forward declarations
========================= */

class CBaseEntity;
class CBasePlayerWeapon;
class CBaseModelEntity;
class CBasePlayerPawn;
class CBasePlayerController;
class CCSPlayerController;
class CEntityInstance;
class CEntityIOOutput;
class CEntitySystem;
class CEntityKeyValues;
class CGameRules;
class CTakeDamageInfo;
class CTakeDamageResult;
class IEntityFindFilter;
class IGameEventListener2;
class IGameEventManager2;

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

* @brief Takes damage from entity..
  */
using CBaseEntity_TakeDamageOld_t = int64_t (FASTCALL*)(CBaseEntity* pThis, CTakeDamageInfo* pInfo,
                                                        CTakeDamageResult* pResult);

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

/**

* @brief Constructs CTakeDamageInfo with valid members.
  */
using CTakeDamageInfo_CTakeDamageInfo_t = void (FASTCALL*)(CTakeDamageInfo* pThis, CBaseEntity* pInflictor,
                                                           CBaseEntity* pAttacker, CBaseEntity* pAbility,
                                                           const Vector* vecDamageForce,
                                                           const Vector* vecDamagePosition, float flDamage,
                                                           int bitsDamageType, int iCustomDamage, void* a10);

/* =========================
Core Toolkit Addresses
========================= */

/**

* @brief Provides access to pre-resolved engine function pointers.
*
* For module inspection, pattern scanning, and pointer arithmetic use
* IToolkitModule and IToolkitMemory instead.
  */
class IToolkitAddresses
{
public:
    virtual ~IToolkitAddresses() = default;

    /* =========================
    Resolved engine functions
    ========================= */

    virtual CBaseEntity_CreateEntityByName_t CBaseEntity_CreateEntityByName() = 0;
    virtual CBaseEntity_DispatchSpawn_t CBaseEntity_DispatchSpawn() = 0;
    virtual CBaseEntity_TakeDamageOld_t CBaseEntity_TakeDamageOld() = 0;
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
    virtual CTakeDamageInfo_CTakeDamageInfo_t CTakeDamageInfo_CTakeDamageInfo() = 0;
};

#endif //_INCLUDE_ITOOLKIT_ADDRESSES_H
