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

class CFilterLOS : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterLOS);


public:
    static CFilterLOS* New(const char* className)
    {
        return CBaseEntity::New<CFilterLOS>(className);
    }

    static CFilterLOS* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterLOS>(iIndex);
    }

    static CFilterLOS* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
