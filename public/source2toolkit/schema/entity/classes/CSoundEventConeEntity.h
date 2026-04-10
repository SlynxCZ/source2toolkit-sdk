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

#include "CSoundEventEntity.h"

class CSoundEventConeEntity : public CSoundEventEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventConeEntity);

    SCHEMA_FIELD(float, m_flEmitterAngle);
    SCHEMA_FIELD(float, m_flSweetSpotAngle);
    SCHEMA_FIELD(float, m_flAttenMin);
    SCHEMA_FIELD(float, m_flAttenMax);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszParameterName);

public:
    static CSoundEventConeEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventConeEntity>(className);
    }

    static CSoundEventConeEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventConeEntity>(iIndex);
    }

    static CSoundEventConeEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
