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

#include "CTonemapController2.h"

class CTonemapController2Alias_env_tonemap_controller2 : public CTonemapController2
{
public:
    DECLARE_SCHEMA_CLASS(CTonemapController2Alias_env_tonemap_controller2);


public:
    static CTonemapController2Alias_env_tonemap_controller2* New(const char* className)
    {
        return CBaseEntity::New<CTonemapController2Alias_env_tonemap_controller2>(className);
    }

    static CTonemapController2Alias_env_tonemap_controller2* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTonemapController2Alias_env_tonemap_controller2>(iIndex);
    }

    static CTonemapController2Alias_env_tonemap_controller2* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
