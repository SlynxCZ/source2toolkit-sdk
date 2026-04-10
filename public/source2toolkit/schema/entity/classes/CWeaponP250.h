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

class CWeaponP250 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponP250);


public:
    static CWeaponP250* New(const char* className)
    {
        return CBaseEntity::New<CWeaponP250>(className);
    }

    static CWeaponP250* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponP250>(iIndex);
    }

    static CWeaponP250* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
