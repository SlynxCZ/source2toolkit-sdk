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

#include "CLightEntity.h"

class CLightSpotEntity : public CLightEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLightSpotEntity);


public:
    static CLightSpotEntity* New(const char* className)
    {
        return CBaseEntity::New<CLightSpotEntity>(className);
    }

    static CLightSpotEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLightSpotEntity>(iIndex);
    }

    static CLightSpotEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
