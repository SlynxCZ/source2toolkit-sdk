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

class CEnvEntityIgniter : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvEntityIgniter);

    SCHEMA_FIELD(float, m_flLifetime);

public:
    static CEnvEntityIgniter* New(const char* className)
    {
        return CBaseEntity::New<CEnvEntityIgniter>(className);
    }

    static CEnvEntityIgniter* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvEntityIgniter>(iIndex);
    }

    static CEnvEntityIgniter* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
