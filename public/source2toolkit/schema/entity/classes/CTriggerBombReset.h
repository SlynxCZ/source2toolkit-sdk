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

class CTriggerBombReset : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerBombReset);


public:
    static CTriggerBombReset* New(const char* className)
    {
        return CBaseEntity::New<CTriggerBombReset>(className);
    }

    static CTriggerBombReset* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerBombReset>(iIndex);
    }

    static CTriggerBombReset* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
