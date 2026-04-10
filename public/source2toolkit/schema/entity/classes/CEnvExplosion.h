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

#include "../enums/Class_T.h"
#include "CModelPointEntity.h"
#include "../enums/DamageTypes_t.h"

class CBaseEntity;

class CEnvExplosion : public CModelPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvExplosion);

    SCHEMA_FIELD(int32_t, m_iMagnitude);
    SCHEMA_FIELD(float, m_flPlayerDamage);
    SCHEMA_FIELD(int32_t, m_iRadiusOverride);
    SCHEMA_FIELD(float, m_flInnerRadius);
    SCHEMA_FIELD(float, m_flDamageForce);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hInflictor);
    SCHEMA_FIELD(DamageTypes_t, m_iCustomDamageType);
    SCHEMA_FIELD(bool, m_bCreateDebris);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszCustomEffectName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszCustomSoundName);
    SCHEMA_FIELD(bool, m_bSuppressParticleImpulse);
    SCHEMA_FIELD(Class_T, m_iClassIgnore);
    SCHEMA_FIELD(Class_T, m_iClassIgnore2);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszEntityIgnoreName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEntityIgnore);

public:
    static CEnvExplosion* New(const char* className)
    {
        return CBaseEntity::New<CEnvExplosion>(className);
    }

    static CEnvExplosion* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvExplosion>(iIndex);
    }

    static CEnvExplosion* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
