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

#include "CBaseModelEntity.h"

class CEntityBlocker : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEntityBlocker);


public:
    static CEntityBlocker* New(const char* className)
    {
        return CBaseEntity::New<CEntityBlocker>(className);
    }

    static CEntityBlocker* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEntityBlocker>(iIndex);
    }

    static CEntityBlocker* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
