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
#include "InfoForResourceTypeCTextureBase.h"
#include "InfoForResourceTypeIMaterial2.h"

class CEnvCubemapFog : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvCubemapFog);

    SCHEMA_FIELD(float, m_flEndDistance);
    SCHEMA_FIELD(float, m_flStartDistance);
    SCHEMA_FIELD(float, m_flFogFalloffExponent);
    SCHEMA_FIELD(bool, m_bHeightFogEnabled);
    SCHEMA_FIELD(float, m_flFogHeightWidth);
    SCHEMA_FIELD(float, m_flFogHeightEnd);
    SCHEMA_FIELD(float, m_flFogHeightStart);
    SCHEMA_FIELD(float, m_flFogHeightExponent);
    SCHEMA_FIELD(float, m_flLODBias);
    SCHEMA_FIELD(bool, m_bActive);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(float, m_flFogMaxOpacity);
    SCHEMA_FIELD(int32_t, m_nCubemapSourceType);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hSkyMaterial);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSkyEntity);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hFogCubemapTexture);
    SCHEMA_FIELD(bool, m_bHasHeightFogEnd);
    SCHEMA_FIELD(bool, m_bFirstTime);

public:
    static CEnvCubemapFog* New(const char* className)
    {
        return CBaseEntity::New<CEnvCubemapFog>(className);
    }

    static CEnvCubemapFog* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvCubemapFog>(iIndex);
    }

    static CEnvCubemapFog* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
