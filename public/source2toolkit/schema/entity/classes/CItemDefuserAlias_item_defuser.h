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

#include "CItemDefuser.h"

class CItemDefuserAlias_item_defuser : public CItemDefuser
{
public:
    DECLARE_SCHEMA_CLASS(CItemDefuserAlias_item_defuser);


public:
    static CItemDefuserAlias_item_defuser* New(const char* className)
    {
        return CBaseEntity::New<CItemDefuserAlias_item_defuser>(className);
    }

    static CItemDefuserAlias_item_defuser* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemDefuserAlias_item_defuser>(iIndex);
    }

    static CItemDefuserAlias_item_defuser* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
