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

#include "CCSWeaponBaseGun.h"

class CWeaponAWP : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponAWP);


public:
    static CWeaponAWP* New(const char* className)
    {
        return CBaseEntity::New<CWeaponAWP>(className);
    }

    static CWeaponAWP* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponAWP>(iIndex);
    }

    static CWeaponAWP* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
