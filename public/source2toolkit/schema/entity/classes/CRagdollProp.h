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

#include "CBaseAnimGraph.h"
#include "ragdoll_t.h"

class CBaseEntity;
class CBasePlayerPawn;

class CRagdollProp : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollProp);

    SCHEMA_FIELD(ragdoll_t, m_ragdoll);
    SCHEMA_FIELD(bool, m_bStartDisabled);
    SCHEMA_FIELD(CUtlVector<bool>, m_ragEnabled);
    SCHEMA_FIELD(CUtlVector<Vector>, m_ragPos);
    SCHEMA_FIELD(CUtlVector<QAngle>, m_ragAngles);
    SCHEMA_FIELD(uint32_t, m_lastUpdateTickCount);
    SCHEMA_FIELD(bool, m_allAsleep);
    SCHEMA_FIELD(bool, m_bFirstCollisionAfterLaunch);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hDamageEntity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hKiller);
    SCHEMA_FIELD(CHandle<CBasePlayerPawn>, m_hPhysicsAttacker);
    SCHEMA_FIELD(float, m_flLastPhysicsInfluenceTime);
    SCHEMA_FIELD(float, m_flFadeOutStartTime);
    SCHEMA_FIELD(float, m_flFadeTime);
    SCHEMA_FIELD(Vector, m_vecLastOrigin);
    SCHEMA_FIELD(float, m_flAwakeTime);
    SCHEMA_FIELD(float, m_flLastOriginChangeTime);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strOriginClassName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strSourceClassName);
    SCHEMA_FIELD(bool, m_bHasBeenPhysgunned);
    SCHEMA_FIELD(bool, m_bAllowStretch);
    SCHEMA_FIELD(float, m_flBlendWeight);
    SCHEMA_FIELD(float, m_flDefaultFadeScale);
    SCHEMA_FIELD(CUtlVector<Vector>, m_ragdollMins);
    SCHEMA_FIELD(CUtlVector<Vector>, m_ragdollMaxs);
    SCHEMA_FIELD(bool, m_bShouldDeleteActivationRecord);

public:
    static CRagdollProp* New(const char* className)
    {
        return CBaseEntity::New<CRagdollProp>(className);
    }

    static CRagdollProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollProp>(iIndex);
    }

    static CRagdollProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
