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

#include "CDynamicProp.h"

class CDynamicPropAlias_dynamic_prop : public CDynamicProp
{
public:
    DECLARE_SCHEMA_CLASS(CDynamicPropAlias_dynamic_prop);


public:
    static CDynamicPropAlias_dynamic_prop* New(const char* className)
    {
        return CBaseEntity::New<CDynamicPropAlias_dynamic_prop>(className);
    }

    static CDynamicPropAlias_dynamic_prop* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDynamicPropAlias_dynamic_prop>(iIndex);
    }

    static CDynamicPropAlias_dynamic_prop* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
