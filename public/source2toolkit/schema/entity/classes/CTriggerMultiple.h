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

class CTriggerMultiple : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerMultiple);

    SCHEMA_FIELD(CEntityIOOutput, m_OnTrigger);

public:
    static CTriggerMultiple* New(const char* className)
    {
        return CBaseEntity::New<CTriggerMultiple>(className);
    }

    static CTriggerMultiple* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerMultiple>(iIndex);
    }

    static CTriggerMultiple* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
