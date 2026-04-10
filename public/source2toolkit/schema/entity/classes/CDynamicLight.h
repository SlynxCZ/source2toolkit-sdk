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

class CDynamicLight : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CDynamicLight);

    SCHEMA_FIELD(uint8_t, m_ActualFlags);
    SCHEMA_FIELD(uint8_t, m_Flags);
    SCHEMA_FIELD(uint8_t, m_LightStyle);
    SCHEMA_FIELD(bool, m_On);
    SCHEMA_FIELD(float, m_Radius);
    SCHEMA_FIELD(int32_t, m_Exponent);
    SCHEMA_FIELD(float, m_InnerAngle);
    SCHEMA_FIELD(float, m_OuterAngle);
    SCHEMA_FIELD(float, m_SpotRadius);

public:
    static CDynamicLight* New(const char* className)
    {
        return CBaseEntity::New<CDynamicLight>(className);
    }

    static CDynamicLight* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDynamicLight>(iIndex);
    }

    static CDynamicLight* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
