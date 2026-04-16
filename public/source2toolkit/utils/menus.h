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