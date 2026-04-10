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

#include "CLightDirectionalEntity.h"

class CLightEnvironmentEntity : public CLightDirectionalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLightEnvironmentEntity);


public:
    static CLightEnvironmentEntity* New(const char* className)
    {
        return CBaseEntity::New<CLightEnvironmentEntity>(className);
    }

    static CLightEnvironmentEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLightEnvironmentEntity>(iIndex);
    }

    static CLightEnvironmentEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
