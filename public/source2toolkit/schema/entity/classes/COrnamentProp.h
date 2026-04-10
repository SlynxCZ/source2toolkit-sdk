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

class COrnamentProp : public CDynamicProp
{
public:
    DECLARE_SCHEMA_CLASS(COrnamentProp);

    SCHEMA_FIELD(CUtlSymbolLarge, m_initialOwner);

public:
    static COrnamentProp* New(const char* className)
    {
        return CBaseEntity::New<COrnamentProp>(className);
    }

    static COrnamentProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<COrnamentProp>(iIndex);
    }

    static COrnamentProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
