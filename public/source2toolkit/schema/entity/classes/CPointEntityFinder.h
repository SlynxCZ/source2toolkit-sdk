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
#include "../enums/EntFinderMethod_t.h"

class CBaseFilter;

class CPointEntityFinder : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointEntityFinder);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEntity);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterName);
    SCHEMA_FIELD(CHandle<CBaseFilter>, m_hFilter);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iRefName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hReference);
    SCHEMA_FIELD(EntFinderMethod_t, m_FindMethod);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFoundEntity);

public:
    static CPointEntityFinder* New(const char* className)
    {
        return CBaseEntity::New<CPointEntityFinder>(className);
    }

    static CPointEntityFinder* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointEntityFinder>(iIndex);
    }

    static CPointEntityFinder* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
