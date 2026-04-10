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

class CTonemapController2 : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTonemapController2);

    SCHEMA_FIELD(float, m_flAutoExposureMin);
    SCHEMA_FIELD(float, m_flAutoExposureMax);
    SCHEMA_FIELD(float, m_flExposureAdaptationSpeedUp);
    SCHEMA_FIELD(float, m_flExposureAdaptationSpeedDown);
    SCHEMA_FIELD(float, m_flTonemapEVSmoothingRange);

public:
    static CTonemapController2* New(const char* className)
    {
        return CBaseEntity::New<CTonemapController2>(className);
    }

    static CTonemapController2* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTonemapController2>(iIndex);
    }

    static CTonemapController2* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
