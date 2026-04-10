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

class CBaseEntity;

class CPointProximitySensor : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointProximitySensor);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetEntity);

public:
    static CPointProximitySensor* New(const char* className)
    {
        return CBaseEntity::New<CPointProximitySensor>(className);
    }

    static CPointProximitySensor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointProximitySensor>(iIndex);
    }

    static CPointProximitySensor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
