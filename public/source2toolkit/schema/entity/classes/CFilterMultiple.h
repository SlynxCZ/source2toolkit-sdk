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
#include "../enums/filter_t.h"

class CBaseEntity;

class CFilterMultiple : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterMultiple);

    SCHEMA_FIELD(filter_t, m_nFilterType);
    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_iFilterName);
    SCHEMA_FIELD_POINTER(CHandle<CBaseEntity>, m_hFilter);

public:
    static CFilterMultiple* New(const char* className)
    {
        return CBaseEntity::New<CFilterMultiple>(className);
    }

    static CFilterMultiple* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterMultiple>(iIndex);
    }

    static CFilterMultiple* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
