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

#include "CBaseModelEntity.h"

class CRuleEntity : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRuleEntity);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszMaster);

public:
    static CRuleEntity* New(const char* className)
    {
        return CBaseEntity::New<CRuleEntity>(className);
    }

    static CRuleEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRuleEntity>(iIndex);
    }

    static CRuleEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
