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

class CLightOrthoEntity : public CLightEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLightOrthoEntity);


public:
    static CLightOrthoEntity* New(const char* className)
    {
        return CBaseEntity::New<CLightOrthoEntity>(className);
    }

    static CLightOrthoEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLightOrthoEntity>(iIndex);
    }

    static CLightOrthoEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
