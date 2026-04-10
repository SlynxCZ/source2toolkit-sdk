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

#include "CSceneEntity.h"

class CBaseEntity;

class CInstancedSceneEntity : public CSceneEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInstancedSceneEntity);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOwner);
    SCHEMA_FIELD(bool, m_bHadOwner);
    SCHEMA_FIELD(float, m_flPostSpeakDelay);
    SCHEMA_FIELD(float, m_flPreDelay);
    SCHEMA_FIELD(bool, m_bIsBackground);
    SCHEMA_FIELD(bool, m_bRemoveOnCompletion);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTarget);

public:
    static CInstancedSceneEntity* New(const char* className)
    {
        return CBaseEntity::New<CInstancedSceneEntity>(className);
    }

    static CInstancedSceneEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInstancedSceneEntity>(iIndex);
    }

    static CInstancedSceneEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
