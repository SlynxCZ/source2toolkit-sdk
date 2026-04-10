//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
/**
* =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2026 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
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

CBaseEntity* UTIL_FindPickerEntity(CBasePlayerController* pPlayer, CCSGameRules* pGameRules = nullptr);
CBaseEntity* UTIL_FindEntityByClassname(CEntityInstance* pStart, const char* name);
CBaseEntity* UTIL_FindEntityByName(CEntityInstance* pStartEntity, const char* szName,
                                   CEntityInstance* pSearchingEntity = nullptr, CEntityInstance* pActivator = nullptr,
                                   CEntityInstance* pCaller = nullptr, IEntityFindFilter* pFilter = nullptr);

template <typename T = CBaseEntity>
T* UTIL_CreateEntityByName(const char* pszClassName)
{
#ifdef SOURCE2TOOLKIT_CORE
    return reinterpret_cast<T*>(addresses::toolkitAddresses.CreateEntityByName(pszClassName, -1));
#else
    return reinterpret_cast<T*>(g_ToolkitAPI->EntityIO()->CreateEntityByName(pszClassName));
#endif
}

void UTIL_AcceptInput(CEntityInstance* pTarget, const char* pszInput, CEntityInstance* pActivator,
                      CEntityInstance* pCaller, const char* pszValue = "");

// Add an entity IO event to the event queue, just like a map would
// The queue is processed after all entities are simulated every frame
void UTIL_AddEntityIOEvent(CEntityInstance* pTarget, const char* pszInput,
                           CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr,
                           const char* pszValue = "", float flDelay = 0.0f);

void UTIL_AddEntityIOListener(IEntityIOListener* pListener, const char* pchClassName,
                             const char* pchOutputName, Mode nMode = Mode::Pre);

void UTIL_RemoveEntityIOListener(IEntityIOListener* pListener, const char* pchClassName,
                             const char* pchOutputName, Mode nMode = Mode::Pre);