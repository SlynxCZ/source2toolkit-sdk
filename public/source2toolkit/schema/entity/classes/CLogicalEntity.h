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

class CLogicalEntity : public CServerOnlyEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicalEntity);


public:
    static CLogicalEntity* New(const char* className)
    {
        return CBaseEntity::New<CLogicalEntity>(className);
    }

    static CLogicalEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicalEntity>(iIndex);
    }

    static CLogicalEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
