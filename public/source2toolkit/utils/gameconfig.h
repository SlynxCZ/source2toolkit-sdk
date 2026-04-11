/**

* @file gameconfig.h
* @brief High-level helper functions for accessing game configuration data.
*
* These functions provide simplified access to the IToolkitGameConfig interface.
*
* GameConfig is typically used for:
* * Resolving signatures (pattern scanning definitions)
* * Accessing symbols (exported functions)
* * Reading offsets
* * Applying patches
*
* @note Internally wraps IToolkitGameConfig.
  */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/gameconfig.h"
#else
#include "source2toolkit/IToolkitGameConfig.h"
#endif

/**

* @brief Gets library/module name from config.
*
* @param pchName Entry name
* @return Library name (e.g. "server", "client")
*
* @note Used for resolving module handles.
  */
const char* UTIL_GetLibrary(const char* pchName);

/**

* @brief Gets signature (pattern) from config.
*
* @param pchName Entry name
* @return Pattern string (e.g. "48 8B ?? ?? ??")
*
* @note Used for pattern scanning.
  */
const char* UTIL_GetSignature(const char* pchName);

/**

* @brief Gets symbol name from config.
*
* @param pchName Entry name
* @return Symbol name
*
* @note Used with exported functions.
  */
const char* UTIL_GetSymbol(const char* pchName);

/**

* @brief Gets patch definition from config.
*
* @param pchName Entry name
* @return Patch string or data
*
* @note Used for runtime memory patching.
  */
const char* UTIL_GetPatch(const char* pchName);

/**

* @brief Gets integer offset from config.
*
* @param pchName Entry name
* @return Offset value
*
* @note Commonly used for structure offsets or vtable indices.
  */
int UTIL_GetOffset(const char* pchName);
