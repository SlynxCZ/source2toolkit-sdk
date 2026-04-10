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

#include "CServerOnlyModelEntity.h"

class CCSPlace : public CServerOnlyModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlace);

    SCHEMA_FIELD(CUtlSymbolLarge, m_name);

public:
    static CCSPlace* New(const char* className)
    {
        return CBaseEntity::New<CCSPlace>(className);
    }

    static CCSPlace* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPlace>(iIndex);
    }

    static CCSPlace* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
