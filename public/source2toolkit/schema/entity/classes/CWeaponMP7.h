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

class CWeaponMP7 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponMP7);


public:
    static CWeaponMP7* New(const char* className)
    {
        return CBaseEntity::New<CWeaponMP7>(className);
    }

    static CWeaponMP7* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponMP7>(iIndex);
    }

    static CWeaponMP7* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
