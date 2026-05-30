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

#include "source2toolkit/schema/entity/classes/CBaseModelEntity.h"

#include "source2toolkit/schema/entity/classes/CBodyComponent.h"
#include "source2toolkit/schema/entity/classes/CSkeletonInstance.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
#endif

CUtlSymbolLarge CBaseModelEntity::GetModelName()
{
    if(m_CBodyComponent == nullptr) return CUtlSymbolLarge();
    if(m_CBodyComponent->m_pSceneNode == nullptr) return CUtlSymbolLarge();
    if(((CSkeletonInstance*)m_CBodyComponent->m_pSceneNode.Get()) == nullptr) return CUtlSymbolLarge();
    return ((CSkeletonInstance*)m_CBodyComponent->m_pSceneNode.Get())->m_modelState().m_ModelName.Get();
}

Vector CBaseModelEntity::GetEyePosition()
{
    Vector x = Vector(m_vecViewOffset().m_vecX, m_vecViewOffset().m_vecY, m_vecViewOffset().m_vecZ);
    Vector m_vecOrigin = GetAbsOrigin();
    return {
        m_vecOrigin.x + x.x,
        m_vecOrigin.y + x.y,
        m_vecOrigin.z + x.z
    };
}

void CBaseModelEntity::SetModel(const char* pszModel) {
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.SetModel(this, pszModel);
#else
    g_ToolkitAPI->Addresses()->CBaseModelEntity_SetModel()(this, pszModel);
#endif
}