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

#include "CBaseTrigger.h"

class CTriggerCallback : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerCallback);


public:
    static CTriggerCallback* New(const char* className)
    {
        return CBaseEntity::New<CTriggerCallback>(className);
    }

    static CTriggerCallback* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerCallback>(iIndex);
    }

    static CTriggerCallback* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
