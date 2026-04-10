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

#include "CRulePointEntity.h"

class CGamePlayerEquip : public CRulePointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGamePlayerEquip);


public:
    static CGamePlayerEquip* New(const char* className)
    {
        return CBaseEntity::New<CGamePlayerEquip>(className);
    }

    static CGamePlayerEquip* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGamePlayerEquip>(iIndex);
    }

    static CGamePlayerEquip* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
