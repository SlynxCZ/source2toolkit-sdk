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
#include "CountdownTimer.h"

class CFish;

class CFishPool : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFishPool);

    SCHEMA_FIELD(int32_t, m_fishCount);
    SCHEMA_FIELD(float, m_maxRange);
    SCHEMA_FIELD(float, m_swimDepth);
    SCHEMA_FIELD(float, m_waterLevel);
    SCHEMA_FIELD(bool, m_isDormant);
    SCHEMA_FIELD(CUtlVector<CHandle<CFish>>, m_fishes);
    SCHEMA_FIELD(CountdownTimer, m_visTimer);

public:
    static CFishPool* New(const char* className)
    {
        return CBaseEntity::New<CFishPool>(className);
    }

    static CFishPool* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFishPool>(iIndex);
    }

    static CFishPool* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
