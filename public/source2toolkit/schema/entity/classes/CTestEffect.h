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

class CBeam;

class CTestEffect : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTestEffect);

    SCHEMA_FIELD(int32_t, m_iLoop);
    SCHEMA_FIELD(int32_t, m_iBeam);
    SCHEMA_FIELD_POINTER(CHandle<CBeam>, m_pBeam);
    SCHEMA_FIELD_POINTER(float, m_flBeamTime);
    SCHEMA_FIELD(float, m_flStartTime);

public:
    static CTestEffect* New(const char* className)
    {
        return CBaseEntity::New<CTestEffect>(className);
    }

    static CTestEffect* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTestEffect>(iIndex);
    }

    static CTestEffect* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
