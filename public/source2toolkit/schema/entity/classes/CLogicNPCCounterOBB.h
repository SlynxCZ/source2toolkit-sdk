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

#include "CLogicNPCCounterAABB.h"

class CLogicNPCCounterOBB : public CLogicNPCCounterAABB
{
public:
    DECLARE_SCHEMA_CLASS(CLogicNPCCounterOBB);


public:
    static CLogicNPCCounterOBB* New(const char* className)
    {
        return CBaseEntity::New<CLogicNPCCounterOBB>(className);
    }

    static CLogicNPCCounterOBB* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicNPCCounterOBB>(iIndex);
    }

    static CLogicNPCCounterOBB* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
