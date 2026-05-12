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

* @file entityio.h
* @brief High-level helper functions for entity lookup and Entity I/O system.
*
* These functions provide simplified access to the IToolkitEntityIO interface.
*
* Supports:
* * Finding entities (by classname, name, picker)
* * Creating entities
* * Triggering entity inputs
* * Scheduling entity I/O events
* * Listening to entity outputs
*
* @note Internally wraps IToolkitEntityIO.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitEntityIO.h"
#include "source2toolkit/IToolkitPlugin.h"
#endif

#include "datamap.h"
#include "platform.h"
#include "string_t.h"
#include "variant.h"

class CEntityInstance;
class CBaseEntity;
class CBasePlayerController;
class CCSGameRules;
class IEntityFindFilter;
class IEntityIOListener;

/**

* @brief Finds the entity currently targeted by a player's crosshair.
*
* @param pPlayer Player controller
* @param pGameRules Optional game rules
* @return Pointer to entity, or nullptr if none found
*
* @note Wrapper around IToolkitEntityIO::FindPickerEntity()
  */
CBaseEntity* UTIL_FindPickerEntity(CBasePlayerController* pPlayer, CCSGameRules* pGameRules = nullptr);

/**

* @brief Finds an entity by classname.
*
* @param pStart Starting entity (or nullptr for first)
* @param name Classname (e.g. "weapon_ak47")
* @return Found entity or nullptr
*
* @note Can be used in loops to iterate entities
  */
CBaseEntity* UTIL_FindEntityByClassname(CEntityInstance* pStart, const char* name);

/**

* @brief Finds an entity by target name.
*
* @param pStartEntity Starting entity
* @param szName Target name
* @param pSearchingEntity Optional searching entity
* @param pActivator Optional activator
* @param pCaller Optional caller
* @param pFilter Optional filter
*
* @return Found entity or nullptr
  */
CBaseEntity* UTIL_FindEntityByName(CEntityInstance* pStartEntity, const char* szName,
                                   CEntityInstance* pSearchingEntity = nullptr,
                                   CEntityInstance* pActivator = nullptr,
                                   CEntityInstance* pCaller = nullptr,
                                   IEntityFindFilter* pFilter = nullptr);

/**

* @brief Creates a new entity by classname.
*
* @tparam T Desired entity type
* @param pszClassName Classname
* @return Pointer to created entity
*
* @note Wrapper around IToolkitEntityIO::CreateEntityByName()
*
* @code
* auto weapon = UTIL_CreateEntityByName<CBaseEntity>("weapon_ak47");
* @endcode
  */
template <typename T = CBaseEntity>
T* UTIL_CreateEntityByName(const char* pszClassName)
{
#ifdef SOURCE2TOOLKIT_CORE
    return reinterpret_cast<T*>(addresses::toolkitAddresses.CreateEntityByName(pszClassName, -1));
#else
    return reinterpret_cast<T*>(g_ToolkitAPI->EntityIO()->CreateEntityByName(pszClassName));
#endif
}

/**

* @brief Sends an input to an entity.
*
* @param pTarget Target entity
* @param pszInput Input name (e.g. "Kill", "Enable", "Disable")
* @param pActivator Activator entity
* @param pCaller Caller entity
* @param pszValue Optional value
*
* @note Equivalent to Source engine "AcceptInput"
  */
void UTIL_AcceptInput(CEntityInstance* pTarget, const char* pszInput,
                      CEntityInstance* pActivator, CEntityInstance* pCaller,
                      const char* pszValue = "");

/**

* @brief Adds an Entity I/O event to the engine queue.
*
* @param pTarget Target entity
* @param pszInput Input name
* @param pActivator Activator entity
* @param pCaller Caller entity
* @param pszValue Optional value
* @param flDelay Delay in seconds
*
* @note Events are processed after entity simulation each frame.
* @note Equivalent to map-defined outputs.
  */
void UTIL_AddEntityIOEvent(CEntityInstance* pTarget, const char* pszInput,
                           CEntityInstance* pActivator = nullptr,
                           CEntityInstance* pCaller = nullptr,
                           const char* pszValue = "",
                           float flDelay = 0.0f);

/**

* @brief Registers a listener for entity outputs.
*
* @param pListener Listener instance
* @param pchClassName Entity classname
* @param pchOutputName Output name (e.g. "OnUser1")
* @param nMode Execution mode (Pre/Post)
*
* @note Allows intercepting entity outputs.
  */
void UTIL_AddEntityIOListener(IEntityIOListener* pListener,
                              const char* pchClassName,
                              const char* pchOutputName,
                              Mode nMode = Mode::Pre);

/**

* @brief Removes an entity output listener.
  */
void UTIL_RemoveEntityIOListener(IEntityIOListener* pListener,
                                 const char* pchClassName,
                                 const char* pchOutputName,
                                 Mode nMode = Mode::Pre);
