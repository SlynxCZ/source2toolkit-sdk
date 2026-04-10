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

class CPointClientCommand : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointClientCommand);


public:
    static CPointClientCommand* New(const char* className)
    {
        return CBaseEntity::New<CPointClientCommand>(className);
    }

    static CPointClientCommand* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointClientCommand>(iIndex);
    }

    static CPointClientCommand* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
