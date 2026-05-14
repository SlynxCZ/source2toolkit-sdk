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

* @file IToolkitCommands.h
* @brief Command and chat handling interface for Source2Toolkit.
*
* Provides functionality for:
* * Registering console commands
* * Listening to console command execution
* * Handling in-game chat messages
*
* @note This system allows plugins to hook into player input via chat or console.
  */

#ifndef _INCLUDE_ITOOLKIT_COMMANDS_H
#define _INCLUDE_ITOOLKIT_COMMANDS_H

#pragma once
#include "IToolkitTypes.h"

#include "convar.h"
#include "eiface.h"

/* =========================
Forward declarations
========================= */

/**

* @brief Callback for chat messages.
*
* @param ctx Command execution context (player, etc.)
* @param cmd Parsed command arguments
* @param mode Execution mode (Pre/Post)
  */
using ChatHandler = std::function<void(const CCommandContext&, const CCommand&, Mode)>;

/**

* @brief Callback for console commands.
*
* @param ctx Command execution context
* @param cmd Parsed command arguments
* @param mode Execution mode (Pre/Post)
* @return Action describing how to handle execution (Ignore, Override, Supersede)
  */
using CommandHandler = std::function<Action(const CCommandContext&, const CCommand&, Mode)>;

/* =========================
Core Toolkit Commands
========================= */

/**

* @brief Interface for registering and handling commands.
*
* Supports:
* * Chat-based commands (player messages)
* * Console commands (server or client)
* * Command listeners with pre/post execution hooks
*
* @note All commands are owned by a plugin via PluginId.
  */
class IToolkitCommands
{
public:
    virtual ~IToolkitCommands() = default;

    /**

    * @brief Registers a chat command listener.
    *
    * @param owner Plugin ID that owns the command
    * @param pchName Command name (e.g. "!kick", "!test")
    * @param handler Callback executed when command is triggered
    *
    * @note Triggered when a player sends a matching chat message.
      */
    virtual void RegChatListener(PluginId owner, const char* pchName, ChatHandler handler) = 0;

    /**

    * @brief Registers a console command.
    *
    * @param owner Plugin ID that owns the command
    * @param pchName Command name (e.g. "sv_test")
    * @param handler Callback executed when command is used
    *
    * @note This creates a new console command accessible via server/client console.
      */
    virtual void RegConCommand(PluginId owner, const char* pchName, ChatHandler handler) = 0;

    /**

    * @brief Registers a listener for an existing console command.
    *
    * @param owner Plugin ID that owns the listener
    * @param pchName Existing command name to listen for
    * @param handler Callback executed on command execution
    * @param mode Execution mode (Pre = before original, Post = after original)
    *
    * @return Action to control command execution:
    * * Ignore: do nothing
    * * Override: override return value but still call original (Pre only)
    * * Supersede: block original execution (Pre only)
        */
    virtual void RegConListener(PluginId owner, const char* pchName, CommandHandler handler, Mode mode) = 0;
};

#endif //_INCLUDE_ITOOLKIT_COMMANDS_H
