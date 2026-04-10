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

class CLogicGameEvent : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicGameEvent);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEventName);

public:
    static CLogicGameEvent* New(const char* className)
    {
        return CBaseEntity::New<CLogicGameEvent>(className);
    }

    static CLogicGameEvent* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicGameEvent>(iIndex);
    }

    static CLogicGameEvent* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
