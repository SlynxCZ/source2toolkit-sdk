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

class CWeaponUMP45 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponUMP45);


public:
    static CWeaponUMP45* New(const char* className)
    {
        return CBaseEntity::New<CWeaponUMP45>(className);
    }

    static CWeaponUMP45* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponUMP45>(iIndex);
    }

    static CWeaponUMP45* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
