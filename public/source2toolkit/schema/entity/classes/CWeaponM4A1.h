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

class CWeaponM4A1 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponM4A1);


public:
    static CWeaponM4A1* New(const char* className)
    {
        return CBaseEntity::New<CWeaponM4A1>(className);
    }

    static CWeaponM4A1* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponM4A1>(iIndex);
    }

    static CWeaponM4A1* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
