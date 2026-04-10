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

#include "CBaseEntity.h"

class CDebugHistory : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CDebugHistory);

    SCHEMA_FIELD(int32_t, m_nNpcEvents);

public:
    static CDebugHistory* New(const char* className)
    {
        return CBaseEntity::New<CDebugHistory>(className);
    }

    static CDebugHistory* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDebugHistory>(iIndex);
    }

    static CDebugHistory* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
