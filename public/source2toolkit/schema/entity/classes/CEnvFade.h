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

class CEnvFade : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvFade);

    SCHEMA_FIELD(Color, m_fadeColor);
    SCHEMA_FIELD(float, m_Duration);
    SCHEMA_FIELD(float, m_HoldDuration);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBeginFade);

public:
    static CEnvFade* New(const char* className)
    {
        return CBaseEntity::New<CEnvFade>(className);
    }

    static CEnvFade* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvFade>(iIndex);
    }

    static CEnvFade* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
