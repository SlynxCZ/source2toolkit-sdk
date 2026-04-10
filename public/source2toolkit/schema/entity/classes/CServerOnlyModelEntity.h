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

class CServerOnlyModelEntity : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CServerOnlyModelEntity);


public:
    static CServerOnlyModelEntity* New(const char* className)
    {
        return CBaseEntity::New<CServerOnlyModelEntity>(className);
    }

    static CServerOnlyModelEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CServerOnlyModelEntity>(iIndex);
    }

    static CServerOnlyModelEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
