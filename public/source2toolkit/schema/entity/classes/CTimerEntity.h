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

class CTimerEntity : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTimerEntity);

    SCHEMA_FIELD(CEntityIOOutput, m_OnTimer);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTimerHigh);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTimerLow);
    SCHEMA_FIELD(int32_t, m_iDisabled);
    SCHEMA_FIELD(float, m_flInitialDelay);
    SCHEMA_FIELD(float, m_flRefireTime);
    SCHEMA_FIELD(bool, m_bUpDownState);
    SCHEMA_FIELD(int32_t, m_iUseRandomTime);
    SCHEMA_FIELD(bool, m_bPauseAfterFiring);
    SCHEMA_FIELD(float, m_flLowerRandomBound);
    SCHEMA_FIELD(float, m_flUpperRandomBound);
    SCHEMA_FIELD(float, m_flRemainingTime);
    SCHEMA_FIELD(bool, m_bPaused);

public:
    static CTimerEntity* New(const char* className)
    {
        return CBaseEntity::New<CTimerEntity>(className);
    }

    static CTimerEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTimerEntity>(iIndex);
    }

    static CTimerEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
