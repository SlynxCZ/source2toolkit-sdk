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

#include "CBaseCSGrenade.h"

class CDecoyGrenade : public CBaseCSGrenade
{
public:
    DECLARE_SCHEMA_CLASS(CDecoyGrenade);


public:
    static CDecoyGrenade* New(const char* className)
    {
        return CBaseEntity::New<CDecoyGrenade>(className);
    }

    static CDecoyGrenade* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDecoyGrenade>(iIndex);
    }

    static CDecoyGrenade* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
