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

#include "CBaseEntity.h"

class CServerOnlyEntity : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CServerOnlyEntity);


public:
    static CServerOnlyEntity* New(const char* className)
    {
        return CBaseEntity::New<CServerOnlyEntity>(className);
    }

    static CServerOnlyEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CServerOnlyEntity>(iIndex);
    }

    static CServerOnlyEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
