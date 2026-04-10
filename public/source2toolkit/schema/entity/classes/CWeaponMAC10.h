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

class CWeaponMAC10 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponMAC10);


public:
    static CWeaponMAC10* New(const char* className)
    {
        return CBaseEntity::New<CWeaponMAC10>(className);
    }

    static CWeaponMAC10* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponMAC10>(iIndex);
    }

    static CWeaponMAC10* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
