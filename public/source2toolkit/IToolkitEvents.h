//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_EVENTS_H
#define _INCLUDE_ITOOLKIT_EVENTS_H

#pragma once
#include "igameevents.h"
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Forward declarations
   ========================= */

using GameEventHandler = std::function<uint8_t(IGameEvent* event, uint8_t mode, bool& dontBroadcast)>;

/* =========================
   Core Toolkit Events
   ========================= */

class IToolkitEvents
{
public:
   virtual void RegGameEvent(const char* pchName, GameEventHandler handler, uint8_t mode) = 0;
};

#endif //_INCLUDE_ITOOLKIT_EVENTS_H
