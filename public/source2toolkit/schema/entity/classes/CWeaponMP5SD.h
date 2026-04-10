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

class CWeaponMP5SD : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponMP5SD);


public:
    static CWeaponMP5SD* New(const char* className)
    {
        return CBaseEntity::New<CWeaponMP5SD>(className);
    }

    static CWeaponMP5SD* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponMP5SD>(iIndex);
    }

    static CWeaponMP5SD* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
