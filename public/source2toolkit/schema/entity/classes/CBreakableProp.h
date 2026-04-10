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

#include "../enums/BaseExplosionTypes_t.h"
#include "../enums/BreakableContentsType_t.h"
#include "CBaseProp.h"
#include "CPropDataComponent.h"
#include "../enums/PerformanceMode_t.h"

class CBaseEntity;
class CBasePlayerPawn;

class CBreakableProp : public CBaseProp
{
public:
    DECLARE_SCHEMA_CLASS(CBreakableProp);

    SCHEMA_FIELD(CPropDataComponent, m_CPropDataComponent);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartDeath);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBreak);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTakeDamage);
    SCHEMA_FIELD(float, m_impactEnergyScale);
    SCHEMA_FIELD(int32_t, m_iMinHealthDmg);
    SCHEMA_FIELD(QAngle, m_preferredCarryAngles);
    SCHEMA_FIELD(float, m_flPressureDelay);
    SCHEMA_FIELD(float, m_flDefBurstScale);
    SCHEMA_FIELD(Vector, m_vDefBurstOffset);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hBreaker);
    SCHEMA_FIELD(PerformanceMode_t, m_PerformanceMode);
    SCHEMA_FIELD(float, m_flPreventDamageBeforeTime);
    SCHEMA_FIELD(BreakableContentsType_t, m_BreakableContentsType);
    SCHEMA_FIELD(CUtlString, m_strBreakableContentsPropGroupOverride);
    SCHEMA_FIELD(CUtlString, m_strBreakableContentsParticleOverride);
    SCHEMA_FIELD(bool, m_bHasBreakPiecesOrCommands);
    SCHEMA_FIELD(float, m_explodeDamage);
    SCHEMA_FIELD(float, m_explodeRadius);
    SCHEMA_FIELD(BaseExplosionTypes_t, m_nExplosionType);
    SCHEMA_FIELD(float, m_explosionDelay);
    SCHEMA_FIELD(CUtlSymbolLarge, m_explosionBuildupSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_explosionCustomEffect);
    SCHEMA_FIELD(CUtlSymbolLarge, m_explosionCustomSound);
    SCHEMA_FIELD(CUtlSymbolLarge, m_explosionModifier);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hPhysicsAttacker);
    SCHEMA_FIELD(float, m_flLastPhysicsInfluenceTime);
    SCHEMA_FIELD(float, m_flDefaultFadeScale);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hLastAttacker);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPuntSound);
    SCHEMA_FIELD(bool, m_bUsePuntSound);
    SCHEMA_FIELD(bool, m_bOriginalBlockLOS);

public:
    static CBreakableProp* New(const char* className)
    {
        return CBaseEntity::New<CBreakableProp>(className);
    }

    static CBreakableProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBreakableProp>(iIndex);
    }

    static CBreakableProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
