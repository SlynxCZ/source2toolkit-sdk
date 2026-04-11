/**

* @file IToolkitAPI.h
* @brief Main entry point for Source2Toolkit API.
*
* This interface provides access to:
* * Core engine interfaces
* * Toolkit subsystems (Commands, Events, ConVars, etc.)
* * Logging and console output
* * Interface querying and factory access
*
* @note This is the primary interface passed to plugins during initialization.
  */

#ifndef _INCLUDE_ITOOLKIT_API_H
#define _INCLUDE_ITOOLKIT_API_H

#pragma once
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
Forward declarations
========================= */

using PluginId = int;

class IGameEventManager2;
class CGlobalVars;
class ICvar;
class ISource2Server;
class IGameEventSystem;
class INetworkMessages;
class INetworkServerService;
class CGameEntitySystem;
class CSchemaSystem;

class IToolkitAddresses;
class IToolkitCommands;
class IToolkitConVars;
class IToolkitGameConfig;
class IToolkitEntityIO;
class IToolkitEvents;
class IToolkitListener;
class IToolkitPlugin;
class IToolkitScheduler;
class IToolkitTrace;

typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);

/* =========================
Core Toolkit API
========================= */

/**

* @brief Main API interface for Source2Toolkit.
*
* Provides access to all toolkit subsystems and engine interfaces.
*
* @code
* api->Commands()->RegConCommand(...);
* api->Events()->RegGameEvent(...);
* @endcode
  */
class IToolkitAPI
{
public:
    virtual ~IToolkitAPI() = default;

    /* =========================
    Logging & console
    ========================= */

    /**

    * @brief Logs a formatted message with plugin context.
    *
    * @param plugin Plugin instance
    * @param msg Format string
      */
    virtual void Log(IToolkitPlugin* plugin, const char* msg, ...) = 0;

    /**

    * @brief Prints message to console.
      */
    virtual void ConPrint(const char* msg) = 0;

    /**

    * @brief Prints formatted message to console.
      */
    virtual void ConPrintf(const char* fmt, ...) = 0;

    /* =========================
    Listeners
    ========================= */

    /**

    * @brief Registers a toolkit listener.
    *
    * @param plugin Owner plugin
    * @param pListener Listener instance
      */
    virtual void AddListener(IToolkitPlugin* plugin, IToolkitListener* pListener) = 0;

    /* =========================
    Interface system
    ========================= */

    /**

    * @brief Queries interface from factory.
    *
    * @param fn Factory function
    * @param iface Interface name
    * @param min Minimum version (optional)
      */
    virtual void* QueryInterface(CreateInterfaceFn fn, const char* iface, int min = -1) = 0;

    /**

    * @brief Searches for interface by iterating versions.
      */
    virtual void* InterfaceSearch(CreateInterfaceFn fn, const char* iface, int max, int* ret) = 0;

    /**

    * @brief Formats interface name with version.
      */
    virtual int FormatIface(char iface[], size_t maxlength) = 0;

    /* =========================
    Engine factories
    ========================= */

    virtual CreateInterfaceFn GetEngineFactory(bool syn = true) = 0;
    virtual CreateInterfaceFn GetPhysicsFactory(bool syn = true) = 0;
    virtual CreateInterfaceFn GetFileSystemFactory(bool syn = true) = 0;
    virtual CreateInterfaceFn GetServerFactory(bool syn = true) = 0;

    /**

    * @brief Toolkit interface factory.
      */
    virtual void* ToolkitFactory(const char* iface, int* ret, PluginId* id) = 0;

    /**

    * @brief Metamod interface factory.
      */
    virtual void* MetaFactory(const char* iface, int* ret, PluginId* id) = 0;

    /* =========================
    Toolkit subsystems
    ========================= */

    /**

    * @brief Access address/pattern system.
      */
    virtual IToolkitAddresses* Addresses() = 0;

    /**

    * @brief Access command system.
      */
    virtual IToolkitCommands* Commands() = 0;

    /**

    * @brief Access ConVar system.
      */
    virtual IToolkitConVars* ConVars() = 0;

    /**

    * @brief Access entity I/O system.
      */
    virtual IToolkitEntityIO* EntityIO() = 0;

    /**

    * @brief Access event system.
      */
    virtual IToolkitEvents* Events() = 0;

    /**

    * @brief Access game configuration system.
      */
    virtual IToolkitGameConfig* GameConfig() = 0;

    /**

    * @brief Access scheduler system.
      */
    virtual IToolkitScheduler* Scheduler() = 0;

    /**

    * @brief Access tracing system.
      */
    virtual IToolkitTrace* Trace() = 0;

    /* =========================
    Engine interfaces
    ========================= */

    virtual IGameEventManager2* GetGameEventManager() = 0;
    virtual CGlobalVars* GetGlobalVars() = 0;
    virtual ICvar* GetCVar() = 0;
    virtual ISource2Server* GetSource2Server() = 0;
    virtual IVEngineServer* GetEngineServer() = 0;
    virtual IGameEventSystem* GetGameEventSystem() = 0;
    virtual INetworkMessages* GetNetworkMessages() = 0;
    virtual INetworkServerService* GetNetworkServerService() = 0;
    virtual CGameEntitySystem* GetEntitySystem() = 0;
    virtual CSchemaSystem* GetSchemaSystem() = 0;

    /**

    * @brief Returns base directory of the server.
      */
    virtual const char* GetBaseDir() = 0;

    /* =========================
    Formatting utilities
    ========================= */

    /**

    * @brief Formats string into buffer.
      */
    virtual size_t Format(char* buffer, size_t maxlength, const char* format, ...) = 0;

    /**

    * @brief Formats string using va_list.
      */
    virtual size_t FormatArgs(char* buffer, size_t maxlength, const char* format, va_list ap) = 0;
};

#endif //_INCLUDE_ITOOLKIT_API_H
