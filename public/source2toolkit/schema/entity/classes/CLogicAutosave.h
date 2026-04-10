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

class CLogicAutosave : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicAutosave);

    SCHEMA_FIELD(bool, m_bForceNewLevelUnit);
    SCHEMA_FIELD(int32_t, m_minHitPoints);
    SCHEMA_FIELD(int32_t, m_minHitPointsToCommit);

public:
    static CLogicAutosave* New(const char* className)
    {
        return CBaseEntity::New<CLogicAutosave>(className);
    }

    static CLogicAutosave* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicAutosave>(iIndex);
    }

    static CLogicAutosave* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
