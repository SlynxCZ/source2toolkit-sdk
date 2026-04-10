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

class FilterHealth : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(FilterHealth);

    SCHEMA_FIELD(bool, m_bAdrenalineActive);
    SCHEMA_FIELD(int32_t, m_iHealthMin);
    SCHEMA_FIELD(int32_t, m_iHealthMax);

public:
    static FilterHealth* New(const char* className)
    {
        return CBaseEntity::New<FilterHealth>(className);
    }

    static FilterHealth* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<FilterHealth>(iIndex);
    }

    static FilterHealth* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
