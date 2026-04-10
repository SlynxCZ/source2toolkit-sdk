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

class CWeaponElite : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponElite);


public:
    static CWeaponElite* New(const char* className)
    {
        return CBaseEntity::New<CWeaponElite>(className);
    }

    static CWeaponElite* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponElite>(iIndex);
    }

    static CWeaponElite* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
