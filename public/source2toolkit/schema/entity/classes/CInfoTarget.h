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

class CInfoTarget : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoTarget);


public:
    static CInfoTarget* New(const char* className)
    {
        return CBaseEntity::New<CInfoTarget>(className);
    }

    static CInfoTarget* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoTarget>(iIndex);
    }

    static CInfoTarget* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
