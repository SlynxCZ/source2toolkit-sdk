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

class CChangeLevel : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CChangeLevel);

    SCHEMA_FIELD(CUtlString, m_sMapName);
    SCHEMA_FIELD(CUtlString, m_sLandmarkName);
    SCHEMA_FIELD(CEntityIOOutput, m_OnChangeLevel);
    SCHEMA_FIELD(bool, m_bTouched);
    SCHEMA_FIELD(bool, m_bNoTouch);
    SCHEMA_FIELD(bool, m_bNewChapter);
    SCHEMA_FIELD(bool, m_bOnChangeLevelFired);

public:
    static CChangeLevel* New(const char* className)
    {
        return CBaseEntity::New<CChangeLevel>(className);
    }

    static CChangeLevel* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CChangeLevel>(iIndex);
    }

    static CChangeLevel* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
