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

#include "CBaseModelEntity.h"
#include "CBuoyancyHelper.h"

class CFuncWater : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncWater);

    SCHEMA_FIELD(CBuoyancyHelper, m_BuoyancyHelper);

public:
    static CFuncWater* New(const char* className)
    {
        return CBaseEntity::New<CFuncWater>(className);
    }

    static CFuncWater* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncWater>(iIndex);
    }

    static CFuncWater* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
