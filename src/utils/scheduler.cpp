//
// Created by Michal Přikryl on 11.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
/**
 * =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2026 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "source2toolkit/utils/scheduler.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "utils/scheduler.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitScheduler.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

void UTIL_NextFrame(std::function<void()> &&task)
{
#ifdef SOURCE2TOOLKIT_CORE
    toolkitScheduler.NextFrame(std::move(task));
#else
    g_ToolkitAPI->Scheduler()->NextFrame(std::move(task));
#endif
}

Timer* UTIL_AddTimer(float interval, TimerCallback callback, int flags)
{
#ifdef SOURCE2TOOLKIT_CORE
    return toolkitScheduler.AddTimer(interval, callback, flags);
#else
    return g_ToolkitAPI->Scheduler()->AddTimer(interval, callback, flags);
#endif
}

void UTIL_KillTimer(Timer* timer)
{
#ifdef SOURCE2TOOLKIT_CORE
    toolkitScheduler.KillTimer(timer);
#else
    g_ToolkitAPI->Scheduler()->KillTimer(timer);
#endif
}