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

class CBaseFilter : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBaseFilter);

    SCHEMA_FIELD(bool, m_bNegated);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPass);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFail);

public:
    static CBaseFilter* New(const char* className)
    {
        return CBaseEntity::New<CBaseFilter>(className);
    }

    static CBaseFilter* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseFilter>(iIndex);
    }

    static CBaseFilter* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
