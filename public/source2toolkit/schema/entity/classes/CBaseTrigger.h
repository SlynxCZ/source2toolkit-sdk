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

#include "CBaseToggle.h"

class CBaseEntity;
class CBaseFilter;

class CBaseTrigger : public CBaseToggle
{
public:
    DECLARE_SCHEMA_CLASS(CBaseTrigger);

    SCHEMA_FIELD(CEntityIOOutput, m_OnStartTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartTouchAll);
    SCHEMA_FIELD(CEntityIOOutput, m_OnEndTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnEndTouchAll);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTouching);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTouchingEachEntity);
    SCHEMA_FIELD(CEntityIOOutput, m_OnNotTouching);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hTouchingEntities);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterName);
    SCHEMA_FIELD(CHandle<CBaseFilter>, m_hFilter);
    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(bool, m_bUseAsyncQueries);

public:
    static CBaseTrigger* New(const char* className)
    {
        return CBaseEntity::New<CBaseTrigger>(className);
    }

    static CBaseTrigger* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseTrigger>(iIndex);
    }

    static CBaseTrigger* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
