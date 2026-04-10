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

class CFilterModel : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterModel);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterModel);

public:
    static CFilterModel* New(const char* className)
    {
        return CBaseEntity::New<CFilterModel>(className);
    }

    static CFilterModel* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterModel>(iIndex);
    }

    static CFilterModel* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
