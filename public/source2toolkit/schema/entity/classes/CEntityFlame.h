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

#include "CBaseEntity.h"

class CEntityFlame : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEntityFlame);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEntAttached);
    SCHEMA_FIELD(bool, m_bCheapEffect);
    SCHEMA_FIELD(float, m_flSize);
    SCHEMA_FIELD(bool, m_bUseHitboxes);
    SCHEMA_FIELD(int32_t, m_iNumHitboxFires);
    SCHEMA_FIELD(float, m_flHitboxFireScale);
    SCHEMA_FIELD(float, m_flLifetime);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAttacker);
    SCHEMA_FIELD(float, m_flDirectDamagePerSecond);
    SCHEMA_FIELD(int32_t, m_iCustomDamageType);

public:
    static CEntityFlame* New(const char* className)
    {
        return CBaseEntity::New<CEntityFlame>(className);
    }

    static CEntityFlame* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEntityFlame>(iIndex);
    }

    static CEntityFlame* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
