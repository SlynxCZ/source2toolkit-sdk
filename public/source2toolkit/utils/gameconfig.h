/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
 * AlliedModders LLC. All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
 * AlliedModders LLC give you permission to link the code of this program
 * (as well as its derivative works) to "Counter-Strike 2," "Source 2,"
 * "Steam," and any Game MODs or server software running on software by
 * Valve Corporation. You must obey the GNU General Public License in all
 * respects for all other code used.
 *
 * Additionally, this exception applies to all derivative works unless
 * otherwise stated in LICENSE.txt.
 *
 * Authors:
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

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

#ifndef _INCLUDE_ITOOLKIT_UTILS_GAMECONFIG_H
#define _INCLUDE_ITOOLKIT_UTILS_GAMECONFIG_H

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

#endif //_INCLUDE_ITOOLKIT_UTILS_GAMECONFIG_H

