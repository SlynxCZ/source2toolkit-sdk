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
#include "source2toolkit/schema/entity.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#include "core/addresses.h"
#include "core/inlinehooks.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitEntityIO.h"
#include "source2toolkit/IToolkitPlugin.h"
#endif

#include "source2toolkit/schema/entity/classes/cgamerules.h"
#include "entitysystem.h"
#include "platform.h"
#include "source2toolkit/schema/entity/classes/CBasePlayerWeapon.h"
#include "source2toolkit/utils/virtual.h"

#include "tier0/memdbgon.h"

class CCSGameRules;

CBaseEntity* UTIL_FindPickerEntity(CBasePlayerController* pPlayer, CCSGameRules* pGameRules)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CGameRules_FindPickerEntity");
    return CALL_VIRTUAL(CBaseEntity*, offset, pGameRules ? pGameRules : shared::g_pGameRules, pPlayer, nullptr);
#else
    return g_ToolkitAPI->EntityIO()->FindPickerEntity(pPlayer, pGameRules);
#endif
}

CBaseEntity* UTIL_FindEntityByClassname(CEntityInstance* pStartEntity, const char* szName)
{
#ifdef SOURCE2TOOLKIT_CORE
    return addresses::toolkitAddresses.FindEntityByClassName(shared::g_pEntitySystem, pStartEntity, szName);
#else
    return g_ToolkitAPI->EntityIO()->FindEntityByClassname(pStartEntity, szName);
#endif
}

CBaseEntity* UTIL_FindEntityByName(CEntityInstance* pStartEntity, const char* szName,
                                   CEntityInstance* pSearchingEntity, CEntityInstance* pActivator,
                                   CEntityInstance* pCaller, IEntityFindFilter* pFilter)
{
#ifdef SOURCE2TOOLKIT_CORE
    return addresses::toolkitAddresses.FindEntityByName(shared::g_pEntitySystem, pStartEntity, szName, pSearchingEntity, pActivator, pCaller, pFilter);
#else
    return g_ToolkitAPI->EntityIO()->FindEntityByName(pStartEntity, szName, pSearchingEntity, pActivator, pCaller, pFilter);
#endif
}

void UTIL_AcceptInput(CEntityInstance* pTarget, const char* pszInput, CEntityInstance* pActivator,
                      CEntityInstance* pCaller, const char* pszValue)
{
#ifdef SOURCE2TOOLKIT_CORE
    return addresses::toolkitAddresses.AcceptInput(pTarget, pszInput, pActivator, pCaller, variant_t(pszValue), 0, nullptr);
#else
    return g_ToolkitAPI->EntityIO()->AcceptInput(pTarget, pszInput, pActivator, pCaller, pszValue);
#endif
}

void UTIL_AddEntityIOEvent(CEntityInstance* pTarget, const char* pszInput, CEntityInstance* pActivator,
                           CEntityInstance* pCaller, const char* pszValue, float flDelay)
{
#ifdef SOURCE2TOOLKIT_CORE
    return addresses::toolkitAddresses.AddEntityIOEvent(shared::g_pEntitySystem, pTarget, pszInput, pActivator, pCaller, variant_t(pszValue), flDelay, 0, nullptr, nullptr);
#else
    return g_ToolkitAPI->EntityIO()->AddEntityIOEvent(pTarget, pszInput, pActivator, pCaller, pszValue, flDelay);
#endif
}

void UTIL_AddEntityIOListener(IEntityIOListener* pListener, const char* pchClassName,
                              const char* pchOutputName, Mode nMode)
{
#ifdef SOURCE2TOOLKIT_CORE
    OutputKey key{
        pchClassName ? pchClassName : "*",
        pchOutputName ? pchOutputName : "*"
    };

    if (nMode == Mode::Post)
        inlinehooks::entityIOListenerStack[key].m_vecPost.push_back(pListener);
    else
        inlinehooks::entityIOListenerStack[key].m_vecPre.push_back(pListener);
#else
    g_ToolkitAPI->EntityIO()->AddEntityIOListener(pListener, pchClassName, pchOutputName, nMode);
#endif
}

void UTIL_RemoveEntityIOListener(IEntityIOListener* pListener, const char* pchClassName,
                                 const char* pchOutputName, Mode nMode)
{
#ifdef SOURCE2TOOLKIT_CORE
    if (!pchClassName && !pchOutputName)
    {
        for (auto it = inlinehooks::entityIOListenerStack.begin(); it != inlinehooks::entityIOListenerStack.end(); )
        {
            auto& vec = nMode == Mode::Post ? it->second.m_vecPost : it->second.m_vecPre;

            std::erase(vec, pListener);

            if (it->second.m_vecPre.empty() && it->second.m_vecPost.empty())
                it = inlinehooks::entityIOListenerStack.erase(it);
            else
                ++it;
        }
        return;
    }

    OutputKey key{
        pchClassName ? pchClassName : "*",
        pchOutputName ? pchOutputName : "*"
    };

    auto it = inlinehooks::entityIOListenerStack.find(key);
    if (it == inlinehooks::entityIOListenerStack.end())
        return;

    auto& vec = nMode == Mode::Post ? it->second.m_vecPost : it->second.m_vecPre;

    std::erase(vec, pListener);

    if (it->second.m_vecPre.empty() && it->second.m_vecPost.empty())
        inlinehooks::entityIOListenerStack.erase(it);
#else
    g_ToolkitAPI->EntityIO()->RemoveEntityIOListener(pListener, pchClassName, pchOutputName, nMode);
#endif
}
