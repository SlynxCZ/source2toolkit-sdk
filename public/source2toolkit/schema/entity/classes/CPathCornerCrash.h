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

#include "CPathCorner.h"

class CPathCornerCrash : public CPathCorner
{
public:
    DECLARE_SCHEMA_CLASS(CPathCornerCrash);


public:
    static CPathCornerCrash* New(const char* className)
    {
        return CBaseEntity::New<CPathCornerCrash>(className);
    }

    static CPathCornerCrash* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathCornerCrash>(iIndex);
    }

    static CPathCornerCrash* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
