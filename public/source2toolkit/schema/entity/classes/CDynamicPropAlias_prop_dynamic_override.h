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

class CDynamicPropAlias_prop_dynamic_override : public CDynamicProp
{
public:
    DECLARE_SCHEMA_CLASS(CDynamicPropAlias_prop_dynamic_override);


public:
    static CDynamicPropAlias_prop_dynamic_override* New(const char* className)
    {
        return CBaseEntity::New<CDynamicPropAlias_prop_dynamic_override>(className);
    }

    static CDynamicPropAlias_prop_dynamic_override* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDynamicPropAlias_prop_dynamic_override>(iIndex);
    }

    static CDynamicPropAlias_prop_dynamic_override* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
