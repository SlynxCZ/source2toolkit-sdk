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

#include "CPointEntity.h"

class CPhysExplosion : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysExplosion);

    SCHEMA_FIELD(bool, m_bExplodeOnSpawn);
    SCHEMA_FIELD(float, m_flMagnitude);
    SCHEMA_FIELD(float, m_flDamage);
    SCHEMA_FIELD(float, m_radius);
    SCHEMA_FIELD(CUtlSymbolLarge, m_targetEntityName);
    SCHEMA_FIELD(float, m_flInnerRadius);
    SCHEMA_FIELD(float, m_flPushScale);
    SCHEMA_FIELD(bool, m_bConvertToDebrisWhenPossible);
    SCHEMA_FIELD(bool, m_bAffectInvulnerableEnts);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPushedPlayer);

public:
    static CPhysExplosion* New(const char* className)
    {
        return CBaseEntity::New<CPhysExplosion>(className);
    }

    static CPhysExplosion* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysExplosion>(iIndex);
    }

    static CPhysExplosion* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
