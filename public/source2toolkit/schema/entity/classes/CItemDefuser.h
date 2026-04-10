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
#include "EntitySpottedState_t.h"

class CItemDefuser : public CItem
{
public:
    DECLARE_SCHEMA_CLASS(CItemDefuser);

    SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState);
    SCHEMA_FIELD(int32_t, m_nSpotRules);

public:
    static CItemDefuser* New(const char* className)
    {
        return CBaseEntity::New<CItemDefuser>(className);
    }

    static CItemDefuser* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemDefuser>(iIndex);
    }

    static CItemDefuser* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
