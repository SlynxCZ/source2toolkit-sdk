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

class CBaseDMStart : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBaseDMStart);

    SCHEMA_FIELD(CUtlSymbolLarge, m_Master);

public:
    static CBaseDMStart* New(const char* className)
    {
        return CBaseEntity::New<CBaseDMStart>(className);
    }

    static CBaseDMStart* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseDMStart>(iIndex);
    }

    static CBaseDMStart* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
