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

class CInfoFan : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoFan);

    SCHEMA_FIELD(float, m_fFanForceMaxRadius);
    SCHEMA_FIELD(float, m_fFanForceMinRadius);
    SCHEMA_FIELD(float, m_flCurveDistRange);
    SCHEMA_FIELD(CUtlSymbolLarge, m_FanForceCurveString);

public:
    static CInfoFan* New(const char* className)
    {
        return CBaseEntity::New<CInfoFan>(className);
    }

    static CInfoFan* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoFan>(iIndex);
    }

    static CInfoFan* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
