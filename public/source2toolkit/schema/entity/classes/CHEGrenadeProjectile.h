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

#include "CBaseCSGrenadeProjectile.h"

class CHEGrenadeProjectile : public CBaseCSGrenadeProjectile
{
public:
    DECLARE_SCHEMA_CLASS(CHEGrenadeProjectile);


public:
    static CHEGrenadeProjectile* New(const char* className)
    {
        return CBaseEntity::New<CHEGrenadeProjectile>(className);
    }

    static CHEGrenadeProjectile* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHEGrenadeProjectile>(iIndex);
    }

    static CHEGrenadeProjectile* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
