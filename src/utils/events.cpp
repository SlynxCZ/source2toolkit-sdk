#include "source2toolkit/utils/events.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/events.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitEvents.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitEvents* GetEvents()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &events::eventManager;
#else
    return g_ToolkitAPI->Events();
#endif
}

static PluginId GetPluginId()
{
#ifdef SOURCE2TOOLKIT_CORE
    return 0;
#else
    return g_PluginID;
#endif
}

void UTIL_RegGameEvent(const char* pchName, GameEventHandler handler, Mode mode)
{
    GetEvents()->RegGameEvent(GetPluginId(), pchName, handler, mode);
}