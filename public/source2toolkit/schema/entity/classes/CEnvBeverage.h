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

class CEnvBeverage : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvBeverage);

    SCHEMA_FIELD(bool, m_CanInDispenser);
    SCHEMA_FIELD(int32_t, m_nBeverageType);

public:
    static CEnvBeverage* New(const char* className)
    {
        return CBaseEntity::New<CEnvBeverage>(className);
    }

    static CEnvBeverage* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvBeverage>(iIndex);
    }

    static CEnvBeverage* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
