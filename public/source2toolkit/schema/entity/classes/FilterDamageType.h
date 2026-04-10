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

class FilterDamageType : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(FilterDamageType);

    SCHEMA_FIELD(int32_t, m_iDamageType);

public:
    static FilterDamageType* New(const char* className)
    {
        return CBaseEntity::New<FilterDamageType>(className);
    }

    static FilterDamageType* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<FilterDamageType>(iIndex);
    }

    static FilterDamageType* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
