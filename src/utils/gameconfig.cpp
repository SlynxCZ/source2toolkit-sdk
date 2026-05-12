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
