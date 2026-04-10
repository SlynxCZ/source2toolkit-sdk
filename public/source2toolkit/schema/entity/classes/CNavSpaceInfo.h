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

#include "CPointEntity.h"

class CNavSpaceInfo : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CNavSpaceInfo);


public:
    static CNavSpaceInfo* New(const char* className)
    {
        return CBaseEntity::New<CNavSpaceInfo>(className);
    }

    static CNavSpaceInfo* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CNavSpaceInfo>(iIndex);
    }

    static CNavSpaceInfo* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
