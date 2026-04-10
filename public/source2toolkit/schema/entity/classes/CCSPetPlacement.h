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

#include "CBaseEntity.h"

class CCSPetPlacement : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCSPetPlacement);


public:
    static CCSPetPlacement* New(const char* className)
    {
        return CBaseEntity::New<CCSPetPlacement>(className);
    }

    static CCSPetPlacement* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPetPlacement>(iIndex);
    }

    static CCSPetPlacement* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
