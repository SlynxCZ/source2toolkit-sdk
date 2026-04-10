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

class CBaseEntity;

class CTriggerProximity : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerProximity);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hMeasureTarget);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszMeasureTarget);
    SCHEMA_FIELD(float, m_fRadius);
    SCHEMA_FIELD(int32_t, m_nTouchers);

public:
    static CTriggerProximity* New(const char* className)
    {
        return CBaseEntity::New<CTriggerProximity>(className);
    }

    static CTriggerProximity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerProximity>(iIndex);
    }

    static CTriggerProximity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
