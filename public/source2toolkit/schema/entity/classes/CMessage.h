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

#include "CPointEntity.h"

class CMessage : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CMessage);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszMessage);
    SCHEMA_FIELD(float, m_MessageVolume);
    SCHEMA_FIELD(int32_t, m_MessageAttenuation);
    SCHEMA_FIELD(float, m_Radius);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sNoise);
    SCHEMA_FIELD(CEntityIOOutput, m_OnShowMessage);

public:
    static CMessage* New(const char* className)
    {
        return CBaseEntity::New<CMessage>(className);
    }

    static CMessage* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMessage>(iIndex);
    }

    static CMessage* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
