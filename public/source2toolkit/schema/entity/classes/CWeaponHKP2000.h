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

class CWeaponHKP2000 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponHKP2000);


public:
    static CWeaponHKP2000* New(const char* className)
    {
        return CBaseEntity::New<CWeaponHKP2000>(className);
    }

    static CWeaponHKP2000* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponHKP2000>(iIndex);
    }

    static CWeaponHKP2000* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
