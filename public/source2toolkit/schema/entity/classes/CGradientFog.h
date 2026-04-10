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

class CGradientFog : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGradientFog);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCTextureBase >, m_hGradientFogTexture);
    SCHEMA_FIELD(float, m_flFogStartDistance);
    SCHEMA_FIELD(float, m_flFogEndDistance);
    SCHEMA_FIELD(bool, m_bHeightFogEnabled);
    SCHEMA_FIELD(float, m_flFogStartHeight);
    SCHEMA_FIELD(float, m_flFogEndHeight);
    SCHEMA_FIELD(float, m_flFarZ);
    SCHEMA_FIELD(float, m_flFogMaxOpacity);
    SCHEMA_FIELD(float, m_flFogFalloffExponent);
    SCHEMA_FIELD(float, m_flFogVerticalExponent);
    SCHEMA_FIELD(Color, m_fogColor);
    SCHEMA_FIELD(float, m_flFogStrength);
    SCHEMA_FIELD(float, m_flFadeTime);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(bool, m_bIsEnabled);
    SCHEMA_FIELD(bool, m_bGradientFogNeedsTextures);

public:
    static CGradientFog* New(const char* className)
    {
        return CBaseEntity::New<CGradientFog>(className);
    }

    static CGradientFog* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGradientFog>(iIndex);
    }

    static CGradientFog* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
