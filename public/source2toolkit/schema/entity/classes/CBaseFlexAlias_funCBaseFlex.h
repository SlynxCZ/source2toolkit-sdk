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

#include "CBaseFlex.h"

class CBaseFlexAlias_funCBaseFlex : public CBaseFlex
{
public:
    DECLARE_SCHEMA_CLASS(CBaseFlexAlias_funCBaseFlex);


public:
    static CBaseFlexAlias_funCBaseFlex* New(const char* className)
    {
        return CBaseEntity::New<CBaseFlexAlias_funCBaseFlex>(className);
    }

    static CBaseFlexAlias_funCBaseFlex* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseFlexAlias_funCBaseFlex>(iIndex);
    }

    static CBaseFlexAlias_funCBaseFlex* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
