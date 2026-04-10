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

#include "CBaseAnimGraph.h"

class CItemSoda : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CItemSoda);


public:
    static CItemSoda* New(const char* className)
    {
        return CBaseEntity::New<CItemSoda>(className);
    }

    static CItemSoda* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemSoda>(iIndex);
    }

    static CItemSoda* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
