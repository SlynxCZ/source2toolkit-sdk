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

#include "source2toolkit/utils/convars.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/convars.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitConVars.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

static IToolkitConVars* GetConVars()
{
#ifdef SOURCE2TOOLKIT_CORE
    return &convars::convarsManager;
#else
    return g_ToolkitAPI->ConVars();
#endif
}

uint16 UTIL_FindConVar(const char* name)
{
    return GetConVars()->GetConvarAccessIndexByName(name);
}

int UTIL_GetConVarInt(uint16 accessIndex)
{
    return GetConVars()->GetInt(accessIndex);
}

float UTIL_GetConVarFloat(uint16 accessIndex)
{
    return GetConVars()->GetFloat(accessIndex);
}

bool UTIL_GetConVarBool(uint16 accessIndex)
{
    return GetConVars()->GetBool(accessIndex);
}

void UTIL_SetConVarInt(uint16 accessIndex, int value)
{
    GetConVars()->SetInt(accessIndex, value);
}

void UTIL_SetConVarFloat(uint16 accessIndex, float value)
{
    GetConVars()->SetFloat(accessIndex, value);
}

void UTIL_SetConVarBool(uint16 accessIndex, bool value)
{
    GetConVars()->SetBool(accessIndex, value);
}

const char* UTIL_GetConVarString(uint16 accessIndex)
{
    return GetConVars()->GetString(accessIndex);
}

void UTIL_SetConVarString(uint16 accessIndex, const char* value)
{
    GetConVars()->SetString(accessIndex, value);
}

void* UTIL_GetConVarValueAddress(uint16 accessIndex)
{
    return GetConVars()->GetValueAddress(accessIndex);
}

void UTIL_SetConVarValue(uint16 accessIndex, const void* value)
{
    GetConVars()->SetValue(accessIndex, value);
}