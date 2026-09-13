/**
* vim: set ts=4 sw=4 tw=99 noet:
 * =============================================================================
 * Source2Toolkit
 * Copyright (C) 2025-2026 Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl,
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
 * As a special exception, Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl and
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
 *   - Michal "Slynx (˙·٠● S l y n x ●٠·˙)" Přikryl
 *   - AlliedModders LLC
 *
 * Project: Source2Toolkit
 */

// The IToolkitHook helpers that talk to IToolkitAPI and IToolkitGameConfig.
// They live here rather than in IToolkitHooks.h because that header is pulled
// in from the end of IToolkitPlugin.h, where both are only forward-declared.

#ifndef SOURCE2TOOLKIT_CORE

#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitPlugin.h"
#include "source2toolkit/IToolkitHooks.h"

TOOLKIT_GLOBALVARS();

void IToolkitHook::Warn(const char* pszFormat, const char* pszName)
{
    if (g_ToolkitAPI)
        g_ToolkitAPI->Log(g_PluginAPI, pszFormat, pszName ? pszName : "(null)");
}

void IToolkitHook::FreeModule(IToolkitModule* pModule)
{
    if (g_ToolkitAPI && pModule)
        g_ToolkitAPI->FreeModule(pModule);
}

int IToolkitHook::GetOffset(const char* pszName)
{
    return g_pToolkitGameConfig ? g_pToolkitGameConfig->GetOffset(pszName) : -1;
}

IToolkitMemory IToolkitHook::ResolveSignature(const char* pszName)
{
    return g_pToolkitGameConfig ? g_pToolkitGameConfig->ResolveSignature(pszName) : IToolkitMemory();
}

#endif // SOURCE2TOOLKIT_CORE
