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

class CGameEnd : public CRulePointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGameEnd);


public:
    static CGameEnd* New(const char* className)
    {
        return CBaseEntity::New<CGameEnd>(className);
    }

    static CGameEnd* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGameEnd>(iIndex);
    }

    static CGameEnd* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
