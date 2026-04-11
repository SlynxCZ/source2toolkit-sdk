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
