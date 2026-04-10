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

#include "CBaseCSGrenadeProjectile.h"

class CDecoyProjectile : public CBaseCSGrenadeProjectile
{
public:
    DECLARE_SCHEMA_CLASS(CDecoyProjectile);

    SCHEMA_FIELD(int32_t, m_nDecoyShotTick);
    SCHEMA_FIELD(int32_t, m_shotsRemaining);
    SCHEMA_FIELD(float, m_fExpireTime);
    SCHEMA_FIELD(uint16_t, m_decoyWeaponDefIndex);

public:
    static CDecoyProjectile* New(const char* className)
    {
        return CBaseEntity::New<CDecoyProjectile>(className);
    }

    static CDecoyProjectile* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDecoyProjectile>(iIndex);
    }

    static CDecoyProjectile* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
