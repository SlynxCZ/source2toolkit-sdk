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

class CBaseEntity;

class CSceneListManager : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSceneListManager);

    SCHEMA_FIELD(CUtlVector<CHandle<CSceneListManager>>, m_hListManagers);
    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_iszScenes);
    SCHEMA_FIELD_POINTER(CHandle<CBaseEntity>, m_hScenes);

public:
    static CSceneListManager* New(const char* className)
    {
        return CBaseEntity::New<CSceneListManager>(className);
    }

    static CSceneListManager* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSceneListManager>(iIndex);
    }

    static CSceneListManager* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
