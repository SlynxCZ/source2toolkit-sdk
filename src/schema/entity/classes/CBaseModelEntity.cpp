//
// Created by Michal Přikryl on 04.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
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