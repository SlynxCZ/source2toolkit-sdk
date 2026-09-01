//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: IBaseMenu bits that cannot live in the header -- they reach for
//          IToolkitMenus and CCSPlayerController, both of which are only
//          declared by the time the class body is parsed.
//
//=============================================================================//
#include "source2toolkit/IToolkitMenus.h"

#include "source2toolkit/schema/entity/classes/CCSPlayerController.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/menus.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
TOOLKIT_GLOBALVARS();
#endif

std::function<bool(CCSPlayerController*)> IBaseMenu::s_canSelect =
    [](CCSPlayerController*) { return true; };

std::function<void(CCSPlayerController*)> IBaseMenu::s_onSelect =
    [](CCSPlayerController*) {};

ChatMenuOption& IBaseMenu::AddMenuOptionWithCooldown(
    std::string optionText,
    std::function<void(CCSPlayerController*, ChatMenuOption&)> action,
    bool disabled,
    bool close,
    std::function<bool()> disabledEvaluator)
{
    ChatMenuOption& opt = AddMenuOption(
        std::move(optionText),
        [action = std::move(action), close](CCSPlayerController* player, ChatMenuOption& optRef)
        {
            if (s_canSelect && !s_canSelect(player))
                return;

            action(player, optRef);

            if (s_onSelect)
                s_onSelect(player);

            if (close)
            {
#ifdef SOURCE2TOOLKIT_CORE
                menus::menuManager.CloseActiveMenu(player);
#else
                if (g_ToolkitAPI && g_ToolkitAPI->Menus())
                    g_ToolkitAPI->Menus()->CloseActiveMenu(player);
#endif

                if (player)
                    player->PrintToCenterHtml(optRef.Text.c_str(), 5, true);
            }
        },
        disabled);

    opt.DisabledEvaluator = std::move(disabledEvaluator);
    return opt;
}
