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

class CLogicEventListener : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicEventListener);

    SCHEMA_FIELD(CUtlString, m_strEventName);
    SCHEMA_FIELD(bool, m_bIsEnabled);
    SCHEMA_FIELD(int32_t, m_nTeam);

public:
    static CLogicEventListener* New(const char* className)
    {
        return CBaseEntity::New<CLogicEventListener>(className);
    }

    static CLogicEventListener* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicEventListener>(iIndex);
    }

    static CLogicEventListener* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
