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

class CLogicCompare : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicCompare);

    SCHEMA_FIELD(float, m_flInValue);
    SCHEMA_FIELD(float, m_flCompareValue);

public:
    static CLogicCompare* New(const char* className)
    {
        return CBaseEntity::New<CLogicCompare>(className);
    }

    static CLogicCompare* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicCompare>(iIndex);
    }

    static CLogicCompare* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
