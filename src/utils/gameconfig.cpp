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
#include "source2toolkit/utils/gameconfig.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitGameConfig* GetGameConfig()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pGameConfig;
#else
    return g_ToolkitAPI->GameConfig();
#endif
}

const char* UTIL_GetLibrary(const char* pchName)
{
    return GetGameConfig()->GetLibrary(pchName);
}

const char* UTIL_GetSignature(const char* pchName)
{
    return GetGameConfig()->GetSignature(pchName);
}

const char* UTIL_GetSymbol(const char* pchName)
{
    return GetGameConfig()->GetSymbol(pchName);
}

const char* UTIL_GetPatch(const char* pchName)
{
    return GetGameConfig()->GetPatch(pchName);
}

int UTIL_GetOffset(const char* pchName)
{
    return GetGameConfig()->GetOffset(pchName);
}
