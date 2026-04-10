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

class CLogicDistanceCheck : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicDistanceCheck);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEntityA);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEntityB);
    SCHEMA_FIELD(float, m_flZone1Distance);
    SCHEMA_FIELD(float, m_flZone2Distance);
    SCHEMA_FIELD(CEntityIOOutput, m_InZone1);
    SCHEMA_FIELD(CEntityIOOutput, m_InZone2);
    SCHEMA_FIELD(CEntityIOOutput, m_InZone3);

public:
    static CLogicDistanceCheck* New(const char* className)
    {
        return CBaseEntity::New<CLogicDistanceCheck>(className);
    }

    static CLogicDistanceCheck* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicDistanceCheck>(iIndex);
    }

    static CLogicDistanceCheck* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
