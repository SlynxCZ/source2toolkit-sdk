//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_COMMANDS_H
#define _INCLUDE_ITOOLKIT_COMMANDS_H

#pragma once
#include "convar.h"
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Forward declarations
   ========================= */

using ChatHandler = std::function<void(const CCommandContext&, const CCommand&, uint8_t)>;
using CommandHandler = std::function<uint8_t(const CCommandContext&, const CCommand&, uint8_t)>;

/* =========================
   Core Toolkit Commands
   ========================= */

class IToolkitCommands
{
public:
   virtual void RegChatListener(const char* pchName, ChatHandler handler) = 0;
   virtual void RegConCommand(const char* pchName, ChatHandler handler) = 0;
   virtual void RegConListener(const char* pchName, CommandHandler handler, uint8_t mode) = 0;
};

#endif //_INCLUDE_ITOOLKIT_COMMANDS_H
