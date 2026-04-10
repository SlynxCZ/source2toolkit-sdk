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

#include "CBaseModelEntity.h"

class CLightComponent;

class CLightEntity : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLightEntity);

    SCHEMA_FIELD(CLightComponent*, m_CLightComponent);

public:
    static CLightEntity* New(const char* className)
    {
        return CBaseEntity::New<CLightEntity>(className);
    }

    static CLightEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLightEntity>(iIndex);
    }

    static CLightEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
