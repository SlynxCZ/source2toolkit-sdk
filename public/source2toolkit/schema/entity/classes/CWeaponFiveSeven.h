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

class CWeaponFiveSeven : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponFiveSeven);


public:
    static CWeaponFiveSeven* New(const char* className)
    {
        return CBaseEntity::New<CWeaponFiveSeven>(className);
    }

    static CWeaponFiveSeven* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponFiveSeven>(iIndex);
    }

    static CWeaponFiveSeven* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
