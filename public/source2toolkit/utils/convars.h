/**

* @file convars.h
* @brief High-level helper functions for working with console variables (ConVars).
*
* These functions provide simplified access to the IToolkitConVars interface.
* They allow reading, writing, and querying ConVars without directly using access indices.
*
* @note Internally wraps IToolkitConVars.
  */

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
