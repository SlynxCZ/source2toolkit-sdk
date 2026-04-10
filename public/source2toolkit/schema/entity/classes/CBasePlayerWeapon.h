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

#include "CEconEntity.h"

class CCSWeaponBase;
class CCSWeaponBaseVData;

class CBasePlayerWeapon : public CEconEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBasePlayerWeapon);

    SCHEMA_FIELD(int32_t, m_nNextPrimaryAttackTick);
    SCHEMA_FIELD(float, m_flNextPrimaryAttackTickRatio);
    SCHEMA_FIELD(int32_t, m_nNextSecondaryAttackTick);
    SCHEMA_FIELD(float, m_flNextSecondaryAttackTickRatio);
    SCHEMA_FIELD(int32_t, m_iClip1);
    SCHEMA_FIELD(int32_t, m_iClip2);
    SCHEMA_FIELD_POINTER(int32_t, m_pReserveAmmo);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerUse);

public:
    /// <summary>Get weapon VData.</summary>
    CCSWeaponBaseVData* GetWeaponVData();
    /// <summary>Get weapon classname.</summary>
    const char* GetWeaponClassname();

public:
    static CBasePlayerWeapon* New(const char* className)
    {
        return CBaseEntity::New<CBasePlayerWeapon>(className);
    }

    static CBasePlayerWeapon* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBasePlayerWeapon>(iIndex);
    }

    static CBasePlayerWeapon* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
