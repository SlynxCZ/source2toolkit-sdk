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

class CMapSharedEnvironment : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CMapSharedEnvironment);

    SCHEMA_FIELD(CUtlSymbolLarge, m_targetMapName);

public:
    static CMapSharedEnvironment* New(const char* className)
    {
        return CBaseEntity::New<CMapSharedEnvironment>(className);
    }

    static CMapSharedEnvironment* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMapSharedEnvironment>(iIndex);
    }

    static CMapSharedEnvironment* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
