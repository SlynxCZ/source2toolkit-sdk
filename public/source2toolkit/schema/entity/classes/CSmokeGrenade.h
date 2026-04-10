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

class CSmokeGrenade : public CBaseCSGrenade
{
public:
    DECLARE_SCHEMA_CLASS(CSmokeGrenade);


public:
    static CSmokeGrenade* New(const char* className)
    {
        return CBaseEntity::New<CSmokeGrenade>(className);
    }

    static CSmokeGrenade* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSmokeGrenade>(iIndex);
    }

    static CSmokeGrenade* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
