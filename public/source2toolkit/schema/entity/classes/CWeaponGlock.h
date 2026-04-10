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

class CWeaponGlock : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponGlock);


public:
    static CWeaponGlock* New(const char* className)
    {
        return CBaseEntity::New<CWeaponGlock>(className);
    }

    static CWeaponGlock* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponGlock>(iIndex);
    }

    static CWeaponGlock* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
