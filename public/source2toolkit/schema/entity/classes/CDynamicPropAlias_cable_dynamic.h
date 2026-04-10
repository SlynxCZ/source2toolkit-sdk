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

class CDynamicPropAlias_cable_dynamic : public CDynamicProp
{
public:
    DECLARE_SCHEMA_CLASS(CDynamicPropAlias_cable_dynamic);


public:
    static CDynamicPropAlias_cable_dynamic* New(const char* className)
    {
        return CBaseEntity::New<CDynamicPropAlias_cable_dynamic>(className);
    }

    static CDynamicPropAlias_cable_dynamic* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDynamicPropAlias_cable_dynamic>(iIndex);
    }

    static CDynamicPropAlias_cable_dynamic* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
