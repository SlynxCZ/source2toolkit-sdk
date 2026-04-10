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

class CEnvSky : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSky);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hSkyMaterial);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hSkyMaterialLightingOnly);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(Color, m_vTintColor);
    SCHEMA_FIELD(Color, m_vTintColorLightingOnly);
    SCHEMA_FIELD(float, m_flBrightnessScale);
    SCHEMA_FIELD(int32_t, m_nFogType);
    SCHEMA_FIELD(float, m_flFogMinStart);
    SCHEMA_FIELD(float, m_flFogMinEnd);
    SCHEMA_FIELD(float, m_flFogMaxStart);
    SCHEMA_FIELD(float, m_flFogMaxEnd);
    SCHEMA_FIELD(bool, m_bEnabled);

public:
    static CEnvSky* New(const char* className)
    {
        return CBaseEntity::New<CEnvSky>(className);
    }

    static CEnvSky* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSky>(iIndex);
    }

    static CEnvSky* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
