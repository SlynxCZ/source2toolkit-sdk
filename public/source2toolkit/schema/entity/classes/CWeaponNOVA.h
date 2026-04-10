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

#include "CCSWeaponBaseShotgun.h"

class CWeaponNOVA : public CCSWeaponBaseShotgun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponNOVA);


public:
    static CWeaponNOVA* New(const char* className)
    {
        return CBaseEntity::New<CWeaponNOVA>(className);
    }

    static CWeaponNOVA* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponNOVA>(iIndex);
    }

    static CWeaponNOVA* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
