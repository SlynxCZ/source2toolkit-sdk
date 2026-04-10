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

class CFlashbangProjectile : public CBaseCSGrenadeProjectile
{
public:
    DECLARE_SCHEMA_CLASS(CFlashbangProjectile);

    SCHEMA_FIELD(float, m_flTimeToDetonate);
    SCHEMA_FIELD(uint8_t, m_numOpponentsHit);
    SCHEMA_FIELD(uint8_t, m_numTeammatesHit);

public:
    static CFlashbangProjectile* New(const char* className)
    {
        return CBaseEntity::New<CFlashbangProjectile>(className);
    }

    static CFlashbangProjectile* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFlashbangProjectile>(iIndex);
    }

    static CFlashbangProjectile* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
