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

class CHandleDummy : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CHandleDummy);


public:
    static CHandleDummy* New(const char* className)
    {
        return CBaseEntity::New<CHandleDummy>(className);
    }

    static CHandleDummy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHandleDummy>(iIndex);
    }

    static CHandleDummy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
