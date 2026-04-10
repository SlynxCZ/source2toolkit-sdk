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

class CInfoSpawnGroupLoadUnload : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoSpawnGroupLoadUnload);

    SCHEMA_FIELD(CEntityIOOutput, m_OnSpawnGroupLoadStarted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnSpawnGroupLoadFinished);
    SCHEMA_FIELD(CEntityIOOutput, m_OnSpawnGroupUnloadStarted);
    SCHEMA_FIELD(CEntityIOOutput, m_OnSpawnGroupUnloadFinished);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSpawnGroupName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSpawnGroupFilterName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLandmarkName);
    SCHEMA_FIELD(CUtlString, m_sFixedSpawnGroupName);
    SCHEMA_FIELD(float, m_flTimeoutInterval);
    SCHEMA_FIELD(bool, m_bAutoActivate);
    SCHEMA_FIELD(bool, m_bUnloadingStarted);
    SCHEMA_FIELD(bool, m_bQueueActiveSpawnGroupChange);
    SCHEMA_FIELD(bool, m_bQueueFinishLoading);

public:
    static CInfoSpawnGroupLoadUnload* New(const char* className)
    {
        return CBaseEntity::New<CInfoSpawnGroupLoadUnload>(className);
    }

    static CInfoSpawnGroupLoadUnload* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoSpawnGroupLoadUnload>(iIndex);
    }

    static CInfoSpawnGroupLoadUnload* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
