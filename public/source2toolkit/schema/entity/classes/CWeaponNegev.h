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

class CWeaponNegev : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponNegev);


public:
    static CWeaponNegev* New(const char* className)
    {
        return CBaseEntity::New<CWeaponNegev>(className);
    }

    static CWeaponNegev* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponNegev>(iIndex);
    }

    static CWeaponNegev* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
