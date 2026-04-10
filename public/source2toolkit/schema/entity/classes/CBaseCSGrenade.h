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

#include "CCSWeaponBase.h"

class CBaseCSGrenade : public CCSWeaponBase
{
public:
    DECLARE_SCHEMA_CLASS(CBaseCSGrenade);

    SCHEMA_FIELD(bool, m_bRedraw);
    SCHEMA_FIELD(bool, m_bIsHeldByPlayer);
    SCHEMA_FIELD(bool, m_bPinPulled);
    SCHEMA_FIELD(bool, m_bJumpThrow);
    SCHEMA_FIELD(bool, m_bThrowAnimating);
    SCHEMA_FIELD(float, m_fThrowTime);
    SCHEMA_FIELD(float, m_flThrowStrength);
    SCHEMA_FIELD(float, m_fDropTime);
    SCHEMA_FIELD(float, m_fPinPullTime);
    SCHEMA_FIELD(bool, m_bJustPulledPin);
    SCHEMA_FIELD(int32_t, m_nNextHoldTick);
    SCHEMA_FIELD(float, m_flNextHoldFrac);
    SCHEMA_FIELD(CHandle<CCSWeaponBase>, m_hSwitchToWeaponAfterThrow);

public:
    static CBaseCSGrenade* New(const char* className)
    {
        return CBaseEntity::New<CBaseCSGrenade>(className);
    }

    static CBaseCSGrenade* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseCSGrenade>(iIndex);
    }

    static CBaseCSGrenade* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
