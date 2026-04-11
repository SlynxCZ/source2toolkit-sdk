//
// Created by Michal Přikryl on 10.04.2026.
// Copyright (c) 2026 slynxcz.
//

#ifndef _INCLUDE_ITOOLKIT_TYPES_H
#define _INCLUDE_ITOOLKIT_TYPES_H

#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>

#ifndef SOURCE2TOOLKIT_CORE
#include "IToolkitPlugin.h"
TOOLKIT_GLOBALVARS();
#endif

/* =========================
   Forward declarations
   ========================= */
enum class Action : std::uint8_t {
    // Hook has taken no specific action
    Ignore = 0,
    // Hook has overwritten the return value
    // But call original anyways if in PRE callback
    // Doesn't do anything in a POST callback
    Override,
    // Hook has overwritten thre return value
    // Don't call the original if in PRE callback
    // Doesn't do anything in a POST callback
    Supersede
};

enum class Mode : std::uint8_t {
    // Hook callback has been called before original function
    Pre = 0,
    // Hook callback has been called after original function
    Post
};

#endif //_INCLUDE_ITOOLKIT_TYPES_H
