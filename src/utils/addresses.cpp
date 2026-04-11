//
// Created by Michal Přikryl on 11.03.2026.
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
#include "source2toolkit/utils/addresses.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitAddresses* GetAddrs()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &addresses::toolkitAddresses;
#else
    return g_ToolkitAPI->Addresses();
#endif
}

void* UTIL_GetModuleHandle(void* module)
{
    return GetAddrs()->GetModuleHandle(module);
}

uintptr_t UTIL_GetModuleBase(void* module)
{
    return GetAddrs()->GetModuleBase(module);
}

uintptr_t UTIL_FindPattern(void* module, const char* pattern)
{
    return GetAddrs()->FindPattern(module, pattern);
}

uintptr_t UTIL_FindPatternInSection(void* module, const char* section, const char* pattern)
{
    return GetAddrs()->FindPatternInSection(module, section, pattern);
}

uintptr_t UTIL_GetFunctionByName(void* module, const char* symbol)
{
    return GetAddrs()->GetFunctionByName(module, symbol);
}

uintptr_t UTIL_GetVirtualTableByName(void* module, const char* name)
{
    return GetAddrs()->GetVirtualTableByName(module, name);
}

uintptr_t UTIL_Offset(uintptr_t address, ptrdiff_t offset)
{
    return GetAddrs()->Offset(address, offset);
}

uintptr_t UTIL_OffsetSelf(uintptr_t& address, ptrdiff_t offset)
{
    return GetAddrs()->OffsetSelf(address, offset);
}

uintptr_t UTIL_Deref(uintptr_t address, int count)
{
    return GetAddrs()->Deref(address, count);
}

uintptr_t UTIL_DerefSelf(uintptr_t& address, int count)
{
    return GetAddrs()->DerefSelf(address, count);
}

uintptr_t UTIL_ResolveRelativeAddress(uintptr_t address, ptrdiff_t offset, ptrdiff_t size)
{
    return GetAddrs()->ResolveRelativeAddress(address, offset, size);
}

uintptr_t UTIL_FollowNearCall(uintptr_t address, ptrdiff_t offset, ptrdiff_t size)
{
    return GetAddrs()->FollowNearCall(address, offset, size);
}