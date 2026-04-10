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

class CEnvMuzzleFlash : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvMuzzleFlash);

    SCHEMA_FIELD(float, m_flScale);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszParentAttachment);

public:
    static CEnvMuzzleFlash* New(const char* className)
    {
        return CBaseEntity::New<CEnvMuzzleFlash>(className);
    }

    static CEnvMuzzleFlash* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvMuzzleFlash>(iIndex);
    }

    static CEnvMuzzleFlash* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
