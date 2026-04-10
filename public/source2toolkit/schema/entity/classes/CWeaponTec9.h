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

class CWeaponTec9 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponTec9);


public:
    static CWeaponTec9* New(const char* className)
    {
        return CBaseEntity::New<CWeaponTec9>(className);
    }

    static CWeaponTec9* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponTec9>(iIndex);
    }

    static CWeaponTec9* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
