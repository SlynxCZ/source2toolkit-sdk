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

#include "CServerOnlyEntity.h"

class CServerOnlyPointEntity : public CServerOnlyEntity
{
public:
    DECLARE_SCHEMA_CLASS(CServerOnlyPointEntity);


public:
    static CServerOnlyPointEntity* New(const char* className)
    {
        return CBaseEntity::New<CServerOnlyPointEntity>(className);
    }

    static CServerOnlyPointEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CServerOnlyPointEntity>(iIndex);
    }

    static CServerOnlyPointEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
