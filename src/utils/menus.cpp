#include "source2toolkit/utils/menus.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/menus.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitMenus.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

/**
 * @brief Retrieves toolkit menus interface.
 */
static IToolkitMenus* GetMenus()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &menus::menuManager;
#else
    return g_ToolkitAPI->Menus();
#endif
}

void UTIL_OpenCenterHtmlMenu(CCSPlayerController *player, CenterHtmlMenu *menu)
{
    GetMenus()->OpenCenterHtmlMenu(player, menu);
}

IMenuInstance *UTIL_GetActiveMenu(CCSPlayerController *player)
{
    return GetMenus()->GetActiveMenu(player);
}

void UTIL_CloseActiveMenu(CCSPlayerController *player)
{
    GetMenus()->CloseActiveMenu(player);
}

void UTIL_OnMenuKeyPress(CCSPlayerController *player, int key)
{
    GetMenus()->OnKeyPress(player, key);
}