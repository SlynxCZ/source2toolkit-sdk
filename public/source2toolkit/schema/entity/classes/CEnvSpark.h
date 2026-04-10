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

class CEnvSpark : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSpark);

    SCHEMA_FIELD(float, m_flDelay);
    SCHEMA_FIELD(int32_t, m_nMagnitude);
    SCHEMA_FIELD(int32_t, m_nTrailLength);
    SCHEMA_FIELD(int32_t, m_nType);
    SCHEMA_FIELD(CEntityIOOutput, m_OnSpark);

public:
    static CEnvSpark* New(const char* className)
    {
        return CBaseEntity::New<CEnvSpark>(className);
    }

    static CEnvSpark* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSpark>(iIndex);
    }

    static CEnvSpark* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
