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

class CEnvVolumetricFogController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvVolumetricFogController);

    SCHEMA_FIELD(float, m_flScattering);
    SCHEMA_FIELD(Color, m_TintColor);
    SCHEMA_FIELD(float, m_flAnisotropy);
    SCHEMA_FIELD(float, m_flFadeSpeed);
    SCHEMA_FIELD(float, m_flDrawDistance);
    SCHEMA_FIELD(float, m_flFadeInStart);
    SCHEMA_FIELD(float, m_flFadeInEnd);
    SCHEMA_FIELD(float, m_flIndirectStrength);
    SCHEMA_FIELD(int32_t, m_nVolumeDepth);
    SCHEMA_FIELD(float, m_fFirstVolumeSliceThickness);
    SCHEMA_FIELD(int32_t, m_nIndirectTextureDimX);
    SCHEMA_FIELD(int32_t, m_nIndirectTextureDimY);
    SCHEMA_FIELD(int32_t, m_nIndirectTextureDimZ);
    SCHEMA_FIELD(Vector, m_vBoxMins);
    SCHEMA_FIELD(Vector, m_vBoxMaxs);
    SCHEMA_FIELD(bool, m_bActive);
    SCHEMA_FIELD(float, m_flStartAnisoTime);
    SCHEMA_FIELD(float, m_flStartScatterTime);
    SCHEMA_FIELD(float, m_flStartDrawDistanceTime);
    SCHEMA_FIELD(float, m_flStartAnisotropy);
    SCHEMA_FIELD(float, m_flStartScattering);
    SCHEMA_FIELD(float, m_flStartDrawDistance);
    SCHEMA_FIELD(float, m_flDefaultAnisotropy);
    SCHEMA_FIELD(float, m_flDefaultScattering);
    SCHEMA_FIELD(float, m_flDefaultDrawDistance);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(bool, m_bEnableIndirect);
    SCHEMA_FIELD(bool, m_bIsMaster);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hFogIndirectTexture);
    SCHEMA_FIELD(int32_t, m_nForceRefreshCount);
    SCHEMA_FIELD(float, m_fNoiseSpeed);
    SCHEMA_FIELD(float, m_fNoiseStrength);
    SCHEMA_FIELD(Vector, m_vNoiseScale);
    SCHEMA_FIELD(float, m_fWindSpeed);
    SCHEMA_FIELD(Vector, m_vWindDirection);
    SCHEMA_FIELD(bool, m_bFirstTime);

public:
    static CEnvVolumetricFogController* New(const char* className)
    {
        return CBaseEntity::New<CEnvVolumetricFogController>(className);
    }

    static CEnvVolumetricFogController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvVolumetricFogController>(iIndex);
    }

    static CEnvVolumetricFogController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
