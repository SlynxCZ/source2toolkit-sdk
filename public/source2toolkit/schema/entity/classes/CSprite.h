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

class CBaseEntity;

class CSprite : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSprite);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIMaterial2 >, m_hSpriteMaterial);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAttachedToEntity);
    SCHEMA_FIELD(float, m_flSpriteFramerate);
    SCHEMA_FIELD(float, m_flFrame);
    SCHEMA_FIELD(float, m_flDieTime);
    SCHEMA_FIELD(uint32_t, m_nBrightness);
    SCHEMA_FIELD(float, m_flBrightnessDuration);
    SCHEMA_FIELD(float, m_flSpriteScale);
    SCHEMA_FIELD(float, m_flScaleDuration);
    SCHEMA_FIELD(bool, m_bWorldSpaceScale);
    SCHEMA_FIELD(float, m_flGlowProxySize);
    SCHEMA_FIELD(float, m_flHDRColorScale);
    SCHEMA_FIELD(float, m_flLastTime);
    SCHEMA_FIELD(float, m_flMaxFrame);
    SCHEMA_FIELD(float, m_flStartScale);
    SCHEMA_FIELD(float, m_flDestScale);
    SCHEMA_FIELD(float, m_flScaleTimeStart);
    SCHEMA_FIELD(int32_t, m_nStartBrightness);
    SCHEMA_FIELD(int32_t, m_nDestBrightness);
    SCHEMA_FIELD(float, m_flBrightnessTimeStart);
    SCHEMA_FIELD(int32_t, m_nSpriteWidth);
    SCHEMA_FIELD(int32_t, m_nSpriteHeight);

public:
    static CSprite* New(const char* className)
    {
        return CBaseEntity::New<CSprite>(className);
    }

    static CSprite* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSprite>(iIndex);
    }

    static CSprite* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
