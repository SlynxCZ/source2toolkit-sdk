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

class CTriggerRemove : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerRemove);

    SCHEMA_FIELD(CEntityIOOutput, m_OnRemove);

public:
    static CTriggerRemove* New(const char* className)
    {
        return CBaseEntity::New<CTriggerRemove>(className);
    }

    static CTriggerRemove* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerRemove>(iIndex);
    }

    static CTriggerRemove* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
