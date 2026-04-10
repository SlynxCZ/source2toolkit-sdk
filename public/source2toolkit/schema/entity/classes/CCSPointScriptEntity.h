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

class CCSPointScriptEntity : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCSPointScriptEntity);


public:
    static CCSPointScriptEntity* New(const char* className)
    {
        return CBaseEntity::New<CCSPointScriptEntity>(className);
    }

    static CCSPointScriptEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPointScriptEntity>(iIndex);
    }

    static CCSPointScriptEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
