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

class CNullEntity : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CNullEntity);


public:
    static CNullEntity* New(const char* className)
    {
        return CBaseEntity::New<CNullEntity>(className);
    }

    static CNullEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CNullEntity>(iIndex);
    }

    static CNullEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
