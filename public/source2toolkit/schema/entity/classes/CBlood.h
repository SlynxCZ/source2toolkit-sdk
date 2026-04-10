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

#include "../enums/BloodType.h"
#include "CPointEntity.h"

class CBlood : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBlood);

    SCHEMA_FIELD(QAngle, m_vecSprayAngles);
    SCHEMA_FIELD(Vector, m_vecSprayDir);
    SCHEMA_FIELD(float, m_flAmount);
    SCHEMA_FIELD(BloodType, m_Color);

public:
    static CBlood* New(const char* className)
    {
        return CBaseEntity::New<CBlood>(className);
    }

    static CBlood* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBlood>(iIndex);
    }

    static CBlood* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
