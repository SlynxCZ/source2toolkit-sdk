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

#include "source2toolkit/schema/entity/classes/CBaseEntity.h"

#include "source2toolkit/schema/entity/classes/CBodyComponent.h"
#include "source2toolkit/schema/entity/classes/CCollisionProperty.h"
#include "source2toolkit/schema/entity/classes/CEntitySubclassVDataBase.h"
#include "source2toolkit/schema/entity/classes/CGameSceneNode.h"

#include "source2toolkit/schema/entities.h"
#include "source2toolkit/utils/virtual.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#include "core/addresses.h"
#else
#include "source2toolkit/IToolkitAddresses.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitPlugin.h"
#endif

CBaseEntity* CBaseEntity::CreateEntityByName(const char* pszClassName)
{
    return UTIL_CreateEntityByName(pszClassName);
}

void CBaseEntity::AcceptInput(const char* pszInput, CEntityInstance* pActivator, CEntityInstance* pCaller, const char* pszValue)
{
    UTIL_AcceptInput(this, pszInput, pActivator, pCaller, pszValue);
}

void CBaseEntity::AddEntityIOEvent(const char* pszInput, CEntityInstance* pActivator, CEntityInstance* pCaller, const char* pszValue, float flDelay)
{
    UTIL_AddEntityIOEvent(this, pszInput, pActivator, pCaller, pszValue, flDelay);
}

CEntityIOListenerHandle* CBaseEntity::AddSingleEntityIOListener(const char* pszOutput, std::function<Action(const char*,CEntityInstance*, CEntityInstance*, float, Mode)> callback, Mode mode)
{
    auto* listener = new CSingleEntityIOListener(this, std::move(callback));

    const char* classname = this->GetClassname();

    UTIL_AddEntityIOListener(listener, classname, pszOutput, mode);

    auto* handle = new CEntityIOListenerHandle();
    handle->m_pListener = listener;
    handle->m_szClassname = classname ? classname : "*";
    handle->m_szOutput = pszOutput ? pszOutput : "*";
    handle->m_nMode = mode;

    return handle;
}

Vector CBaseEntity::GetAbsOrigin()
{
    return m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin;
}

QAngle CBaseEntity::GetAngRotation()
{
    return m_CBodyComponent->m_pSceneNode->m_angRotation;
}

QAngle CBaseEntity::GetAbsRotation()
{
    return m_CBodyComponent->m_pSceneNode->m_angAbsRotation;
}

Vector CBaseEntity::GetAbsVelocity()
{
    return m_vecAbsVelocity;
}

void CBaseEntity::SetAbsOrigin(Vector vecOrigin)
{
    m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin(vecOrigin);
}

void CBaseEntity::SetAbsRotation(QAngle angAbsRotation)
{
    m_CBodyComponent->m_pSceneNode->m_angAbsRotation(angAbsRotation);
}

void CBaseEntity::SetAngRotation(QAngle angRotation)
{
    m_CBodyComponent->m_pSceneNode->m_angRotation(angRotation);
}

void CBaseEntity::SetAbsVelocity(Vector vecVelocity)
{
    m_vecAbsVelocity = vecVelocity;
}

void CBaseEntity::SetBaseVelocity(Vector vecVelocity)
{
    m_vecBaseVelocity = vecVelocity;
}

CEntitySubclassVDataBase* CBaseEntity::GetVData()
{
    return *(CEntitySubclassVDataBase**)((uint8*)(m_nSubclassID()) + 4);
}

void CBaseEntity::DispatchSpawn(CEntityKeyValues* pEntityKeyValues)
{
#ifdef SOURCE2TOOLKIT_CORE
    addresses::toolkitAddresses.DispatchSpawn(this, pEntityKeyValues);
#else
    g_ToolkitAPI->Addresses()->CBaseEntity_DispatchSpawn()(this, pEntityKeyValues);
#endif
}

void CBaseEntity::Teleport(const Vector* pPosition, const QAngle* pAngles, const Vector* pVelocity)
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CBaseEntity_Teleport");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CBaseEntity_Teleport");
#endif
    CALL_VIRTUAL(void, offset, this, pPosition, pAngles, pVelocity);
}

void CBaseEntity::SetMoveType(MoveType_t nMoveType)
{
    m_MoveType() = nMoveType;
    m_nActualMoveType() = nMoveType;
}

uint8 CBaseEntity::GetCollisionGroup()
{
    if (!m_pCollision())
        return 0;

    return m_pCollision->m_collisionAttribute().m_nCollisionGroup;
}

void CBaseEntity::SetCollisionGroup(uint8 nCollisionGroup = COLLISION_GROUP_DEBRIS)
{
    if (!m_pCollision())
        return;

    m_pCollision->m_collisionAttribute().m_nCollisionGroup = nCollisionGroup;
    m_pCollision->m_CollisionGroup() = nCollisionGroup;
    CollisionRulesChanged();
}

void CBaseEntity::CollisionRulesChanged()
{
#ifdef SOURCE2TOOLKIT_CORE
    static int offset = shared::g_pGameConfig->GetOffset("CBaseEntity_CollisionRulesChanged");
#else
    static int offset = g_ToolkitAPI->GameConfig()->GetOffset("CBaseEntity_CollisionRulesChanged");
#endif
    CALL_VIRTUAL(void, offset, this);
}

int CBaseEntity::GetIndex()
{
    return GetEntityIndex().Get();
}

CHandle<CBaseEntity> CBaseEntity::GetHandle() { return m_pEntity->m_EHandle; }

const char* CBaseEntity::GetName() const { return m_pEntity->m_name.String(); }