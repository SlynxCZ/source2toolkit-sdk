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

* @file IToolkitScheduler.h
* @brief Interface for scheduling tasks and managing timers.
*
* Provides functionality for:
* * Scheduling callbacks for next frame
* * Creating repeating or delayed timers
* * Managing timer lifecycle
    */

#ifndef _INCLUDE_ITOOLKIT_SCHEDULER_H
#define _INCLUDE_ITOOLKIT_SCHEDULER_H

#pragma once
#include "IToolkitTypes.h"

#include "eiface.h"

/* =========================
Callback types
========================= */

/// Callback executed by timers
using TimerCallback = std::function<void()>;

/* =========================
Timer flags
========================= */

/**

* @brief Timer behavior flags.
  */
enum TimerFlags
{
    /// Repeats timer indefinitely
    TIMER_FLAG_REPEAT = 1 << 0,

    /// Automatically stops timer on map change
    TIMER_FLAG_NO_MAPCHANGE = 1 << 1,
};

/* =========================
Timer object
========================= */

/**

* @brief Represents a scheduled timer.
*
* Contains execution data and state for scheduled callbacks.
  */
class Timer
{
public:
    /**

    * @brief Constructs a timer.
      */
    Timer(float interval, double execTime, TimerCallback callback, int flags)
        : Interval(interval), ExecTime(execTime), Callback(std::move(callback)), Flags(flags)
    {
    }

    ~Timer() = default;

    /// Interval between executions (seconds)
    float Interval;

    /// Next execution time (engine time)
    double ExecTime;

    /// Callback function
    TimerCallback Callback;

    /// Timer flags (TimerFlags)
    int Flags;

    /// True while callback is executing
    bool InExec = false;

    /// Marks timer for deletion
    bool KillMe = false;
};

/* =========================
Core Toolkit Scheduler
========================= */

/**

* @brief Interface for scheduling tasks and timers.
  */
class IToolkitScheduler
{
public:
    virtual ~IToolkitScheduler() = default;

    /**

    * @brief Executes a task on the next frame.
    *
    * @param task Callback function
    *
    * @note Runs once on the next game frame
      */
    virtual void NextFrame(std::function<void()>&& task) = 0;

    /**

    * @brief Adds a timer.
    *
    * @param interval Time in seconds between executions
    * @param callback Function to execute
    * @param flags Timer behavior flags
    *
    * @return Pointer to created Timer
      */
    virtual Timer* AddTimer(float interval, TimerCallback callback, int flags = 0) = 0;

    /**

    * @brief Removes a timer.
    *
    * @param timer Timer instance
      */
    virtual void KillTimer(Timer* timer) = 0;
};

#endif //_INCLUDE_ITOOLKIT_SCHEDULER_H
