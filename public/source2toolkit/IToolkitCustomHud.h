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

* @file IToolkitCustomHud.h
* @brief Interface for the panorama custom HUD layouts.
*
* `custom_hud_layout` entities render a panorama layout on top of the game HUD.
* The entity itself is driven through CCSCustomHudLayout; this interface only
* owns the click callbacks, because the button press arrives as a user message
* on the core's own hook and has to be routed back to whichever plugin created
* the layout.
*
* @note Plugins do not normally touch this interface -- CCSCustomHudLayout's
*       HookClick() forwards here for them.
  */

#ifndef _INCLUDE_ITOOLKIT_CUSTOMHUD_H
#define _INCLUDE_ITOOLKIT_CUSTOMHUD_H

#pragma once
#include "IToolkitPlugin.h"

/* =========================
Forward declarations
========================= */

class CCSCustomHudLayout;
class CCSPlayerController;

/**

* @brief Callback type for custom HUD button clicks.
*
* @param player Player who clicked
* @param pLayout Layout the button lives on
* @param pszButtonId `id` attribute of the clicked panel
  */
using CustomHudClickHandler = std::function<void(CCSPlayerController* player, CCSCustomHudLayout* pLayout, const char* pszButtonId)>;

/* =========================
Core Toolkit Custom HUD
========================= */

/**

* @brief Registry of custom HUD click callbacks.
*
* Callbacks are keyed by layout entity, so several plugins may listen on their
* own layouts at once. Every callback a plugin registers is dropped when that
* plugin unloads, and the whole registry is cleared on level shutdown along
* with the entities it points at.
  */
#define TOOLKIT_CUSTOMHUD_INTERFACE "IToolkitCustomHud001"

class IToolkitCustomHud
{
public:
    virtual ~IToolkitCustomHud() = default;

    /**

    * @brief Registers a click callback for one layout entity.
    *
    * @param owner Plugin ID that owns the callback
    * @param pLayout Layout to listen on
    * @param handler Callback function
      */
    virtual void HookCustomHudClick(PluginId owner, CCSCustomHudLayout* pLayout, CustomHudClickHandler handler) = 0;

    /**

    * @brief Drops every callback registered for a layout.
    *
    * @param pLayout Layout to stop listening on
      */
    virtual void UnhookCustomHudClick(CCSCustomHudLayout* pLayout) = 0;
};

/**
 * @brief Hook macros, matching HOOK_GAME_EVENT: the plugin ID is filled in.
 */
#define HOOK_CUSTOM_HUD_CLICK(pLayout, handler) \
    g_pToolkitCustomHud->HookCustomHudClick(g_PluginID, pLayout, handler)

#define UNHOOK_CUSTOM_HUD_CLICK(pLayout) \
    g_pToolkitCustomHud->UnhookCustomHudClick(pLayout)

#endif //_INCLUDE_ITOOLKIT_CUSTOMHUD_H
