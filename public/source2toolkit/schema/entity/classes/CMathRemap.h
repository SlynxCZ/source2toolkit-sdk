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

class CMathRemap : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CMathRemap);

    SCHEMA_FIELD(float, m_flInMin);
    SCHEMA_FIELD(float, m_flInMax);
    SCHEMA_FIELD(float, m_flOut1);
    SCHEMA_FIELD(float, m_flOut2);
    SCHEMA_FIELD(float, m_flOldInValue);
    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(CEntityIOOutput, m_OnRoseAboveMin);
    SCHEMA_FIELD(CEntityIOOutput, m_OnRoseAboveMax);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFellBelowMin);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFellBelowMax);

public:
    static CMathRemap* New(const char* className)
    {
        return CBaseEntity::New<CMathRemap>(className);
    }

    static CMathRemap* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMathRemap>(iIndex);
    }

    static CMathRemap* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
