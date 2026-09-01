/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

/**

* @file IToolkitPaths.h
* @brief Where the toolkit keeps things on disk.
*
* Every path a plugin needs comes from here rather than being spelled out
* against the game directory, so the layout can move without every plugin
* having to be found and edited.
  */

#ifndef _INCLUDE_ITOOLKIT_PATHS_H
#define _INCLUDE_ITOOLKIT_PATHS_H

#pragma once
#include "IToolkitPlugin.h"

/* =========================
Core Toolkit Paths
========================= */

/**

* @brief The toolkit's on-disk layout.
*
* Under the game directory:
*
* @code
* addons/source2toolkit/
*   configs/              core.json, and one directory per plugin
*     <PluginName>/       this plugin's own configs
*   gamedata/             every .json here is read into the game config
*   plugins/              the .stx files themselves
*   shared/               data more than one plugin reads
* @endcode
*
* The returned strings are owned by the toolkit and stay valid for as long as
* it is loaded; copy them if you need to keep one past that.
  */
#define TOOLKIT_PATHS_INTERFACE "IToolkitPaths001"

class IToolkitPaths
{
public:
    virtual ~IToolkitPaths() = default;

    /**

    * @brief The game directory, e.g. ".../game/csgo".
      */
    virtual const char* GameDirectory() = 0;

    /**

    * @brief addons/source2toolkit.
      */
    virtual const char* RootDirectory() = 0;

    /**

    * @brief addons/source2toolkit/configs.
      */
    virtual const char* ConfigsDirectory() = 0;

    /**

    * @brief addons/source2toolkit/gamedata.
      */
    virtual const char* GamedataDirectory() = 0;

    /**

    * @brief addons/source2toolkit/plugins, where the .stx files live.
      */
    virtual const char* PluginsDirectory() = 0;

    /**

    * @brief addons/source2toolkit/shared, for data more than one plugin reads.
      */
    virtual const char* SharedDirectory() = 0;

    /**

    * @brief This plugin's own config directory, configs/<PluginName>.
    *
    * The directory is not created for you; it is where the plugin's files are
    * expected to have been installed.
    *
    * @param owner Plugin ID to look up
    * @return The path, or nullptr when there is no such plugin
      */
    virtual const char* PluginConfigDirectory(PluginId owner) = 0;
};

#define TOOLKIT_GAME_DIR()          g_pToolkitPaths->GameDirectory()
#define TOOLKIT_ROOT_DIR()          g_pToolkitPaths->RootDirectory()
#define TOOLKIT_CONFIGS_DIR()       g_pToolkitPaths->ConfigsDirectory()
#define TOOLKIT_GAMEDATA_DIR()      g_pToolkitPaths->GamedataDirectory()
#define TOOLKIT_PLUGINS_DIR()       g_pToolkitPaths->PluginsDirectory()
#define TOOLKIT_SHARED_DIR()        g_pToolkitPaths->SharedDirectory()

/**
 * @brief This plugin's config directory; the plugin ID is filled in for you.
 */
#define PLUGIN_CONFIG_DIR()         g_pToolkitPaths->PluginConfigDirectory(g_PluginID)

#endif //_INCLUDE_ITOOLKIT_PATHS_H
