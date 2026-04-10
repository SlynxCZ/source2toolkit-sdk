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

#include "CPhysicsProp.h"

class CPhysicsPropOverride : public CPhysicsProp
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicsPropOverride);


public:
    static CPhysicsPropOverride* New(const char* className)
    {
        return CBaseEntity::New<CPhysicsPropOverride>(className);
    }

    static CPhysicsPropOverride* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicsPropOverride>(iIndex);
    }

    static CPhysicsPropOverride* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
