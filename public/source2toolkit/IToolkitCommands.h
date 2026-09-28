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
#include "IToolkitPlugin.h"
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
* @param post false when called before the original, true after
  */
/**
* @brief Where a command came from, in the toolkit's own layout.
*
* The engine's CCommandContext is what the core sees; what a handler gets is
* this, so the engine type's layout is not part of the plugin API. The two
* methods handlers use are the same as on the engine type.
  */
class ToolkitCommandContext
{
public:
    ToolkitCommandContext(CPlayerSlot slot, int target) : m_slot(slot), m_target(target) {}

    /// The player who issued the command; invalid for the server console.
    CPlayerSlot GetPlayerSlot() const { return m_slot; }

    /// The engine's CommandTarget_t (CT_NO_TARGET, CT_FIRST_SPLITSCREEN_CLIENT, ...).
    int GetCommandTarget() const { return m_target; }

private:
    CPlayerSlot m_slot;
    int m_target;
};

/**
* @brief A command's arguments, in the toolkit's own layout; same accessors
* as the engine's CCommand. The strings belong to the dispatch and are gone
* when the handler returns -- copy what has to outlive it.
  */
class ToolkitCommandArgs
{
public:
    static constexpr int kMaxArgs = 64;

    ToolkitCommandArgs() = default;

    ToolkitCommandArgs(int argc, const char* const* argv, const char* argS, const char* command)
        : m_argc(argc < kMaxArgs ? argc : kMaxArgs), m_argS(argS ? argS : ""), m_command(command ? command : "")
    {
        for (int i = 0; i < m_argc; i++)
            m_argv[i] = argv[i] ? argv[i] : "";
    }

    /// Number of arguments, the command name included.
    int ArgC() const { return m_argc; }

    /// Argument i, the command name at 0; "" past the end.
    const char* Arg(int i) const { return (i >= 0 && i < m_argc) ? m_argv[i] : ""; }

    const char* operator[](int i) const { return Arg(i); }

    /// Everything after the command name, as typed.
    const char* ArgS() const { return m_argS; }

    /// The whole command line, as typed.
    const char* GetCommandString() const { return m_command; }

private:
    int m_argc = 0;
    const char* m_argv[kMaxArgs] = {};
    const char* m_argS = "";
    const char* m_command = "";
};

using ChatHandler = std::function<void(const ToolkitCommandContext&, const ToolkitCommandArgs&, bool post)>;

/**

* @brief Callback for console commands.
*
* @param ctx Command execution context
* @param cmd Parsed command arguments
* @param post false when called before the original, true after
* @return Action describing how to handle execution (Action::Ignore, Action::Override, Action::Supersede)
  */
using CommandHandler = std::function<Action(const ToolkitCommandContext&, const ToolkitCommandArgs&, bool post)>;

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
#define TOOLKIT_COMMANDS_INTERFACE "IToolkitCommands001"

class IToolkitCommands
{
public:
    virtual ~IToolkitCommands() = default;

    /**

    * @brief Registers a chat command listener.
    *
    * @param owner Plugin ID that owns the command
    * @param pchName Command name without a trigger (e.g. "kick", "test")
    * @param handler Callback executed when command is triggered
    *
    * @note Only fires for a chat message that starts with one of the
    *       configured chat triggers (public or silent, "!" and "/" by default),
    *       e.g. "!kick" or "/kick". Plain "kick" typed into chat does not fire
    *       it. The trigger is stripped before matching, so args.Arg(0) is the
    *       bare name. A silent trigger hides the message; a public one lets
    *       it show.
      */
    virtual void RegisterChatListener(PluginId owner, const char* pchName, ChatHandler handler) = 0;

    /**

    * @brief Drops one of this plugin's chat listeners.
      */
    virtual void UnregisterChatListener(PluginId owner, const char* pchName) = 0;

    /**

    * @brief Registers a console command.
    *
    * @param owner Plugin ID that owns the command
    * @param pchName Command name (e.g. "sv_test")
    * @param handler Callback executed when command is used
    *
    * @note This creates a new console command accessible via server/client console.
      */
    virtual void RegisterConCommand(PluginId owner, const char* pchName, ChatHandler handler) = 0;

    /**

    * @brief Removes a console command this plugin created.
      */
    virtual void UnregisterConCommand(PluginId owner, const char* pchName) = 0;

    /**

    * @brief Registers a listener for an existing console command.
    *
    * @param owner Plugin ID that owns the listener
    * @param pchName Existing command name to listen for
    * @param handler Callback executed on command execution
    * @param post false to run before the original, true to run after
    *
    * @return Action to control command execution:
    * * Action::Ignore: do nothing
    * * Action::Override: the original still runs; commands return nothing, so
    *   this has no further effect. Later pre listeners and all post
    *   listeners still fire.
    * * Action::Supersede: block original execution (pre only); the remaining
    *   pre listeners and all post listeners are skipped
        */
    virtual void RegisterConListener(PluginId owner, const char* pchName, CommandHandler handler, bool post) = 0;

    /**

    * @brief Drops one of this plugin's console listeners.
      */
    virtual void UnregisterConListener(PluginId owner, const char* pchName, bool post) = 0;
};

#define REGISTER_CHAT_LISTENER(pchName, handler) \
    g_pToolkitCommands->RegisterChatListener(g_PluginID, pchName, handler)
#define UNREGISTER_CHAT_LISTENER(pchName) \
    g_pToolkitCommands->UnregisterChatListener(g_PluginID, pchName)

#define REGISTER_CON_COMMAND(pchName, handler) \
    g_pToolkitCommands->RegisterConCommand(g_PluginID, pchName, handler)
#define UNREGISTER_CON_COMMAND(pchName) \
    g_pToolkitCommands->UnregisterConCommand(g_PluginID, pchName)

#define REGISTER_CON_LISTENER(pchName, handler, post) \
    g_pToolkitCommands->RegisterConListener(g_PluginID, pchName, handler, post)
#define UNREGISTER_CON_LISTENER(pchName, post) \
    g_pToolkitCommands->UnregisterConListener(g_PluginID, pchName, post)

#endif //_INCLUDE_ITOOLKIT_COMMANDS_H
