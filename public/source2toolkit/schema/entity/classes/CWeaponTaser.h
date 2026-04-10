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

#include "CCSWeaponBaseGun.h"

class CWeaponTaser : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponTaser);

    SCHEMA_FIELD(float, m_fFireTime);
    SCHEMA_FIELD(int32_t, m_nLastAttackTick);

public:
    static CWeaponTaser* New(const char* className)
    {
        return CBaseEntity::New<CWeaponTaser>(className);
    }

    static CWeaponTaser* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponTaser>(iIndex);
    }

    static CWeaponTaser* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
