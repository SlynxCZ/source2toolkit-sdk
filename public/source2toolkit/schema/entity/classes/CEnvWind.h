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
#include "CEnvWindShared.h"

class CEnvWind : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvWind);

    SCHEMA_FIELD(CEnvWindShared, m_EnvWindShared);

public:
    static CEnvWind* New(const char* className)
    {
        return CBaseEntity::New<CEnvWind>(className);
    }

    static CEnvWind* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvWind>(iIndex);
    }

    static CEnvWind* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
