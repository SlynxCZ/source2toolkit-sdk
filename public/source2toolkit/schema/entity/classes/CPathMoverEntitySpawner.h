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

class CPathMover;

class CPathMoverEntitySpawner : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathMoverEntitySpawner);

    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_szSpawnTemplates);
    SCHEMA_FIELD(int32_t, m_nSpawnIndex);
    SCHEMA_FIELD(CHandle<CPathMover>, m_hPathMover);
    SCHEMA_FIELD(float, m_flSpawnFrequencySeconds);
    SCHEMA_FIELD(float, m_flSpawnFrequencyDistToNearestMover);
    SCHEMA_FIELD(int32_t, m_nMaxActive);
    SCHEMA_FIELD(float, m_flLastSpawnTime);
    SCHEMA_FIELD(bool, m_bEnabled);

public:
    static CPathMoverEntitySpawner* New(const char* className)
    {
        return CBaseEntity::New<CPathMoverEntitySpawner>(className);
    }

    static CPathMoverEntitySpawner* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathMoverEntitySpawner>(iIndex);
    }

    static CPathMoverEntitySpawner* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
