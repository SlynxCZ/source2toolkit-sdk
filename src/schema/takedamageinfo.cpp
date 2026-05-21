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

#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitTypes.h"

#include "source2toolkit/schema/takedamageinfo.h"


CTakeDamageInfo::CTakeDamageInfo()
{
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.CTakeDamageInfo(this, nullptr, nullptr, nullptr, &vec3_origin, &vec3_origin, 0.f, 0, 0, nullptr);
#else
    g_ToolkitAPI->Addresses()->CTakeDamageInfo_CTakeDamageInfo()(this, nullptr, nullptr, nullptr, &vec3_origin, &vec3_origin, 0.f, 0, 0, nullptr);
#endif
}

CTakeDamageInfo::CTakeDamageInfo(CBaseEntity* pInflictor, CBaseEntity* pAttacker, CBaseEntity* pAbility, float flDamage, DamageTypes_t bitsDamageType)
{
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.CTakeDamageInfo(this, pInflictor, pAttacker, pAbility, &vec3_origin, &vec3_origin, flDamage, bitsDamageType, 0, nullptr);
#else
    g_ToolkitAPI->Addresses()->CTakeDamageInfo_CTakeDamageInfo()(this, pInflictor, pAttacker, pAbility, &vec3_origin, &vec3_origin, flDamage, (int)bitsDamageType, 0, nullptr);
#endif
}

HitGroup_t CTakeDamageInfo::GetHitGroup() const
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CTakeDamageInfo_HitGroup");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CTakeDamageInfo_HitGroup");
#endif

    if (offset <= 0)
        return HitGroup_t::HITGROUP_INVALID;

    const uintptr_t base = reinterpret_cast<uintptr_t>(this);

    const uintptr_t v4 = *reinterpret_cast<const uintptr_t*>(base + offset);
    if (!v4)
        return HitGroup_t::HITGROUP_INVALID;

    const uintptr_t v1 = *reinterpret_cast<const uintptr_t*>(v4 + 16);
    if (!v1)
        return HitGroup_t::HITGROUP_GENERIC;

    const int32_t group = *reinterpret_cast<const int32_t*>(v1 + 56);
    return static_cast<HitGroup_t>(group);
}