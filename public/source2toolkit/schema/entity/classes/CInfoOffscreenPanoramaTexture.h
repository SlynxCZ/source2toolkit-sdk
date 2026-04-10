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

class CBaseModelEntity;

class CInfoOffscreenPanoramaTexture : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoOffscreenPanoramaTexture);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(int32_t, m_nResolutionX);
    SCHEMA_FIELD(int32_t, m_nResolutionY);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szPanelType);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szLayoutFileName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_RenderAttrName);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseModelEntity>>, m_TargetEntities);
    SCHEMA_FIELD(int32_t, m_nTargetChangeCount);
    SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>, m_vecCSSClasses);
    SCHEMA_FIELD(CUtlSymbolLarge, m_szTargetsName);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseModelEntity>>, m_AdditionalTargetEntities);

public:
    static CInfoOffscreenPanoramaTexture* New(const char* className)
    {
        return CBaseEntity::New<CInfoOffscreenPanoramaTexture>(className);
    }

    static CInfoOffscreenPanoramaTexture* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoOffscreenPanoramaTexture>(iIndex);
    }

    static CInfoOffscreenPanoramaTexture* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
