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

class CFilterClass : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterClass);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterClass);

public:
    static CFilterClass* New(const char* className)
    {
        return CBaseEntity::New<CFilterClass>(className);
    }

    static CFilterClass* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterClass>(iIndex);
    }

    static CFilterClass* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
