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

class CWeaponP90 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponP90);


public:
    static CWeaponP90* New(const char* className)
    {
        return CBaseEntity::New<CWeaponP90>(className);
    }

    static CWeaponP90* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponP90>(iIndex);
    }

    static CWeaponP90* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
