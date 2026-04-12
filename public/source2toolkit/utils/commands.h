/**

* @file commands.h
* @brief High-level helper functions for command and chat registration.
*
* These functions provide simplified access to the IToolkitCommands interface,
* removing the need to manually pass PluginId or access the API instance.
*
* @note Internally uses IToolkitCommands from the global toolkit API.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/commands.h"
#else
#include "source2toolkit/IToolkitCommands.h"
#endif

/**

* @brief Registers a chat command listener.
*
* @param pchName Command name (e.g. "!hello", "!kick")
* @param handler Callback executed when the chat command is triggered
*
* @note This is a helper wrapper around IToolkitCommands::RegChatListener().
* @note The current plugin is automatically used as the owner.
*
* @code
* UTIL_RegChatListener("!hello", [](auto& ctx, auto& cmd, auto mode) {
      printf("Hello from chat\n");
* });
* @endcode
  */
void UTIL_RegChatListener(const char* pchName, ChatHandler handler);

/**

* @brief Registers a console command.
*
* @param pchName Command name (e.g. "sv_test")
* @param handler Callback executed when the command is used
*
* @note This creates a new console command accessible via the server or client console.
* @note Wrapper around IToolkitCommands::RegConCommand().
*
* @code
* UTIL_RegConCommand("sv_test", [](auto& ctx, auto& cmd, auto mode) {
      printf("Command executed\n");
* });
* @endcode
  */
void UTIL_RegConCommand(const char* pchName, ChatHandler handler);

/**

* @brief Registers a listener for an existing console command.
*
* @param pchName Command name to listen for
* @param handler Callback executed when the command runs
* @param mode Execution mode (Pre = before original, Post = after original)
*
* @note Wrapper around IToolkitCommands::RegConListener().
*
* @return Action to control execution:
* * Ignore: do nothing
* * Override: override return value (Pre only)
* * Supersede: block original execution (Pre only)
*
* @code
* UTIL_RegConListener("sv_cheats", [](auto& ctx, auto& cmd, auto mode) {
      return Action::Supersede;
* }, Mode::Pre);
* @endcode
  */
void UTIL_RegConListener(const char* pchName, CommandHandler handler, Mode mode);
