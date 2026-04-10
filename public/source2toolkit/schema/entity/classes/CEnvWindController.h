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
#include "CEnvWindShared.h"

class CEnvWindController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvWindController);

    SCHEMA_FIELD(CEnvWindShared, m_EnvWindShared);
    SCHEMA_FIELD(float, m_fDirectionVariation);
    SCHEMA_FIELD(float, m_fSpeedVariation);
    SCHEMA_FIELD(float, m_fTurbulence);
    SCHEMA_FIELD(float, m_fVolumeHalfExtentXY);
    SCHEMA_FIELD(float, m_fVolumeHalfExtentZ);
    SCHEMA_FIELD(int32_t, m_nVolumeResolutionXY);
    SCHEMA_FIELD(int32_t, m_nVolumeResolutionZ);
    SCHEMA_FIELD(int32_t, m_nClipmapLevels);
    SCHEMA_FIELD(bool, m_bIsMaster);
    SCHEMA_FIELD(bool, m_bFirstTime);

public:
    static CEnvWindController* New(const char* className)
    {
        return CBaseEntity::New<CEnvWindController>(className);
    }

    static CEnvWindController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvWindController>(iIndex);
    }

    static CEnvWindController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
