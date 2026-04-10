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

#include "CRuleEntity.h"

class CRulePointEntity : public CRuleEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRulePointEntity);

    SCHEMA_FIELD(int32_t, m_Score);

public:
    static CRulePointEntity* New(const char* className)
    {
        return CBaseEntity::New<CRulePointEntity>(className);
    }

    static CRulePointEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRulePointEntity>(iIndex);
    }

    static CRulePointEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
