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

#include "source2toolkit/utils/scheduler.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "utils/scheduler.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitScheduler.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitScheduler* GetScheduler()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &toolkitScheduler;
#else
    return g_ToolkitAPI->Scheduler();
#endif
}

void UTIL_NextFrame(std::function<void()> &&task)
{
    GetScheduler()->NextFrame(std::move(task));
}

Timer* UTIL_AddTimer(float interval, TimerCallback callback, int flags)
{
    return GetScheduler()->AddTimer(interval, callback, flags);
}

void UTIL_KillTimer(Timer* timer)
{
    GetScheduler()->KillTimer(timer);
}