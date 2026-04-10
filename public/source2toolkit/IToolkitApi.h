//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_API_H
#define _INCLUDE_ITOOLKIT_API_H

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Forward declarations
   ========================= */

using PluginId = int;
class IToolkitAPI;
class CGlobalVars;
class IToolkitListener;
class IToolkitPlugin;

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

enum class Mode : uint8_t {
    // Hook callback has been called before original function
    Pre = 0,
    // Hook callback has been called after original function
    Post
};

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

    virtual void* QueryInterface(CreateInterfaceFn fn, const char *iface, int min) = 0;
    virtual void* InterfaceSearch(CreateInterfaceFn fn, const char *iface, int max, int *ret) = 0;
    virtual int FormatIface(char iface[], size_t maxlength) = 0;
    virtual void* ToolkitFactory(const char *iface, int *ret, PluginId *id) = 0;
    virtual void* MetaFactory(const char *iface, int *ret, PluginId *id) = 0;

    virtual const char* GetBaseDir() =0;

    virtual size_t Format(char *buffer, size_t maxlength, const char *format, ...) = 0;
    virtual size_t FormatArgs(char *buffer, size_t maxlength, const char *format, va_list ap) = 0;
};

#endif //_INCLUDE_ITOOLKIT_API_H