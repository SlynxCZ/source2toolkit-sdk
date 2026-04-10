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

class CSmokeGrenadeProjectile : public CBaseCSGrenadeProjectile
{
public:
    DECLARE_SCHEMA_CLASS(CSmokeGrenadeProjectile);

    SCHEMA_FIELD(int32_t, m_nSmokeEffectTickBegin);
    SCHEMA_FIELD(bool, m_bDidSmokeEffect);
    SCHEMA_FIELD(int32_t, m_nRandomSeed);
    SCHEMA_FIELD(Vector, m_vSmokeColor);
    SCHEMA_FIELD(Vector, m_vSmokeDetonationPos);
    SCHEMA_FIELD(CUtlVector<uint8_t>, m_VoxelFrameData);
    SCHEMA_FIELD(int32_t, m_nVoxelFrameDataSize);
    SCHEMA_FIELD(int32_t, m_nVoxelUpdate);
    SCHEMA_FIELD(float, m_flLastBounce);
    SCHEMA_FIELD(float, m_fllastSimulationTime);
    SCHEMA_FIELD(bool, m_bExplodeFromInferno);
    SCHEMA_FIELD(bool, m_bDidGroundScorch);

public:
    static CSmokeGrenadeProjectile* New(const char* className)
    {
        return CBaseEntity::New<CSmokeGrenadeProjectile>(className);
    }

    static CSmokeGrenadeProjectile* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSmokeGrenadeProjectile>(iIndex);
    }

    static CSmokeGrenadeProjectile* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
