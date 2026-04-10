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

class CTriggerGameEvent : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerGameEvent);

    SCHEMA_FIELD(CUtlString, m_strStartTouchEventName);
    SCHEMA_FIELD(CUtlString, m_strEndTouchEventName);
    SCHEMA_FIELD(CUtlString, m_strTriggerID);

public:
    static CTriggerGameEvent* New(const char* className)
    {
        return CBaseEntity::New<CTriggerGameEvent>(className);
    }

    static CTriggerGameEvent* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerGameEvent>(iIndex);
    }

    static CTriggerGameEvent* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
