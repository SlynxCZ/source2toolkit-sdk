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

#include "CParticleSystem.h"
#include "InfoForResourceTypeCTextureBase.h"

class CEnvParticleGlow : public CParticleSystem
{
public:
    DECLARE_SCHEMA_CLASS(CEnvParticleGlow);

    SCHEMA_FIELD(float, m_flAlphaScale);
    SCHEMA_FIELD(float, m_flRadiusScale);
    SCHEMA_FIELD(float, m_flSelfIllumScale);
    SCHEMA_FIELD(Color, m_ColorTint);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hTextureOverride);

public:
    static CEnvParticleGlow* New(const char* className)
    {
        return CBaseEntity::New<CEnvParticleGlow>(className);
    }

    static CEnvParticleGlow* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvParticleGlow>(iIndex);
    }

    static CEnvParticleGlow* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
