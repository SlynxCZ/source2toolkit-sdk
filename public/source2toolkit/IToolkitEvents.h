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

* @file IToolkitEvents.h
* @brief Interface for registering and handling game events.
*
* Provides functionality for hooking into Source2 game events,
* allowing plugins to inspect, modify, or block events.
*
* @note Events correspond to engine-defined events (e.g. "player_death").
  */

#ifndef _INCLUDE_ITOOLKIT_EVENTS_H
#define _INCLUDE_ITOOLKIT_EVENTS_H

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

/**

* @brief Callback type for game events.
*
* @param event Pointer to the event data
* @param mode Execution mode (Pre/Post)
* @param dontBroadcast Set to true to prevent event from being sent to clients
*
* @return Action:
* * Ignore: no changes
* * Override: modify event but still allow original execution (Pre only)
* * Supersede: block original execution (Pre only)
    */
    using GameEventHandler = std::function<Action(IGameEvent* event, Mode mode, bool& dontBroadcast)>;

/* =========================
Core Toolkit Events
========================= */

/**

* @brief Interface for registering game event listeners.
*
* Allows plugins to:
* * Listen to engine events
* * Modify event data
* * Block event propagation
    */
class IToolkitEvents
{
public:
    virtual ~IToolkitEvents() = default;

    /**

    * @brief Registers a listener for a game event.
    *
    * @param owner Plugin ID that owns the listener
    * @param pchName Event name (e.g. "player_death")
    * @param handler Callback function
    * @param mode Execution mode:
    * * Pre: called before engine processes the event
    * * Post: called after engine processes the event
        */
    virtual void RegGameEvent(PluginId owner, const char* pchName, GameEventHandler handler, Mode mode) = 0;
};

#endif //_INCLUDE_ITOOLKIT_EVENTS_H
