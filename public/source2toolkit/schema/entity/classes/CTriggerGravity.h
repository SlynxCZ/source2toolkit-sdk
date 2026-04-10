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

class CTriggerGravity : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerGravity);


public:
    static CTriggerGravity* New(const char* className)
    {
        return CBaseEntity::New<CTriggerGravity>(className);
    }

    static CTriggerGravity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerGravity>(iIndex);
    }

    static CTriggerGravity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
