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

class CFilterProximity : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterProximity);

    SCHEMA_FIELD(float, m_flRadius);

public:
    static CFilterProximity* New(const char* className)
    {
        return CBaseEntity::New<CFilterProximity>(className);
    }

    static CFilterProximity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterProximity>(iIndex);
    }

    static CFilterProximity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
