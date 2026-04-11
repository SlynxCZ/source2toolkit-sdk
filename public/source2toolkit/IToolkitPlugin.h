//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

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
    TOOLKIT_IFACE_OK = 0,
    TOOLKIT_IFACE_FAILED
};

/* =========================
   Export system (CreateInterface)
   ========================= */

#define MMIFACE_KHOOK "IKHook"
#define TOOLKIT_INTERFACE_NAME "S2ToolkitPlugin001"
#define TOOLKIT_PLAPI_VERSION 1
#define TOOLKIT_PLAPI_NAME "IToolkitPlugin"

/* =========================
   Plugin Interface
   ========================= */

class IToolkitPlugin
{
public:
    virtual int GetApiVersion()
    {
        return TOOLKIT_PLAPI_VERSION;
    }

    virtual ~IToolkitPlugin() = default;

public:
    virtual bool Load(PluginId id, IToolkitAPI* api, char* error, size_t maxlen, bool late) = 0;

    virtual bool Unload(char* error, size_t maxlen)
    {
        return true;
    }

public:
    virtual const char* GetAuthor() = 0;
    virtual const char* GetName() = 0;
    virtual const char* GetDescription() = 0;
    virtual const char* GetVersion() = 0;
};

/* =========================
   Listener Interface
   ========================= */

class IToolkitListener
{
public:
    virtual ~IToolkitListener() = default;

    virtual void OnPluginLoad(PluginId id) {}
    virtual void OnPluginUnload(PluginId id) {}

    virtual void OnAllToolkitPluginsLoaded() {}
    virtual void OnAllMetamodPluginsLoaded() {}

    virtual void OnLevelInit(const char* mapName,
                             const char* mapEntities,
                             const char* oldLevel,
                             const char* landmarkName,
                             bool loadGame,
                             bool background)
    {
    }

    virtual void OnLevelShutdown() {}

    virtual void *OnToolkitQuery(const char *iface, int *ret)
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

#define PL_EXPOSURE_FUNC(name, var)	EXPOSE_SINGLE_INTERFACE_GLOBALVAR(IToolkitPlugin, IToolkitPlugin, TOOLKIT_PLAPI_NAME, var);

/* =========================
   Globals
   ========================= */
#include "khook.hpp"

#define TOOLKIT_EXPOSE(name, var) \
    IToolkitAPI* g_ToolkitAPI = nullptr; \
    IToolkitPlugin* g_PluginAPI = nullptr; \
    PluginId g_PluginID = 0; \
    namespace KHook { IKHook* __exported__khook = nullptr; } \
    PL_EXPOSURE_FUNC(name, var)

/* =========================
   Extern globals
   ========================= */

#define TOOLKIT_GLOBALVARS() \
    namespace KHook { extern IKHook* __exported__khook; } \
    extern IToolkitAPI* g_ToolkitAPI; \
    extern IToolkitPlugin* g_PluginAPI; \
    extern PluginId g_PluginID;

/* =========================
   Save vars (init)
   ========================= */

#define TOOLKIT_SAVEVARS() \
    g_ToolkitAPI = api; \
    KHook::__exported__khook = static_cast<KHook::IKHook*>(api->MetaFactory(MMIFACE_KHOOK, nullptr, nullptr)) \
    g_PluginAPI = static_cast<IToolkitPlugin*>(this); \
    g_PluginID = id;

/* =========================
   Logging helpers
   ========================= */

#define TOOLKIT_LOG        g_ToolkitAPI->Log
#define TOOLKIT_CONPRINT   g_ToolkitAPI->ConPrint
#define TOOLKIT_CONPRINTF  g_ToolkitAPI->ConPrintf

/* =========================
   Interface getter
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
 * @brief Get interface from Source2Toolkit (plugin system).
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
