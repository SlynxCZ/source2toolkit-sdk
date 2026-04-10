#pragma once
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

class CBaseEntity;

class CEnvWindShared
{
public:
    DECLARE_SCHEMA_CLASS(CEnvWindShared);

    SCHEMA_FIELD(float, m_flStartTime);
    SCHEMA_FIELD(uint32_t, m_iWindSeed);
    SCHEMA_FIELD(uint16_t, m_iMinWind);
    SCHEMA_FIELD(uint16_t, m_iMaxWind);
    SCHEMA_FIELD(int32_t, m_windRadius);
    SCHEMA_FIELD(uint16_t, m_iMinGust);
    SCHEMA_FIELD(uint16_t, m_iMaxGust);
    SCHEMA_FIELD(float, m_flMinGustDelay);
    SCHEMA_FIELD(float, m_flMaxGustDelay);
    SCHEMA_FIELD(float, m_flGustDuration);
    SCHEMA_FIELD(uint16_t, m_iGustDirChange);
    SCHEMA_FIELD(uint16_t, m_iInitialWindDir);
    SCHEMA_FIELD(float, m_flInitialWindSpeed);
    SCHEMA_FIELD(Vector, m_location);
    SCHEMA_FIELD(CEntityIOOutput, m_OnGustStart);
    SCHEMA_FIELD(CEntityIOOutput, m_OnGustEnd);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEntOwner);
};
