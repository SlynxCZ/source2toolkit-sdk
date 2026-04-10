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

#include "CBaseFilter.h"

class CFilterEnemy : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterEnemy);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEnemyName);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(float, m_flOuterRadius);
    SCHEMA_FIELD(int32_t, m_nMaxSquadmatesPerEnemy);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPlayerName);

public:
    static CFilterEnemy* New(const char* className)
    {
        return CBaseEntity::New<CFilterEnemy>(className);
    }

    static CFilterEnemy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterEnemy>(iIndex);
    }

    static CFilterEnemy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
