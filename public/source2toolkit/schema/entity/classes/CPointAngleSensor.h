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

class CBaseEntity;

class CPointAngleSensor : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointAngleSensor);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nLookAtName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetEntity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hLookAtEntity);
    SCHEMA_FIELD(float, m_flDuration);
    SCHEMA_FIELD(float, m_flDotTolerance);
    SCHEMA_FIELD(float, m_flFacingTime);
    SCHEMA_FIELD(bool, m_bFired);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFacingLookat);
    SCHEMA_FIELD(CEntityIOOutput, m_OnNotFacingLookat);

public:
    static CPointAngleSensor* New(const char* className)
    {
        return CBaseEntity::New<CPointAngleSensor>(className);
    }

    static CPointAngleSensor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointAngleSensor>(iIndex);
    }

    static CPointAngleSensor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
