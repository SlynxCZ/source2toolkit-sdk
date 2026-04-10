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

class CEnvGlobal : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvGlobal);

    SCHEMA_FIELD(CUtlSymbolLarge, m_globalstate);
    SCHEMA_FIELD(int32_t, m_triggermode);
    SCHEMA_FIELD(int32_t, m_initialstate);
    SCHEMA_FIELD(int32_t, m_counter);

public:
    static CEnvGlobal* New(const char* className)
    {
        return CBaseEntity::New<CEnvGlobal>(className);
    }

    static CEnvGlobal* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvGlobal>(iIndex);
    }

    static CEnvGlobal* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
