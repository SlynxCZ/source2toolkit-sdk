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

* @file IToolkitPlugin.h
* @brief Plugin interface and integration layer for Source2Toolkit.
*
* This file defines:
* * Plugin lifecycle interface (IToolkitPlugin)
* * Listener system (IToolkitListener)
* * Global variables and exposure macros
* * Interface helper macros
*
* @note This is the main entry point for plugin developers.
  */

#ifndef _INCLUDE_ITOOLKIT_PLUGIN_H
#define _INCLUDE_ITOOLKIT_PLUGIN_H

#pragma once
#include "interfaces/interfaces.h"

#include <cstddef>
#include <cstring>
#include <cstdio>

/* =========================
Forward declarations
========================= */

using PluginId = int;
class IToolkitAPI;

namespace KHook
{
    class IKHook;
}

/* =========================
Interface status
========================= */

enum
{
    /// Interface query successful
    TOOLKIT_IFACE_OK = 0,
    /// Interface query failed
    TOOLKIT_IFACE_FAILED
};

/* =========================
Export system
========================= */

/// KHook interface name
#define MMIFACE_KHOOK "IKHook"

/// Plugin interface name
#define TOOLKIT_INTERFACE_NAME "S2ToolkitPlugin001"

/// Plugin API version
#define TOOLKIT_PLAPI_VERSION 1

/// Plugin API interface name
#define TOOLKIT_PLAPI_NAME "IToolkitPlugin"

/* =========================
Plugin Interface
========================= */

/**

* @brief Main plugin interface.
*
* Every plugin must implement this interface.
  */
class IToolkitPlugin
{
public:
    virtual int GetApiVersion()
    {
        return TOOLKIT_PLAPI_VERSION;
    }

    virtual ~IToolkitPlugin() = default;

public:
    /**
    * @brief Called when plugin is loaded.
    *
    * @param id Plugin identifier
    * @param api Toolkit API instance
    * @param error Buffer for error message
    * @param maxlen Error buffer size
    * @param late True if loaded after server start
    *
    * @return True on success, false on failure
    *
    * @note This is the main initialization function.
    */
    virtual bool Load(PluginId id, IToolkitAPI* api, char* error, size_t maxlen, bool late) = 0;

    /**
     * @brief Called when plugin is unloaded.
     *
     * @return True on success
     */
    virtual bool Unload(char* error, size_t maxlen)
    {
        return true;
    }

public:
    /// Plugin author name
    virtual const char* GetAuthor() = 0;

    /// Plugin name
    virtual const char* GetName() = 0;

    /// Plugin description
    virtual const char* GetDescription() = 0;

    /// Plugin version
    virtual const char* GetVersion() = 0;
};

/* =========================
Listener Interface
========================= */

/**

* @brief Listener for toolkit and engine events.
*
* Allows plugins to react to lifecycle and map events.
  */
class IToolkitListener
{
public:
    virtual ~IToolkitListener() = default;

    /// Called when a plugin is loaded
    virtual void OnPluginLoad(PluginId id)
    {
    }

    /// Called when a plugin is unloaded
    virtual void OnPluginUnload(PluginId id)
    {
    }

    /// Called when all toolkit plugins are loaded
    virtual void OnAllToolkitPluginsLoaded()
    {
    }

    /// Called when all Metamod plugins are loaded
    virtual void OnAllMetamodPluginsLoaded()
    {
    }

    /**

    * @brief Called when a map is initialized.
      */
    virtual void OnLevelInit(const char* mapName,
                             const char* mapEntities,
                             const char* oldLevel,
                             const char* landmarkName,
                             bool loadGame,
                             bool background)
    {
    }

    /// Called when a map is shutting down
    virtual void OnLevelShutdown()
    {
    }

    /**

    * @brief Called when an interface is requested from toolkit.
    *
    * @return Pointer to interface or nullptr
      */
    virtual void* OnToolkitQuery(const char* iface, int* ret)
    {
        if (ret)
        {
            *ret = TOOLKIT_IFACE_FAILED;
        }

        return nullptr;
    }
};

/* =========================
Plugin exposure
========================= */

/**

* @brief Exposes plugin interface to engine.
  */
