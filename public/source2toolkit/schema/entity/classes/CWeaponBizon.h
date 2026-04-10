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

class CWeaponBizon : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponBizon);


public:
    static CWeaponBizon* New(const char* className)
    {
        return CBaseEntity::New<CWeaponBizon>(className);
    }

    static CWeaponBizon* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponBizon>(iIndex);
    }

    static CWeaponBizon* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
