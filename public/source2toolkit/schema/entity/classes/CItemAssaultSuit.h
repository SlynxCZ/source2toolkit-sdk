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

#include "CItem.h"

class CItemAssaultSuit : public CItem
{
public:
    DECLARE_SCHEMA_CLASS(CItemAssaultSuit);


public:
    static CItemAssaultSuit* New(const char* className)
    {
        return CBaseEntity::New<CItemAssaultSuit>(className);
    }

    static CItemAssaultSuit* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemAssaultSuit>(iIndex);
    }

    static CItemAssaultSuit* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
