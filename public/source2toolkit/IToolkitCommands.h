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

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

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
