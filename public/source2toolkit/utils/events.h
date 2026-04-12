/**

* @file events.h
* @brief High-level helper functions for game event handling.
*
* These functions provide simplified access to the IToolkitEvents interface,
* allowing plugins to register callbacks for Source2 game events.
*
* @note Internally wraps IToolkitEvents.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/events.h"
#else
#include "source2toolkit/IToolkitEvents.h"
#endif

/**

* @brief Registers a game event listener.
*
* @param pchName Event name (e.g. "player_death", "round_start")
* @param handler Callback executed when the event is fired
* @param mode Execution mode (Pre = before engine processing, Post = after)
*
* @param handler parameters:
* * event: Pointer to game event data
* * mode: Execution mode (Pre/Post)
* * dontBroadcast: Set to true to prevent event from being broadcast to clients
*
* @return Action:
* * Ignore: no changes
* * Override: modify event but still allow original processing (Pre only)
* * Supersede: block original processing (Pre only)
*
* @note Wrapper around IToolkitEvents::RegGameEvent()
*
* @code
* UTIL_RegGameEvent("player_death", [](IGameEvent* event, Mode mode, bool& dontBroadcast) {
      dontBroadcast = true; // hide event from clients
      return Action::Ignore;
* }, Mode::Pre);
* @endcode
  */
void UTIL_RegGameEvent(const char* pchName, GameEventHandler handler, Mode mode);
