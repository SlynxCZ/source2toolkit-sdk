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

class CEnvDetailController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvDetailController);

    SCHEMA_FIELD(float, m_flFadeStartDist);
    SCHEMA_FIELD(float, m_flFadeEndDist);

public:
    static CEnvDetailController* New(const char* className)
    {
        return CBaseEntity::New<CEnvDetailController>(className);
    }

    static CEnvDetailController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvDetailController>(iIndex);
    }

    static CEnvDetailController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
