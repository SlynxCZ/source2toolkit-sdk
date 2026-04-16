//
// Created by Michal Přikryl on 04.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/entity/classes/CBaseEntity.h"

#include "source2toolkit/schema/entity/classes/CBodyComponent.h"
#include "source2toolkit/schema/entity/classes/CCollisionProperty.h"
#include "source2toolkit/schema/entity/classes/CEntitySubclassVDataBase.h"
#include "source2toolkit/schema/entity/classes/CGameSceneNode.h"

#include "source2toolkit/schema/entity.h"
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