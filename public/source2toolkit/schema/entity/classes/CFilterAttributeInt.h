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

class CFilterAttributeInt : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterAttributeInt);

    SCHEMA_FIELD(CUtlSymbolLarge, m_sAttributeName);

public:
    static CFilterAttributeInt* New(const char* className)
    {
        return CBaseEntity::New<CFilterAttributeInt>(className);
    }

    static CFilterAttributeInt* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterAttributeInt>(iIndex);
    }

    static CFilterAttributeInt* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
