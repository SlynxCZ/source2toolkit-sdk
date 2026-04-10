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

class CInfoTeleportDestination : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoTeleportDestination);


public:
    static CInfoTeleportDestination* New(const char* className)
    {
        return CBaseEntity::New<CInfoTeleportDestination>(className);
    }

    static CInfoTeleportDestination* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoTeleportDestination>(iIndex);
    }

    static CInfoTeleportDestination* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
