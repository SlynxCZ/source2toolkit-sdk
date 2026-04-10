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

#include "CPointEntity.h"

class CPointGamestatsCounter : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointGamestatsCounter);

    SCHEMA_FIELD(CUtlSymbolLarge, m_strStatisticName);
    SCHEMA_FIELD(bool, m_bDisabled);

public:
    static CPointGamestatsCounter* New(const char* className)
    {
        return CBaseEntity::New<CPointGamestatsCounter>(className);
    }

    static CPointGamestatsCounter* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointGamestatsCounter>(iIndex);
    }

    static CPointGamestatsCounter* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
