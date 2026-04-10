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

#include "CTriggerMultiple.h"

class CTriggerOnce : public CTriggerMultiple
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerOnce);


public:
    static CTriggerOnce* New(const char* className)
    {
        return CBaseEntity::New<CTriggerOnce>(className);
    }

    static CTriggerOnce* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerOnce>(iIndex);
    }

    static CTriggerOnce* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
