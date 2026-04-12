/**

* @file scheduler.h
* @brief High-level helper functions for task scheduling and timers.
*
* These functions provide simplified access to the IToolkitScheduler interface.
*
* Used for:
* * Delayed execution
* * Repeating tasks
* * Frame-based callbacks
*
* @note Internally wraps IToolkitScheduler.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "utils/scheduler.h"
#else
#include "source2toolkit/IToolkitScheduler.h"
#endif

/**

* @brief Executes a task on the next frame.
*
* @param task Callback to execute
*
* @note Useful when you need to defer execution (e.g. after entity spawn)
*
* @code
* UTIL_NextFrame([]() {
      printf("Executed next frame\n");
* });
* @endcode
  */
void UTIL_NextFrame(std::function<void()>&& task);

/**

* @brief Adds a timer.
*
* @param interval Time in seconds between executions
* @param callback Function to execute
* @param flags Timer behavior flags
*
* @return Pointer to created timer
*
* @note Wrapper around IToolkitScheduler::AddTimer()
*
* @code
* UTIL_AddTimer(1.0f, []() {
      printf("Runs every second\n");
* }, TIMER_FLAG_REPEAT);
* @endcode
  */
Timer* UTIL_AddTimer(float interval, TimerCallback callback, int flags = 0);

/**

* @brief Removes (kills) a timer.
*
* @param timer Timer instance
*
* @note Wrapper around IToolkitScheduler::KillTimer()
  */
void UTIL_KillTimer(Timer* timer);
