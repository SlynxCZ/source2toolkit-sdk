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

#include "CWeaponBaseItem.h"

class CItem_Healthshot : public CWeaponBaseItem
{
public:
    DECLARE_SCHEMA_CLASS(CItem_Healthshot);


public:
    static CItem_Healthshot* New(const char* className)
    {
        return CBaseEntity::New<CItem_Healthshot>(className);
    }

    static CItem_Healthshot* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItem_Healthshot>(iIndex);
    }

    static CItem_Healthshot* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
