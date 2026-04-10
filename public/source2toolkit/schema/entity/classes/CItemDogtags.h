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

class CCSPlayerPawn;

class CItemDogtags : public CItem
{
public:
    DECLARE_SCHEMA_CLASS(CItemDogtags);

    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_OwningPlayer);
    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_KillingPlayer);

public:
    static CItemDogtags* New(const char* className)
    {
        return CBaseEntity::New<CItemDogtags>(className);
    }

    static CItemDogtags* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemDogtags>(iIndex);
    }

    static CItemDogtags* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
