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

#include "CServerOnlyPointEntity.h"

class CInfoTargetServerOnly : public CServerOnlyPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoTargetServerOnly);


public:
    static CInfoTargetServerOnly* New(const char* className)
    {
        return CBaseEntity::New<CInfoTargetServerOnly>(className);
    }

    static CInfoTargetServerOnly* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoTargetServerOnly>(iIndex);
    }

    static CInfoTargetServerOnly* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
