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

class CLogicAchievement : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicAchievement);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszAchievementEventID);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFired);

public:
    static CLogicAchievement* New(const char* className)
    {
        return CBaseEntity::New<CLogicAchievement>(className);
    }

    static CLogicAchievement* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicAchievement>(iIndex);
    }

    static CLogicAchievement* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
