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

class CRuleBrushEntity : public CRuleEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRuleBrushEntity);


public:
    static CRuleBrushEntity* New(const char* className)
    {
        return CBaseEntity::New<CRuleBrushEntity>(className);
    }

    static CRuleBrushEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRuleBrushEntity>(iIndex);
    }

    static CRuleBrushEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
