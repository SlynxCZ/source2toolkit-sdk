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

#include "CHostageRescueZoneShim.h"

class CHostageRescueZone : public CHostageRescueZoneShim
{
public:
    DECLARE_SCHEMA_CLASS(CHostageRescueZone);


public:
    static CHostageRescueZone* New(const char* className)
    {
        return CBaseEntity::New<CHostageRescueZone>(className);
    }

    static CHostageRescueZone* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHostageRescueZone>(iIndex);
    }

    static CHostageRescueZone* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
