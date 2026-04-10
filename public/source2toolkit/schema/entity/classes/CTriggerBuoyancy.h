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

#include "CBaseTrigger.h"
#include "CBuoyancyHelper.h"

class CTriggerBuoyancy : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerBuoyancy);

    SCHEMA_FIELD(CBuoyancyHelper, m_BuoyancyHelper);
    SCHEMA_FIELD(float, m_flFluidDensity);

public:
    static CTriggerBuoyancy* New(const char* className)
    {
        return CBaseEntity::New<CTriggerBuoyancy>(className);
    }

    static CTriggerBuoyancy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerBuoyancy>(iIndex);
    }

    static CTriggerBuoyancy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
