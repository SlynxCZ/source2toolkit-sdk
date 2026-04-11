//
// Created by Michal Přikryl on 11.04.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
/**
* =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2026 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef SOURCE2TOOLKIT_CORE
#include "core/convars.h"
#else
#include "source2toolkit/IToolkitConVars.h"
#endif

uint16 UTIL_FindConVar(const char* name);

int UTIL_GetConVarInt(uint16 accessIndex);

float UTIL_GetConVarFloat(uint16 accessIndex);

bool UTIL_GetConVarBool(uint16 accessIndex);

void UTIL_SetConVarInt(uint16 accessIndex, int value);

void UTIL_SetConVarFloat(uint16 accessIndex, float value);

void UTIL_SetConVarBool(uint16 accessIndex, bool value);

const char* UTIL_GetConVarString(uint16 accessIndex);

void UTIL_SetConVarString(uint16 accessIndex, const char* value);

void* UTIL_GetConVarValueAddress(uint16 accessIndex);

void UTIL_SetConVarValue(uint16 accessIndex, const void* value);