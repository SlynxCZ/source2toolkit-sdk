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

class CWeaponSG556 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponSG556);


public:
    static CWeaponSG556* New(const char* className)
    {
        return CBaseEntity::New<CWeaponSG556>(className);
    }

    static CWeaponSG556* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponSG556>(iIndex);
    }

    static CWeaponSG556* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
