//
// Created by Michal Přikryl on 02.03.2026.
// Copyright (c) 2026 slynxcz. All rights reserved.
//
#include "source2toolkit/schema/schema.h"
#include "source2toolkit/utils/virtual.h"

#ifdef SOURCE2TOOLKIT_CORE
#include "core/shared.h"
#include "core/gameconfig.h"
#else
#include "source2toolkit/IToolkitApi.h"
#include "source2toolkit/IToolkitGameConfig.h"
#include "source2toolkit/IToolkitPlugin.h"
#include "source2toolkit/IToolkitTypes.h"
#endif

#include "platform.h"
#include "edict.h"
#include "iserver.h"
#include "networksystem/inetworkmessages.h"
#include "schemasystem/schemasystem.h"
#include "entity2/entityidentity.h"
#include "entity2/entityinstance.h"
#include "tier0/memdbgon.h"
#include "tier1/utlmap.h"
#include <map>

#ifdef _WIN32
#define MODULE_PREFIX ""
#define MODULE_EXT ".dll"
#else
#define MODULE_PREFIX "lib"
#define MODULE_EXT ".so"
#endif

class GameSessionConfiguration_t
{
};

CGameEntitySystem* GameEntitySystem() { return GetEntitySystem(); }

IGameEventManager2* GetGameEventManager()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pGameEventManager;
#else
    return g_ToolkitAPI->GetGameEventManager();
#endif
}

CGlobalVars* GetGlobalVars()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::getGlobalVars();
#else
    return g_ToolkitAPI->GetGlobalVars();
#endif
}

ICvar* GetCVar()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pCVar;
#else
    return g_ToolkitAPI->GetCVar();
#endif
}

ISource2Server* GetSource2Server()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pServer;
#else
    return g_ToolkitAPI->GetSource2Server();
#endif
}

IVEngineServer* GetEngineServer()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pEngine;
#else
    return g_ToolkitAPI->GetEngineServer();
#endif
}

IGameEventSystem* GetGameEventSystem()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pGameEventSystem;
#else
    return g_ToolkitAPI->GetGameEventSystem();
#endif
}
INetworkMessages* GetNetworkMessages()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pNetworkMessages;
#else
    return g_ToolkitAPI->GetNetworkMessages();
#endif
}

INetworkServerService* GetNetworkServerService()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pNetworkServerService;
#else
    return g_ToolkitAPI->GetNetworkServerService();
#endif
}

CGameEntitySystem* GetEntitySystem()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pEntitySystem;
#else
    return g_ToolkitAPI->GetEntitySystem();
#endif
}

CSchemaSystem* GetSchemaSystem()
{
#ifdef SOURCE2TOOLKIT_CORE
    return shared::g_pSchemaSystem;
#else
    return g_ToolkitAPI->GetSchemaSystem();
#endif
}

using SchemaKeyValueMap_t = std::map<uint32_t, SchemaKey>;
using SchemaTableMap_t = std::map<uint32_t, SchemaKeyValueMap_t>;

static constexpr uint32_t g_ChainKey = hash_32_fnv1a_const("__m_pChainEntity");

static bool IsFieldNetworked(const char* cppName, SchemaClassFieldData_t& field)
{
    if (!GetEntitySystem())
        return false;

    // Just use a random class to get access to the full database, as some schema classes don't have entity representations
    CNetworkSerializerCodeGenDatabase* pDatabase = GetEntitySystem()->FindClassByName("CBaseEntity")->m_NetworkSerializerInfo->m_pDatabase;
    int index = pDatabase->m_ClassInfos.Find(cppName);

    if (index == pDatabase->m_ClassInfos.InvalidIndex())
        return false;

    if (pDatabase->m_ClassInfos[index]->FindField(field.m_pszName))
        return true;

    return false;
}

