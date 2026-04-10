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

#include "CHostage.h"

class CHostageAlias_info_hostage_spawn : public CHostage
{
public:
    DECLARE_SCHEMA_CLASS(CHostageAlias_info_hostage_spawn);


public:
    static CHostageAlias_info_hostage_spawn* New(const char* className)
    {
        return CBaseEntity::New<CHostageAlias_info_hostage_spawn>(className);
    }

    static CHostageAlias_info_hostage_spawn* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHostageAlias_info_hostage_spawn>(iIndex);
    }

    static CHostageAlias_info_hostage_spawn* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
