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

* @file convars.h
* @brief High-level helper functions for working with console variables (ConVars).
*
* These functions provide simplified access to the IToolkitConVars interface.
* They allow reading, writing, and querying ConVars without directly using access indices.
*
* @note Internally wraps IToolkitConVars.
*/

#ifndef _INCLUDE_ITOOLKIT_UTILS_CONVARS_H
#define _INCLUDE_ITOOLKIT_UTILS_CONVARS_H

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/convars.h"
#else
#include "source2toolkit/IToolkitConVars.h"
#endif

/**

* @brief Finds a ConVar by name.
*
* @param name ConVar name (e.g. "sv_cheats")
* @return Access index used for further operations
*
* @note Wrapper around IToolkitConVars::GetConvarAccessIndexByName()
  */
uint16 UTIL_FindConVar(const char* name);

/**

* @brief Gets integer value of a ConVar.
  */
int UTIL_GetConVarInt(uint16 accessIndex);

/**

* @brief Gets float value of a ConVar.
  */
float UTIL_GetConVarFloat(uint16 accessIndex);

/**

* @brief Gets boolean value of a ConVar.
  */
bool UTIL_GetConVarBool(uint16 accessIndex);

/**

* @brief Sets integer value of a ConVar.
  */
void UTIL_SetConVarInt(uint16 accessIndex, int value);

/**

* @brief Sets float value of a ConVar.
  */
void UTIL_SetConVarFloat(uint16 accessIndex, float value);

/**

* @brief Sets boolean value of a ConVar.
  */
void UTIL_SetConVarBool(uint16 accessIndex, bool value);

/**

* @brief Gets string value of a ConVar.
*
* @return Null-terminated string (owned by engine)
  */
const char* UTIL_GetConVarString(uint16 accessIndex);

/**

* @brief Sets string value of a ConVar.
  */
void UTIL_SetConVarString(uint16 accessIndex, const char* value);

/**

* @brief Gets raw pointer to ConVar value.
*
* @return Pointer to underlying value storage
*
* @warning Type must be interpreted manually based on ConVar type
  */
void* UTIL_GetConVarValueAddress(uint16 accessIndex);

/**

* @brief Sets raw value of a ConVar.
*
* @param value Pointer to value (type depends on ConVar type)
*
* @warning Unsafe if type does not match ConVar type
  */
void UTIL_SetConVarValue(uint16 accessIndex, const void* value);

#endif //_INCLUDE_ITOOLKIT_UTILS_CONVARS_H

