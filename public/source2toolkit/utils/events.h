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

* @file events.h
* @brief High-level helper functions for game event handling.
*
* These functions provide simplified access to the IToolkitEvents interface,
* allowing plugins to register callbacks for Source2 game events.
*
* @note Internally wraps IToolkitEvents.
*/

#ifndef _INCLUDE_ITOOLKIT_UTILS_EVENTS_H
#define _INCLUDE_ITOOLKIT_UTILS_EVENTS_H

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

#endif //_INCLUDE_ITOOLKIT_UTILS_EVENTS_H

