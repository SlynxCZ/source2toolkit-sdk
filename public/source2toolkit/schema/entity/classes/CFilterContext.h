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

class CFilterContext : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterContext);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterContext);

public:
    static CFilterContext* New(const char* className)
    {
        return CBaseEntity::New<CFilterContext>(className);
    }

    static CFilterContext* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterContext>(iIndex);
    }

    static CFilterContext* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
