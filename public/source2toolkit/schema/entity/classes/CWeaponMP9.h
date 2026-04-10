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

class CWeaponMP9 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponMP9);


public:
    static CWeaponMP9* New(const char* className)
    {
        return CBaseEntity::New<CWeaponMP9>(className);
    }

    static CWeaponMP9* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponMP9>(iIndex);
    }

    static CWeaponMP9* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
