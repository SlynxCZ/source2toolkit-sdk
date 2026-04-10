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

#include "CBaseModelEntity.h"

class CWorld : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CWorld);


public:
    static CWorld* New(const char* className)
    {
        return CBaseEntity::New<CWorld>(className);
    }

    static CWorld* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWorld>(iIndex);
    }

    static CWorld* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
