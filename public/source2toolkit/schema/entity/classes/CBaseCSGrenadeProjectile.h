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

#include "CBaseGrenade.h"
#include "InfoForResourceTypeIParticleSystemDefinition.h"

class CBaseCSGrenadeProjectile : public CBaseGrenade
{
public:
    DECLARE_SCHEMA_CLASS(CBaseCSGrenadeProjectile);

    SCHEMA_FIELD(Vector, m_vInitialPosition);
    SCHEMA_FIELD(Vector, m_vInitialVelocity);
    SCHEMA_FIELD(int32_t, m_nBounces);
    SCHEMA_FIELD(CStrongHandle< InfoForResourceTypeIParticleSystemDefinition >, m_nExplodeEffectIndex);
    SCHEMA_FIELD(int32_t, m_nExplodeEffectTickBegin);
    SCHEMA_FIELD(Vector, m_vecExplodeEffectOrigin);
    SCHEMA_FIELD(float, m_flSpawnTime);
    SCHEMA_FIELD(uint8_t, m_unOGSExtraFlags);
    SCHEMA_FIELD(bool, m_bDetonationRecorded);
    SCHEMA_FIELD(uint16_t, m_nItemIndex);
    SCHEMA_FIELD(Vector, m_vecOriginalSpawnLocation);
    SCHEMA_FIELD(float, m_flLastBounceSoundTime);
    SCHEMA_FIELD(RotationVector, m_vecGrenadeSpin);
    SCHEMA_FIELD(Vector, m_vecLastHitSurfaceNormal);
    SCHEMA_FIELD(int32_t, m_nTicksAtZeroVelocity);
    SCHEMA_FIELD(bool, m_bHasEverHitEnemy);

public:
    static CBaseCSGrenadeProjectile* New(const char* className)
    {
        return CBaseEntity::New<CBaseCSGrenadeProjectile>(className);
    }

    static CBaseCSGrenadeProjectile* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseCSGrenadeProjectile>(iIndex);
    }

    static CBaseCSGrenadeProjectile* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
