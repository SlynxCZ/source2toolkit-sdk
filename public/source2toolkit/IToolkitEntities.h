//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_ENTITIES_H
#define _INCLUDE_ITOOLKIT_ENTITIES_H

#pragma once
#include "entitysystem.h"
#include "eiface.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

/* =========================
   Forward declarations
   ========================= */

using TimerCallback = std::function<void()>;

class Timer;

/* =========================
   Core Toolkit Entities
   ========================= */

class IToolkitEntities
{
public:
   virtual void NextFrame(std::function<void()> &&task) = 0;
   virtual Timer* AddTimer(float interval, TimerCallback callback, int flags = 0);
   virtual void KillTimer(Timer* timer) = 0;
};

#endif //_INCLUDE_ITOOLKIT_ENTITIES_H
