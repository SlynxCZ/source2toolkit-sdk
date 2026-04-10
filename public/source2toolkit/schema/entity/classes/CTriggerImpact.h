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

#include "CTriggerMultiple.h"

class CTriggerImpact : public CTriggerMultiple
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerImpact);

    SCHEMA_FIELD(float, m_flMagnitude);
    SCHEMA_FIELD(float, m_flNoise);
    SCHEMA_FIELD(float, m_flViewkick);

public:
    static CTriggerImpact* New(const char* className)
    {
        return CBaseEntity::New<CTriggerImpact>(className);
    }

    static CTriggerImpact* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerImpact>(iIndex);
    }

    static CTriggerImpact* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