// Try to recursively find __m_pChainEntity in base classes
// (e.g. CCSGameRules -> CTeamplayRules -> CMultiplayRules -> CGameRules, in this case it's in CGameRules)
static void InitChainOffset(SchemaClassInfoData_t* pClassInfo, SchemaKeyValueMap_t& keyValueMap)
{
    short fieldsSize = pClassInfo->m_nFieldCount;
    SchemaClassFieldData_t* pFields = pClassInfo->m_pFields;

    for (int i = 0; i < fieldsSize; ++i)
    {
        SchemaClassFieldData_t& field = pFields[i];

        if (hash_32_fnv1a_const(field.m_pszName) != g_ChainKey)
            continue;

        std::pair<uint32_t, SchemaKey> keyValuePair;
        keyValuePair.first = g_ChainKey;
        keyValuePair.second.offset = field.m_nSingleInheritanceOffset;
        keyValuePair.second.networked = IsFieldNetworked(pClassInfo->m_pszName, field);

        keyValueMap.insert(keyValuePair);
        return;
    }

    // Not the base class yet, keep looking
    if (pClassInfo->m_nBaseClassCount)
        return InitChainOffset(pClassInfo->m_pBaseClasses[0].m_pClass, keyValueMap);
}

static void InitSchemaKeyValueMap(SchemaClassInfoData_t* pClassInfo, SchemaKeyValueMap_t& keyValueMap)
{
    short fieldsSize = pClassInfo->m_nFieldCount;
    SchemaClassFieldData_t* pFields = pClassInfo->m_pFields;

    for (int i = 0; i < fieldsSize; ++i)
    {
        SchemaClassFieldData_t& field = pFields[i];

        std::pair<uint32_t, SchemaKey> keyValuePair;
        keyValuePair.first = hash_32_fnv1a_const(field.m_pszName);
        keyValuePair.second.offset = field.m_nSingleInheritanceOffset;
        keyValuePair.second.networked = IsFieldNetworked(pClassInfo->m_pszName, field);

        keyValueMap.insert(keyValuePair);
    }

    // If this is a child class there might be a parent class with __m_pChainEntity
    if (keyValueMap.find(g_ChainKey) == keyValueMap.end() && pClassInfo->m_nBaseClassCount)
        InitChainOffset(pClassInfo->m_pBaseClasses[0].m_pClass, keyValueMap);
}

static bool InitSchemaFieldsForClass(SchemaTableMap_t& tableMap, const char* className, uint32_t classKey)
{
    CSchemaSystemTypeScope* pType = GetSchemaSystem()->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);

    if (!pType)
        return false;

    SchemaClassInfoData_t* pClassInfo = pType->FindDeclaredClass(className).Get();

    if (!pClassInfo)
    {
        SchemaKeyValueMap_t map;
        tableMap.insert(std::make_pair(classKey, map));

#ifdef SOURCE2TOOLKIT_CORE
        FP_WARN("InitSchemaFieldsForClass(): '{}' was not found!", className);
#endif
        return false;
    }

    SchemaKeyValueMap_t& keyValueMap = tableMap.insert(std::make_pair(classKey, SchemaKeyValueMap_t())).first->second;

    InitSchemaKeyValueMap(pClassInfo, keyValueMap);

    return true;
}

int16_t schema::FindChainOffset(const char* className, uint32_t classNameHash)
{
    return schema::GetOffset(className, classNameHash, "__m_pChainEntity", g_ChainKey).offset;
}

int16_t schema::FindChainOffset(const char* className)
{
    CSchemaSystemTypeScope* pType = GetSchemaSystem()->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);

    if (!pType)
        return false;

    SchemaClassInfoData_t* pClassInfo = pType->FindDeclaredClass(className).Get();

    do
    {
        SchemaClassFieldData_t* pFields = pClassInfo->m_pFields;
        short fieldsSize = pClassInfo->m_nFieldCount;
        for (int i = 0; i < fieldsSize; ++i)
        {
            SchemaClassFieldData_t& field = pFields[i];

            if (V_strcmp(field.m_pszName, "__m_pChainEntity") == 0)
            {
                return field.m_nSingleInheritanceOffset;
            }
        }
    }
    while ((pClassInfo = pClassInfo->m_pBaseClasses ? pClassInfo->m_pBaseClasses->m_pClass : nullptr) != nullptr);

    return 0;
}

