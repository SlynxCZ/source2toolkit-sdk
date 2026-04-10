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

class CWeaponSawedoff : public CCSWeaponBaseShotgun
{
public:
    DECLARE_SCHEMA_CLASS(CWeaponSawedoff);


public:
    static CWeaponSawedoff* New(const char* className)
    {
        return CBaseEntity::New<CWeaponSawedoff>(className);
    }

    static CWeaponSawedoff* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWeaponSawedoff>(iIndex);
    }

    static CWeaponSawedoff* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
