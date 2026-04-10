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

class CEnvHudHint : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvHudHint);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszMessage);

public:
    static CEnvHudHint* New(const char* className)
    {
        return CBaseEntity::New<CEnvHudHint>(className);
    }

    static CEnvHudHint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvHudHint>(iIndex);
    }

    static CEnvHudHint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
