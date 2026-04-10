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

class CPointVelocitySensor : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointVelocitySensor);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetEntity);
    SCHEMA_FIELD(Vector, m_vecAxis);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(float, m_fPrevVelocity);
    SCHEMA_FIELD(float, m_flAvgInterval);

public:
    static CPointVelocitySensor* New(const char* className)
    {
        return CBaseEntity::New<CPointVelocitySensor>(className);
    }

    static CPointVelocitySensor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointVelocitySensor>(iIndex);
    }

    static CPointVelocitySensor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
