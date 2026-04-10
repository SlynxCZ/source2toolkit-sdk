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
#include "InfoForResourceTypeIMaterial2.h"

class CEnvDecal : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvDecal);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hDecalMaterial);
    SCHEMA_FIELD(float, m_flWidth);
    SCHEMA_FIELD(float, m_flHeight);
    SCHEMA_FIELD(float, m_flDepth);
    SCHEMA_FIELD(uint32_t, m_nRenderOrder);
    SCHEMA_FIELD(bool, m_bProjectOnWorld);
    SCHEMA_FIELD(bool, m_bProjectOnCharacters);
    SCHEMA_FIELD(bool, m_bProjectOnWater);
    SCHEMA_FIELD(float, m_flDepthSortBias);

public:
    static CEnvDecal* New(const char* className)
    {
        return CBaseEntity::New<CEnvDecal>(className);
    }

    static CEnvDecal* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvDecal>(iIndex);
    }

    static CEnvDecal* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
