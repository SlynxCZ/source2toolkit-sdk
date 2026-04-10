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

class CColorCorrectionVolume : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CColorCorrectionVolume);

    SCHEMA_FIELD(float, m_MaxWeight);
    SCHEMA_FIELD(float, m_FadeDuration);
    SCHEMA_FIELD(float, m_Weight);
    SCHEMA_FIELD_POINTER(char, m_lookupFilename);
    SCHEMA_FIELD(float, m_LastEnterWeight);
    SCHEMA_FIELD(float, m_LastEnterTime);
    SCHEMA_FIELD(float, m_LastExitWeight);
    SCHEMA_FIELD(float, m_LastExitTime);

public:
    static CColorCorrectionVolume* New(const char* className)
    {
        return CBaseEntity::New<CColorCorrectionVolume>(className);
    }

    static CColorCorrectionVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CColorCorrectionVolume>(iIndex);
    }

    static CColorCorrectionVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
