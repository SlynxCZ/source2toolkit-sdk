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

#include "CServerOnlyPointEntity.h"

class CPointPrefab : public CServerOnlyPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointPrefab);

    SCHEMA_FIELD(CUtlSymbolLarge, m_targetMapName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_forceWorldGroupID);
    SCHEMA_FIELD(CUtlSymbolLarge, m_associatedRelayTargetName);
    SCHEMA_FIELD(bool, m_fixupNames);
    SCHEMA_FIELD(bool, m_bLoadDynamic);
    SCHEMA_FIELD(CHandle<CPointPrefab>, m_associatedRelayEntity);

public:
    static CPointPrefab* New(const char* className)
    {
        return CBaseEntity::New<CPointPrefab>(className);
    }

    static CPointPrefab* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointPrefab>(iIndex);
    }

    static CPointPrefab* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
