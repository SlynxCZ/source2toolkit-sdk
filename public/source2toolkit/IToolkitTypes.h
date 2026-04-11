/**

* @file IToolkitTypes.h
* @brief Common types and enums used across Source2Toolkit.
*
* Defines core types used for:
* * Hook control flow (Action)
* * Execution timing (Mode)
*
* @note These types are used in commands, events, and other hook-based systems.
  */

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
Hook control
========================= */

/**

* @brief Describes how a hook affects execution.
*
* Used as return value in callbacks to control original function behavior.
  */
enum class Action : std::uint8_t
{
    /**

    * @brief Do nothing.
    *
    * Original function executes normally.
      */
    Ignore = 0,

    /**

    * @brief Override return value but still call original function.
    *
    * @note Only meaningful in Pre mode.
      */
    Override,

    /**

    * @brief Completely block original function execution.
    *
    * @note Only meaningful in Pre mode.
      */
    Supersede
};

/* =========================
Execution mode
========================= */

/**

* @brief Determines when a hook is executed.
  */
enum class Mode : std::uint8_t
{
    /**

    * @brief Called before original function.
    *
    * Allows modifying input or blocking execution.
      */
    Pre = 0,

    /**

    * @brief Called after original function.
    *
    * Allows observing results but not blocking execution.
      */
    Post
};

#endif //_INCLUDE_ITOOLKIT_TYPES_H
