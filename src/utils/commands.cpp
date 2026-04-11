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
#include "source2toolkit/utils/commands.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/commands.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitCommands.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitCommands* GetCommands()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &commands::commandsManager;
#else
    return g_ToolkitAPI->Commands();
#endif
}

static PluginId GetPluginId()
{
#ifdef SOURCE2TOOLKIT_CORE
    return 0;
#else
    return g_PluginID;
#endif
}

void UTIL_RegChatListener(const char* pchName, ChatHandler handler)
{
    GetCommands()->RegChatListener(GetPluginId(), pchName, handler);
}

void UTIL_RegConCommand(const char* pchName, ChatHandler handler)
{
    GetCommands()->RegConCommand(GetPluginId(), pchName, handler);
}

void UTIL_RegConListener(const char* pchName, CommandHandler handler, Mode mode)
{
    GetCommands()->RegConListener(GetPluginId(), pchName, handler, mode);
}