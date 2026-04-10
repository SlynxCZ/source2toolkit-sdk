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

class CPlayerVisibility : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPlayerVisibility);

    SCHEMA_FIELD(float, m_flVisibilityStrength);
    SCHEMA_FIELD(float, m_flFogDistanceMultiplier);
    SCHEMA_FIELD(float, m_flFogMaxDensityMultiplier);
    SCHEMA_FIELD(float, m_flFadeTime);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(bool, m_bIsEnabled);

public:
    static CPlayerVisibility* New(const char* className)
    {
        return CBaseEntity::New<CPlayerVisibility>(className);
    }

    static CPlayerVisibility* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPlayerVisibility>(iIndex);
    }

    static CPlayerVisibility* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
