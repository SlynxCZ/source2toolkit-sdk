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

class CEnvViewPunch : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvViewPunch);

    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(QAngle, m_angViewPunch);

public:
    static CEnvViewPunch* New(const char* className)
    {
        return CBaseEntity::New<CEnvViewPunch>(className);
    }

    static CEnvViewPunch* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvViewPunch>(iIndex);
    }

    static CEnvViewPunch* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
