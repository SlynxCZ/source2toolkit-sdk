//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_GAMECONFIG_H
#define _INCLUDE_ITOOLKIT_GAMECONFIG_H

#pragma once
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Core Toolkit GameConfig
   ========================= */

class IToolkitGameConfig
{
public:
    virtual ~IToolkitGameConfig() = default;

    virtual const char* GetLibrary(const char* pchName) = 0;
    virtual const char* GetSignature(const char* pchName) = 0;
    virtual const char* GetSymbol(const char* pchName) = 0;
    virtual const char* GetPatch(const char* pchName) = 0;
    virtual int GetOffset(const char* pchName) = 0;
};

#endif //_INCLUDE_ITOOLKIT_GAMECONFIG_H
