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

* @file IToolkitEntityIO.h
* @brief Interface for entity lookup and Source2 Entity I/O system.
*
* Provides:
* * Entity searching (classname, name, picker)
* * Entity creation
* * Input triggering
* * Output listening
*
* @note Entity I/O is the system used by maps to connect entities together.
  */

#ifndef _INCLUDE_ITOOLKIT_ENTITYIO_H
#define _INCLUDE_ITOOLKIT_ENTITYIO_H

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
class CBaseEntity;
class CBasePlayerController;
class CCSGameRules;
class IEntityFindFilter;
class IEntityIOListener;

/**

* @brief Interface for interacting with entities and Entity I/O system.
  */
class IToolkitEntityIO
{
public:
    virtual ~IToolkitEntityIO() = default;

    /**

    * @brief Finds entity under player's crosshair.
      */
    virtual CBaseEntity* FindPickerEntity(CBasePlayerController* pPlayer,
                                          CCSGameRules* pGameRules = nullptr) = 0;

    /**

    * @brief Finds entity by classname.
      */
    virtual CBaseEntity* FindEntityByClassname(CEntityInstance* pStart,
                                               const char* name) = 0;

    /**

    * @brief Finds entity by name.
      */
    virtual CBaseEntity* FindEntityByName(CEntityInstance* pStartEntity,
                                          const char* szName,
                                          CEntityInstance* pSearchingEntity = nullptr,
                                          CEntityInstance* pActivator = nullptr,
                                          CEntityInstance* pCaller = nullptr,
                                          IEntityFindFilter* pFilter = nullptr) = 0;

    /**

    * @brief Creates entity by classname.
      */
    virtual CBaseEntity* CreateEntityByName(const char* pszClassName) = 0;

    /**

    * @brief Sends input to entity.
    *
    * @note Equivalent to Source engine AcceptInput()
      */
    virtual void AcceptInput(CEntityInstance* pTarget,
                             const char* pszInput,
                             CEntityInstance* pActivator,
                             CEntityInstance* pCaller,
                             const char* pszValue = "") = 0;

    /**

    * @brief Queues an entity I/O event.
      */
    virtual void AddEntityIOEvent(CEntityInstance* pTarget,
                                  const char* pszInput,
                                  CEntityInstance* pActivator = nullptr,
                                  CEntityInstance* pCaller = nullptr,
                                  const char* pszValue = "",
                                  float flDelay = 0.0f) = 0;

    /**

    * @brief Adds listener for entity outputs.
      */
    virtual void AddEntityIOListener(IEntityIOListener* pListener,
                                     const char* pchClassName,
                                     const char* pchOutputName,
                                     Mode nMode = Mode::Pre) = 0;

    /**

    * @brief Removes entity output listener.
      */
    virtual void RemoveEntityIOListener(IEntityIOListener* pListener,
                                        const char* pchClassName,
                                        const char* pchOutputName,
                                        Mode nMode = Mode::Pre) = 0;
};

#endif //_INCLUDE_ITOOLKIT_ENTITYIO_H
