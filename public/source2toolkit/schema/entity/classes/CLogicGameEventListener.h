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

#include "CLogicalEntity.h"

class CLogicGameEventListener : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicGameEventListener);

    SCHEMA_FIELD(CEntityIOOutput, m_OnEventFired);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszGameEventName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszGameEventItem);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(bool, m_bStartDisabled);

public:
    static CLogicGameEventListener* New(const char* className)
    {
        return CBaseEntity::New<CLogicGameEventListener>(className);
    }

    static CLogicGameEventListener* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicGameEventListener>(iIndex);
    }

    static CLogicGameEventListener* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
