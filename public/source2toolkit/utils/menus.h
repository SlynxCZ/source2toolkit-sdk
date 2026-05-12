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
* @file menus.h
 * @brief High-level helper functions for menu system.
 *
 * These functions provide simplified access to the IToolkitMenus interface.
 *
 * Used for:
 *  * Opening menus
 *  * Managing active menu instances
 *  * Handling player input
 *
 * @note Internally wraps IToolkitMenus.
 */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/menus.h"
#else
#include "source2toolkit/IToolkitMenus.h"
#endif

/**
 * @brief Opens a CenterHtmlMenu for a player.
 *
 * @param player Target player
 * @param menu Menu to open
 *
 * @note Wrapper around IToolkitMenus::OpenCenterHtmlMenu()
 */
void UTIL_OpenCenterHtmlMenu(CCSPlayerController *player, CenterHtmlMenu *menu);

/**
 * @brief Gets active menu instance for player.
 *
 * @param player Target player
 *
 * @return Pointer to active menu instance or nullptr
 *
 * @note Wrapper around IToolkitMenus::GetActiveMenu()
 */
IMenuInstance *UTIL_GetActiveMenu(CCSPlayerController *player);

/**
 * @brief Closes active menu for player.
 *
 * @param player Target player
 *
 * @note Wrapper around IToolkitMenus::CloseActiveMenu()
 */
void UTIL_CloseActiveMenu(CCSPlayerController *player);

/**
 * @brief Handles key press input.
 *
 * @param player Player who pressed key
 * @param key Pressed key (1-9)
 *
 * @note Wrapper around IToolkitMenus::OnKeyPress()
 */
void UTIL_OnMenuKeyPress(CCSPlayerController *player, int key);