#include "source2toolkit/utils/commands.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/commands.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitCommands.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitCommands* GetCommands()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &commands::commandsManager;
#else
    return g_ToolkitAPI->Commands();
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

void UTIL_RegChatListener(const char* pchName, ChatHandler handler)
{
    GetCommands()->RegChatListener(GetPluginId(), pchName, handler);
}

void UTIL_RegConCommand(const char* pchName, ChatHandler handler)
{
    GetCommands()->RegConCommand(GetPluginId(), pchName, handler);
}

void UTIL_RegConListener(const char* pchName, CommandHandler handler, Mode mode)
{
    GetCommands()->RegConListener(GetPluginId(), pchName, handler, mode);
}