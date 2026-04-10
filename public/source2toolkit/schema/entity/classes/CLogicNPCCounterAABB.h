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

#include "CLogicNPCCounter.h"

class CLogicNPCCounterAABB : public CLogicNPCCounter
{
public:
    DECLARE_SCHEMA_CLASS(CLogicNPCCounterAABB);

    SCHEMA_FIELD(Vector, m_vDistanceOuterMins);
    SCHEMA_FIELD(Vector, m_vDistanceOuterMaxs);
    SCHEMA_FIELD(Vector, m_vOuterMins);
    SCHEMA_FIELD(Vector, m_vOuterMaxs);

public:
    static CLogicNPCCounterAABB* New(const char* className)
    {
        return CBaseEntity::New<CLogicNPCCounterAABB>(className);
    }

    static CLogicNPCCounterAABB* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicNPCCounterAABB>(iIndex);
    }

    static CLogicNPCCounterAABB* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
