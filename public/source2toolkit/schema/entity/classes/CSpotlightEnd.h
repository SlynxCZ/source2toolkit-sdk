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

#include "CBaseModelEntity.h"

class CSpotlightEnd : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSpotlightEnd);

    SCHEMA_FIELD(float, m_flLightScale);
    SCHEMA_FIELD(float, m_Radius);
    SCHEMA_FIELD(Vector, m_vSpotlightDir);
    SCHEMA_FIELD(Vector, m_vSpotlightOrg);

public:
    static CSpotlightEnd* New(const char* className)
    {
        return CBaseEntity::New<CSpotlightEnd>(className);
    }

    static CSpotlightEnd* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSpotlightEnd>(iIndex);
    }

    static CSpotlightEnd* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
