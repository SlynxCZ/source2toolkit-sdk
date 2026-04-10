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

#include "CBaseEntity.h"

class CInfoWorldLayer : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoWorldLayer);

    SCHEMA_FIELD(CEntityIOOutput, m_pOutputOnEntitiesSpawned);
    SCHEMA_FIELD(CUtlSymbolLarge, m_worldName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_layerName);
    SCHEMA_FIELD(bool, m_bWorldLayerVisible);
    SCHEMA_FIELD(bool, m_bEntitiesSpawned);
    SCHEMA_FIELD(bool, m_bCreateAsChildSpawnGroup);
    SCHEMA_FIELD(uint32_t, m_hLayerSpawnGroup);

public:
    static CInfoWorldLayer* New(const char* className)
    {
        return CBaseEntity::New<CInfoWorldLayer>(className);
    }

    static CInfoWorldLayer* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoWorldLayer>(iIndex);
    }

    static CInfoWorldLayer* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
