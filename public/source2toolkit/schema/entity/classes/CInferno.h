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

#include "CBaseModelEntity.h"
#include "CountdownTimer.h"
#include "Extent.h"
#include "IntervalTimer.h"

class CInferno : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInferno);

    SCHEMA_FIELD_POINTER(Vector, m_firePositions);
    SCHEMA_FIELD_POINTER(Vector, m_fireParentPositions);
    SCHEMA_FIELD_POINTER(bool, m_bFireIsBurning);
    SCHEMA_FIELD_POINTER(Vector, m_BurnNormal);
    SCHEMA_FIELD(int32_t, m_fireCount);
    SCHEMA_FIELD(int32_t, m_nInfernoType);
    SCHEMA_FIELD(int32_t, m_nFireEffectTickBegin);
    SCHEMA_FIELD(float, m_nFireLifetime);
    SCHEMA_FIELD(bool, m_bInPostEffectTime);
    SCHEMA_FIELD(bool, m_bWasCreatedInSmoke);
    SCHEMA_FIELD(Extent, m_extent);
    SCHEMA_FIELD(CountdownTimer, m_damageTimer);
    SCHEMA_FIELD(CountdownTimer, m_damageRampTimer);
    SCHEMA_FIELD(Vector, m_splashVelocity);
    SCHEMA_FIELD(Vector, m_InitialSplashVelocity);
    SCHEMA_FIELD(Vector, m_startPos);
    SCHEMA_FIELD(Vector, m_vecOriginalSpawnLocation);
    SCHEMA_FIELD(IntervalTimer, m_activeTimer);
    SCHEMA_FIELD(int32_t, m_fireSpawnOffset);
    SCHEMA_FIELD(int32_t, m_nMaxFlames);
    SCHEMA_FIELD(int32_t, m_nSpreadCount);
    SCHEMA_FIELD(CountdownTimer, m_BookkeepingTimer);
    SCHEMA_FIELD(CountdownTimer, m_NextSpreadTimer);
    SCHEMA_FIELD(uint16_t, m_nSourceItemDefIndex);

public:
    static CInferno* New(const char* className)
    {
        return CBaseEntity::New<CInferno>(className);
    }

    static CInferno* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInferno>(iIndex);
    }

    static CInferno* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
