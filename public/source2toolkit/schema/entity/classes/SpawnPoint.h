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

class SpawnPoint : public CServerOnlyPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(SpawnPoint);

    SCHEMA_FIELD(int32_t, m_iPriority);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(int32_t, m_nType);

public:
    static SpawnPoint* New(const char* className)
    {
        return CBaseEntity::New<SpawnPoint>(className);
    }

    static SpawnPoint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<SpawnPoint>(iIndex);
    }

    static SpawnPoint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
