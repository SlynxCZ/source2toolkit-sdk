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

class CEnvWindVolume : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvWindVolume);

    SCHEMA_FIELD(bool, m_bActive);
    SCHEMA_FIELD(Vector, m_vBoxMins);
    SCHEMA_FIELD(Vector, m_vBoxMaxs);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(int32_t, m_nShape);
    SCHEMA_FIELD(float, m_fWindSpeedMultiplier);
    SCHEMA_FIELD(float, m_fWindTurbulenceMultiplier);
    SCHEMA_FIELD(float, m_fWindSpeedVariationMultiplier);
    SCHEMA_FIELD(float, m_fWindDirectionVariationMultiplier);

public:
    static CEnvWindVolume* New(const char* className)
    {
        return CBaseEntity::New<CEnvWindVolume>(className);
    }

    static CEnvWindVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvWindVolume>(iIndex);
    }

    static CEnvWindVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
