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

class CWeaponSSG08 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponSSG08);


public:
    static CWeaponSSG08* New(const char* className)
    {
        return CBaseEntity::New<CWeaponSSG08>(className);
    }

    static CWeaponSSG08* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponSSG08>(iIndex);
    }

    static CWeaponSSG08* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
