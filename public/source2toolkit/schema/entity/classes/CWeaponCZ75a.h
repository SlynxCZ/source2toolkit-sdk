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

class CWeaponCZ75a : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponCZ75a);

    SCHEMA_FIELD(bool, m_bMagazineRemoved);

public:
    static CWeaponCZ75a* New(const char* className)
    {
        return CBaseEntity::New<CWeaponCZ75a>(className);
    }

    static CWeaponCZ75a* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponCZ75a>(iIndex);
    }

    static CWeaponCZ75a* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
