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

#include "CLogicalEntity.h"

class CLightEntity;

class CMultiLightProxy : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CMultiLightProxy);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLightNameFilter);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLightClassFilter);
    SCHEMA_FIELD(float, m_flLightRadiusFilter);
    SCHEMA_FIELD(float, m_flBrightnessDelta);
    SCHEMA_FIELD(bool, m_bPerformScreenFade);
    SCHEMA_FIELD(float, m_flTargetBrightnessMultiplier);
    SCHEMA_FIELD(float, m_flCurrentBrightnessMultiplier);
    SCHEMA_FIELD(CUtlVector<CHandle<CLightEntity>>, m_vecLights);

public:
    static CMultiLightProxy* New(const char* className)
    {
        return CBaseEntity::New<CMultiLightProxy>(className);
    }

    static CMultiLightProxy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMultiLightProxy>(iIndex);
    }

    static CMultiLightProxy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
