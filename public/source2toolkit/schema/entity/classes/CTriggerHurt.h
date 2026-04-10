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

#include "CBaseTrigger.h"
#include "../enums/DamageTypes_t.h"

class CBaseEntity;

class CTriggerHurt : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerHurt);

    SCHEMA_FIELD(float, m_flOriginalDamage);
    SCHEMA_FIELD(float, m_flDamage);
    SCHEMA_FIELD(float, m_flDamageCap);
    SCHEMA_FIELD(float, m_flLastDmgTime);
    SCHEMA_FIELD(float, m_flForgivenessDelay);
    SCHEMA_FIELD(DamageTypes_t, m_bitsDamageInflict);
    SCHEMA_FIELD(int32_t, m_damageModel);
    SCHEMA_FIELD(bool, m_bNoDmgForce);
    SCHEMA_FIELD(Vector, m_vDamageForce);
    SCHEMA_FIELD(bool, m_thinkAlways);
    SCHEMA_FIELD(float, m_hurtThinkPeriod);
    SCHEMA_FIELD(CEntityIOOutput, m_OnHurt);
    SCHEMA_FIELD(CEntityIOOutput, m_OnHurtPlayer);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hurtEntities);

public:
    static CTriggerHurt* New(const char* className)
    {
        return CBaseEntity::New<CTriggerHurt>(className);
    }

    static CTriggerHurt* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerHurt>(iIndex);
    }

    static CTriggerHurt* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