#define TOOLKIT_EXPOSURE_FUNC(name, var)	EXPOSE_SINGLE_INTERFACE_GLOBALVAR(IToolkitPlugin, IToolkitPlugin, TOOLKIT_PLAPI_NAME, var);

/* =========================
Globals
========================= */

#include "khook.hpp"

/**

* @brief Defines global plugin variables.
*
* Creates:
* * g_ToolkitAPI
* * g_PluginAPI
* * g_PluginID
* * KHook interface
    */
#define TOOLKIT_EXPOSE(name, var) \
    IToolkitAPI* g_ToolkitAPI = nullptr; \
    IToolkitPlugin* g_PluginAPI = nullptr; \
    PluginId g_PluginID = 0; \
    namespace KHook { IKHook* __exported__khook = nullptr; } \
    TOOLKIT_EXPOSURE_FUNC(name, var)

/**

* @brief Declares external globals.
  */
#define TOOLKIT_GLOBALVARS() \
    namespace KHook { extern IKHook* __exported__khook; } \
    extern IToolkitAPI* g_ToolkitAPI; \
    extern IToolkitPlugin* g_PluginAPI; \
    extern PluginId g_PluginID;

/**

* @brief Initializes global variables inside Load().
*
* @note Must be called in plugin Load().
  */
#define TOOLKIT_SAVEVARS() \
    g_ToolkitAPI = api; \
    KHook::__exported__khook = static_cast<KHook::IKHook*>(api->MetaFactory(MMIFACE_KHOOK, nullptr, nullptr)); \
    g_PluginAPI = static_cast<IToolkitPlugin*>(this); \
    g_PluginID = id;

/* =========================
Logging helpers
========================= */

/// Shortcut for logging
#define TOOLKIT_LOG        g_ToolkitAPI->Log

/// Console print
#define TOOLKIT_CONPRINT   g_ToolkitAPI->ConPrint

/// Console printf
#define TOOLKIT_CONPRINTF  g_ToolkitAPI->ConPrintf

/* =========================
Interface helpers
========================= */

/**
 * @brief Macro for automatically getting a current or newer Valve interface.
 *
 * @param v_factory		Factory method to use from IToolkitApi (such as engineFactory).
 * @param v_var			Variable name to store into.
 * @param v_type		Interface type (do not include the pointer/asterisk).
 * @param v_name		Interface name.
 */
#define GET_IFACE_CURRENT(v_factory, v_var, v_type, v_name) \
	v_var = (v_type *)g_ToolkitAPI->QueryInterface(g_ToolkitAPI->v_factory(), v_name); \
	if (!v_var) \
	{ \
		if (error && maxlen) \
		{ \
			g_ToolkitAPI->Format(error, maxlen, "Could not find interface: %s", v_name); \
		} \
		return false; \
	}

/**
 * @brief Same as GET_IFACE, except searches for any.
 *
 * @param v_factory	Factory method to use from IToolkitApi (such as engineFactory).
 * @param v_var		Variable name to store into.
 * @param v_type		Interface type (do not include the pointer/asterisk).
 * @param v_name		Interface name.
 */
#define GET_IFACE_ANY(v_factory, v_var, v_type, v_name) \
	v_var = (v_type *)g_ToolkitAPI->QueryInterface(g_ToolkitAPI->v_factory(), v_name, 0); \
	if (!v_var) \
	{ \
		if (error && maxlen) \
		{ \
			g_ToolkitAPI->Format(error, maxlen, "Could not find interface: %s", v_name); \
		} \
		return false; \
	}

/**
 * @brief Macro for automatically getting a Source2Toolkit plugin exposed interface.
 *
 * @param v_var		Variable name to store into.
 * @param v_type		Interface type (do not include the pointer/asterisk).
 * @param v_name		Interface name.
 */
#define GET_IFACE_TOOLKIT(v_var, v_type, v_name) \
    v_var = (v_type*)g_ToolkitAPI->ToolkitFactory(v_name, nullptr, nullptr); \
    if (!v_var) \
    { \
        if (error && maxlen) \
        { \
            g_ToolkitAPI->Format(error, maxlen, "Could not find toolkit interface: %s", v_name); \
        } \
        return false; \
    }

#endif //_INCLUDE_ITOOLKIT_PLUGIN_H
