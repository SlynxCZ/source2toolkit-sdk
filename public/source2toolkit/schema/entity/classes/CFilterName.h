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

class CFilterName : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterName);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterName);

public:
    static CFilterName* New(const char* className)
    {
        return CBaseEntity::New<CFilterName>(className);
    }

    static CFilterName* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterName>(iIndex);
    }

    static CFilterName* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
