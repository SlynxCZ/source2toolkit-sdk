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

#include "CCSWeaponBaseShotgun.h"

class CWeaponXM1014 : public CCSWeaponBaseShotgun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponXM1014);


public:
    static CWeaponXM1014* New(const char* className)
    {
        return CBaseEntity::New<CWeaponXM1014>(className);
    }

    static CWeaponXM1014* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponXM1014>(iIndex);
    }

    static CWeaponXM1014* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
