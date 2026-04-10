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

class CGameMoney : public CRulePointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGameMoney);

    SCHEMA_FIELD(CEntityIOOutput, m_OnMoneySpent);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMoneySpentFail);
    SCHEMA_FIELD(int32_t, m_nMoney);
    SCHEMA_FIELD(CUtlString, m_strAwardText);

public:
    static CGameMoney* New(const char* className)
    {
        return CBaseEntity::New<CGameMoney>(className);
    }

    static CGameMoney* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGameMoney>(iIndex);
    }

    static CGameMoney* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
