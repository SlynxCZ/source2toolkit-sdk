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

class CDEagle : public CCSWeaponBaseGun
{
public:
    DECLARE_SCHEMA_CLASS(CDEagle);


public:
    static CDEagle* New(const char* className)
    {
        return CBaseEntity::New<CDEagle>(className);
    }

    static CDEagle* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDEagle>(iIndex);
    }

    static CDEagle* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
