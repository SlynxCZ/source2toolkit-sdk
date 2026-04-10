#pragma once
#include "CBaseEntity.h"
#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitTypes.h"
#include "source2toolkit/schema/entityio.h"
#include "source2toolkit/schema/schema.h"
#include <cstdint>

#include "CLogicalEntity.h"
#include "../enums/PointTemplateClientOnlyEntityBehavior_t.h"
#include "../enums/PointTemplateOwnerSpawnGroupType_t.h"

class CPointTemplate : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointTemplate);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszWorldName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSource2EntityLumpName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEntityFilterName);
    SCHEMA_FIELD(float, m_flTimeoutInterval);
    SCHEMA_FIELD(bool, m_bAsynchronouslySpawnEntities);
    SCHEMA_FIELD(PointTemplateClientOnlyEntityBehavior_t, m_clientOnlyEntityBehavior);
    SCHEMA_FIELD(PointTemplateOwnerSpawnGroupType_t, m_ownerSpawnGroupType);
    SCHEMA_FIELD(CUtlVector<uint32_t>, m_createdSpawnGroupHandles);
    SCHEMA_FIELD(CUtlVector<CEntityHandle>, m_SpawnedEntityHandles);

public:
    static CPointTemplate* New(const char* className)
    {
        return CBaseEntity::New<CPointTemplate>(className);
    }

    static CPointTemplate* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointTemplate>(iIndex);
    }

    static CPointTemplate* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
