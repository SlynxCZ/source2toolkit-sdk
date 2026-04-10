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

class CLightDirectionalEntity : public CLightEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLightDirectionalEntity);


public:
    static CLightDirectionalEntity* New(const char* className)
    {
        return CBaseEntity::New<CLightDirectionalEntity>(className);
    }

    static CLightDirectionalEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLightDirectionalEntity>(iIndex);
    }

    static CLightDirectionalEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
