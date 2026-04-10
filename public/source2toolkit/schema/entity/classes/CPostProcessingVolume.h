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

#include "CBaseTrigger.h"
#include "InfoForResourceTypeCPostProcessingResource.h"

class CPostProcessingVolume : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CPostProcessingVolume);

    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeCPostProcessingResource >, m_hPostSettings);
    SCHEMA_FIELD(float, m_flFadeDuration);
    SCHEMA_FIELD(float, m_flMinLogExposure);
    SCHEMA_FIELD(float, m_flMaxLogExposure);
    SCHEMA_FIELD(float, m_flMinExposure);
    SCHEMA_FIELD(float, m_flMaxExposure);
    SCHEMA_FIELD(float, m_flExposureCompensation);
    SCHEMA_FIELD(float, m_flExposureFadeSpeedUp);
    SCHEMA_FIELD(float, m_flExposureFadeSpeedDown);
    SCHEMA_FIELD(float, m_flTonemapEVSmoothingRange);
    SCHEMA_FIELD(bool, m_bMaster);
    SCHEMA_FIELD(bool, m_bExposureControl);

public:
    static CPostProcessingVolume* New(const char* className)
    {
        return CBaseEntity::New<CPostProcessingVolume>(className);
    }

    static CPostProcessingVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPostProcessingVolume>(iIndex);
    }

    static CPostProcessingVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
