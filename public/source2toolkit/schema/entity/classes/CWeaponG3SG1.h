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

class CWeaponG3SG1 : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponG3SG1);


public:
    static CWeaponG3SG1* New(const char* className)
    {
        return CBaseEntity::New<CWeaponG3SG1>(className);
    }

    static CWeaponG3SG1* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponG3SG1>(iIndex);
    }

    static CWeaponG3SG1* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
