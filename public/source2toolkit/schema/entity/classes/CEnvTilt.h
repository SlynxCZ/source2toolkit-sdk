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

class CEnvTilt : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvTilt);

    SCHEMA_FIELD(float, m_Duration);
    SCHEMA_FIELD(float, m_Radius);
    SCHEMA_FIELD(float, m_TiltTime);
    SCHEMA_FIELD(float, m_stopTime);

public:
    static CEnvTilt* New(const char* className)
    {
        return CBaseEntity::New<CEnvTilt>(className);
    }

    static CEnvTilt* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvTilt>(iIndex);
    }

    static CEnvTilt* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
