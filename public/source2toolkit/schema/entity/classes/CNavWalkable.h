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

class CNavWalkable : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CNavWalkable);


public:
    static CNavWalkable* New(const char* className)
    {
        return CBaseEntity::New<CNavWalkable>(className);
    }

    static CNavWalkable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CNavWalkable>(iIndex);
    }

    static CNavWalkable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
