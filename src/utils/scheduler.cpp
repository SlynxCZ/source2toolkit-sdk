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