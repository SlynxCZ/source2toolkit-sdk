//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

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
class IGameEventManager2;
class IToolkitAPI;
class IToolkitScheduler;
class IToolkitTrace;
class IToolkitGameConfig;
class IToolkitEntityIO;
class IToolkitEvents;
class IToolkitCommands;
class IToolkitAddresses;
class IToolkitListener;
class IToolkitPlugin;

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

/* =========================
   Core Toolkit API
   ========================= */

class IToolkitAPI
{
public:
    virtual ~IToolkitAPI() = default;

    virtual void Log(IToolkitPlugin *plugin, const char* msg, ...) = 0;
    virtual void ConPrint(const char* msg) = 0;
    virtual void ConPrintf(const char* fmt, ...) = 0;

    virtual void AddListener(IToolkitPlugin *plugin, IToolkitListener *pListener) = 0;

    virtual void* QueryInterface(CreateInterfaceFn fn, const char *iface, int min=-1) = 0;
    virtual void* InterfaceSearch(CreateInterfaceFn fn, const char *iface, int max, int *ret) = 0;
    virtual int FormatIface(char iface[], size_t maxlength) = 0;

    virtual CreateInterfaceFn GetEngineFactory(bool syn=true) = 0;
    virtual CreateInterfaceFn GetPhysicsFactory(bool syn=true) = 0;
    virtual CreateInterfaceFn GetFileSystemFactory(bool syn=true) = 0;
    virtual CreateInterfaceFn GetServerFactory(bool syn=true) = 0;

    virtual void* ToolkitFactory(const char *iface, int *ret, PluginId *id) = 0;
    virtual void* MetaFactory(const char *iface, int *ret, PluginId *id) = 0;

    virtual IToolkitAddresses* Addresses() = 0;
    virtual IToolkitCommands* Commands() = 0;
    virtual IToolkitEntityIO* EntityIO() = 0;
    virtual IToolkitEvents* Events() = 0;
    virtual IToolkitGameConfig* GameConfig() = 0;
    virtual IToolkitScheduler* Scheduler() = 0;
    virtual IToolkitTrace* Trace() = 0;

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
    virtual const char* GetBaseDir() = 0;

    virtual size_t Format(char *buffer, size_t maxlength, const char *format, ...) = 0;
    virtual size_t FormatArgs(char *buffer, size_t maxlength, const char *format, va_list ap) = 0;
};

#endif //_INCLUDE_ITOOLKIT_API_H
