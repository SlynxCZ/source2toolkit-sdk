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

class CBaseFilter;

class CPointPush : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointPush);

    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(float, m_flMagnitude);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(float, m_flInnerRadius);
    SCHEMA_FIELD(float, m_flConeOfInfluence);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszFilterName);
    SCHEMA_FIELD(CHandle<CBaseFilter>, m_hFilter);

public:
    static CPointPush* New(const char* className)
    {
        return CBaseEntity::New<CPointPush>(className);
    }

    static CPointPush* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointPush>(iIndex);
    }

    static CPointPush* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
