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

class CLogicDistanceAutosave : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicDistanceAutosave);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszTargetEntity);
    SCHEMA_FIELD(float, m_flDistanceToPlayer);
    SCHEMA_FIELD(bool, m_bForceNewLevelUnit);
    SCHEMA_FIELD(bool, m_bCheckCough);
    SCHEMA_FIELD(bool, m_bThinkDangerous);
    SCHEMA_FIELD(float, m_flDangerousTime);

public:
    static CLogicDistanceAutosave* New(const char* className)
    {
        return CBaseEntity::New<CLogicDistanceAutosave>(className);
    }

    static CLogicDistanceAutosave* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicDistanceAutosave>(iIndex);
    }

    static CLogicDistanceAutosave* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