SchemaKey schema::GetOffset(const char* className, uint32_t classKey, const char* memberName, uint32_t memberKey)
{
    static SchemaTableMap_t schemaTableMap;

    if (schemaTableMap.find(classKey) == schemaTableMap.end())
    {
        if (InitSchemaFieldsForClass(schemaTableMap, className, classKey))
            return GetOffset(className, classKey, memberName, memberKey);

        return {0, 0};
    }

    SchemaKeyValueMap_t tableMap = schemaTableMap[classKey];

    if (tableMap.find(memberKey) == tableMap.end())
    {
        if (memberKey != g_ChainKey)
#ifdef SOURCE2TOOLKIT_CORE
            FP_WARN("schema::GetOffset(): '{}' was not found in '{}'!\n", memberName, className);
#endif

        return {0, 0};
    }

    return tableMap[memberKey];
}

int32_t schema::GetServerOffset(const char* pszClassName, const char* pszPropName)
{
    SchemaClassInfoData_t* pClassInfo = GetSchemaSystem()->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT)->FindDeclaredClass(pszClassName).Get();
    if (pClassInfo)
    {
        for (int i = 0; i < pClassInfo->m_nFieldCount; i++)
        {
            auto& pFieldData = pClassInfo->m_pFields[i];

            if (strcmp(pFieldData.m_pszName, pszPropName) == 0)
            {
                return pFieldData.m_nSingleInheritanceOffset;
            }
        }
    }

    return -1;
}

int32_t schema::GetClassSize(const char* className) {
    CSchemaSystemTypeScope *pType = GetSchemaSystem()->FindTypeScopeForModule(
        MODULE_PREFIX "server" MODULE_EXT);

    SchemaClassInfoData_t *pClassInfo = pType->FindDeclaredClass(className).Get();
    if (!pClassInfo) return -1;

    return pClassInfo->m_nSize;
}

void schema::SetStateChanged(CEntityInstance *entity, const char *className, const char *propName) {
    if (!entity || !className || !propName)
        return;

    const uint32_t classHash = hash_32_fnv1a_const(className);
    const uint32_t propHash = hash_32_fnv1a_const(propName);

    SchemaKey key = GetOffset(className, classHash, propName, propHash);

    if (!key.networked || key.offset == 0)
        return;

    const int16_t chainOffset = FindChainOffset(className, classHash);

    auto pEntity = reinterpret_cast<uintptr_t>(entity);

    if (chainOffset != 0)
        ChainNetworkStateChanged(pEntity + chainOffset, key.offset);
    else
        EntityNetworkStateChanged(pEntity, key.offset);
}

void NetworkVarStateChanged(uintptr_t pNetworkVar, uint32_t nOffset, uint32 nNetworkStateChangedOffset)
{
    NetworkStateChangedData data(nOffset);
    CALL_VIRTUAL(void, nNetworkStateChangedOffset, (void*)pNetworkVar, &data);
}

void EntityNetworkStateChanged(uintptr_t pEntity, uint nOffset)
{
    NetworkStateChangedData data(nOffset);
    reinterpret_cast<CEntityInstance*>(pEntity)->NetworkStateChanged(data);
}

void ChainNetworkStateChanged(uintptr_t pNetworkVarChainer, uint nLocalOffset)
{
    CEntityInstance* pEntity = reinterpret_cast<CNetworkVarChainer2*>(pNetworkVarChainer)->m_pEntity;

    if (pEntity)
        pEntity->NetworkStateChanged(NetworkStateChangedData(nLocalOffset, -1, reinterpret_cast<CNetworkVarChainer2*>(pNetworkVarChainer)->m_PathIndex));
}