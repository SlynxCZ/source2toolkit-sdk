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
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

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
