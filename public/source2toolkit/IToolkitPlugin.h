//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_PLUGIN_H
#define _INCLUDE_ITOOLKIT_PLUGIN_H

#pragma once

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
   Plugin Interface
   ========================= */

class IToolkitPlugin
{
public:
    virtual ~IToolkitPlugin() = default;

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
   Export system (CreateInterface)
   ========================= */

#define PL_EXPOSURE CreateInterface
#define PL_EXPOSURE_C "CreateInterface"

#if defined(_WIN32)
    #define TOOLKIT_API extern "C" __declspec(dllexport)
#else
    #define TOOLKIT_API extern "C" __attribute__((visibility("default")))
#endif

#define TOOLKIT_INTERFACE_NAME "S2ToolkitPlugin001"

/* =========================
   Plugin exposure
   ========================= */

#define PL_EXPOSURE_FUNC(name, var) \
    TOOLKIT_API void* PL_EXPOSURE(const char* nameStr, int* code) { \
        if (nameStr && std::strcmp(nameStr, TOOLKIT_INTERFACE_NAME) == 0) { \
            if (code) *code = TOOLKIT_IFACE_OK; \
            return static_cast<void*>(&var); \
        } \
        if (code) *code = TOOLKIT_IFACE_FAILED; \
        return nullptr; \
    }

/* =========================
   Globals
   ========================= */

#include "khook.hpp"

#define PLUGIN_EXPOSE(name, var) \
    IToolkitAPI* g_ToolkitAPI = nullptr; \
    IToolkitPlugin* g_PluginAPI = nullptr; \
    PluginId g_PluginID = 0; \
    namespace KHook { IKHook* __exported__khook = nullptr; } \
    PL_EXPOSURE_FUNC(name, var)

/* =========================
   Extern globals
   ========================= */

#define PLUGIN_GLOBALVARS() \
    namespace KHook { extern IKHook* __exported__khook; } \
    extern IToolkitAPI* g_ToolkitAPI; \
    extern IToolkitPlugin* g_PluginAPI; \
    extern PluginId g_PluginID;

/* =========================
   Save vars (init)
   ========================= */

#define PLUGIN_SAVEVARS() \
    g_ToolkitAPI = api; \
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
	v_var = (v_type *)g_ToolkitAPI->QueryInterface(ismm->v_factory(), v_name); \
	if (!v_var) \
	{ \
		if (error && maxlen) \
		{ \
			ismm->Format(error, maxlen, "Could not find interface: %s", v_name); \
		} \
		return false; \
	}

 /**
  * @brief Same as GET_V_IFACE, except searches for any.
  *
  * @param v_factory	Factory method to use from IToolkitApi (such as engineFactory).
  * @param v_var		Variable name to store into.
  * @param v_type		Interface type (do not include the pointer/asterisk).
  * @param v_name		Interface name.
  */
#define GET_IFACE_ANY(v_factory, v_var, v_type, v_name) \
	v_var = (v_type *)g_ToolkitAPI->QueryInterface(ismm->v_factory(), v_name, 0); \
	if (!v_var) \
	{ \
		if (error && maxlen) \
		{ \
			ismm->Format(error, maxlen, "Could not find interface: %s", v_name); \
		} \
		return false; \
	}

#endif //_INCLUDE_ITOOLKIT_PLUGIN_H