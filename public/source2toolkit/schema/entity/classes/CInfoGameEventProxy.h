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

#include "CPointEntity.h"

class CInfoGameEventProxy : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoGameEventProxy);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEventName);
    SCHEMA_FIELD(float, m_flRange);

public:
    static CInfoGameEventProxy* New(const char* className)
    {
        return CBaseEntity::New<CInfoGameEventProxy>(className);
    }

    static CInfoGameEventProxy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoGameEventProxy>(iIndex);
    }

    static CInfoGameEventProxy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
