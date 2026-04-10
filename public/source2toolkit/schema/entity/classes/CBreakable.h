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
#include "CPropDataComponent.h"
#include "../enums/EOverrideBlockLOS_t.h"
#include "../enums/Explosions.h"
#include "../enums/Materials.h"
#include "../enums/PerformanceMode_t.h"

class CBaseEntity;
class CBasePlayerPawn;

class CBreakable : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBreakable);

    SCHEMA_FIELD(CPropDataComponent, m_CPropDataComponent);
    SCHEMA_FIELD(Materials, m_Material);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hBreaker);
    SCHEMA_FIELD(Explosions, m_Explosion);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSpawnObject);
    SCHEMA_FIELD(float, m_flPressureDelay);
    SCHEMA_FIELD(int32_t, m_iMinHealthDmg);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPropData);
    SCHEMA_FIELD(float, m_impactEnergyScale);
    SCHEMA_FIELD(EOverrideBlockLOS_t, m_nOverrideBlockLOS);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartDeath);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBreak);
    SCHEMA_FIELD(PerformanceMode_t, m_PerformanceMode);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hPhysicsAttacker);
    SCHEMA_FIELD(float, m_flLastPhysicsInfluenceTime);

public:
    static CBreakable* New(const char* className)
    {
        return CBaseEntity::New<CBreakable>(className);
    }

    static CBreakable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBreakable>(iIndex);
    }

    static CBreakable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
