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
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#endif

void* UTIL_GetModuleHandle(void* module);
uintptr_t UTIL_GetModuleBase(void* module);

uintptr_t UTIL_FindPattern(void* module, const char* pattern);
uintptr_t UTIL_FindPatternInSection(void* module, const char* section, const char* pattern);

uintptr_t UTIL_GetFunctionByName(void* module, const char* symbol);
uintptr_t UTIL_GetVirtualTableByName(void* module, const char* name);

uintptr_t UTIL_Offset(uintptr_t address, ptrdiff_t offset);
uintptr_t UTIL_OffsetSelf(uintptr_t& address, ptrdiff_t offset);

uintptr_t UTIL_Deref(uintptr_t address, int count = 1);
uintptr_t UTIL_DerefSelf(uintptr_t& address, int count = 1);

uintptr_t UTIL_ResolveRelativeAddress(uintptr_t address, ptrdiff_t offset = 0x0, ptrdiff_t size = 0x4);
uintptr_t UTIL_FollowNearCall(uintptr_t address, ptrdiff_t offset = 0x1, ptrdiff_t size = 0x5);