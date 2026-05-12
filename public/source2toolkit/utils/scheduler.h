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
