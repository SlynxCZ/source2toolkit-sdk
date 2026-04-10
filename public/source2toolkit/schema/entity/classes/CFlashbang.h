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

class CFlashbang : public CBaseCSGrenade
{
public:
    DECLARE_SCHEMA_CLASS(CFlashbang);


public:
    static CFlashbang* New(const char* className)
    {
        return CBaseEntity::New<CFlashbang>(className);
    }

    static CFlashbang* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFlashbang>(iIndex);
    }

    static CFlashbang* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
