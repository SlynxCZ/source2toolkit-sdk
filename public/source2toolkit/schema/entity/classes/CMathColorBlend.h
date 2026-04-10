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

#include "CLogicalEntity.h"

class CMathColorBlend : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CMathColorBlend);

    SCHEMA_FIELD(float, m_flInMin);
    SCHEMA_FIELD(float, m_flInMax);
    SCHEMA_FIELD(Color, m_OutColor1);
    SCHEMA_FIELD(Color, m_OutColor2);

public:
    static CMathColorBlend* New(const char* className)
    {
        return CBaseEntity::New<CMathColorBlend>(className);
    }

    static CMathColorBlend* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMathColorBlend>(iIndex);
    }

    static CMathColorBlend* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
