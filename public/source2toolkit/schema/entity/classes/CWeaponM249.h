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

class CWeaponM249 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponM249);


public:
    static CWeaponM249* New(const char* className)
    {
        return CBaseEntity::New<CWeaponM249>(className);
    }

    static CWeaponM249* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponM249>(iIndex);
    }

    static CWeaponM249* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
