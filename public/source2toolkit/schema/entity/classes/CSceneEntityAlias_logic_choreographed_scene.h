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

#include "CSceneEntity.h"

class CSceneEntityAlias_logic_choreographed_scene : public CSceneEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSceneEntityAlias_logic_choreographed_scene);


public:
    static CSceneEntityAlias_logic_choreographed_scene* New(const char* className)
    {
        return CBaseEntity::New<CSceneEntityAlias_logic_choreographed_scene>(className);
    }

    static CSceneEntityAlias_logic_choreographed_scene* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSceneEntityAlias_logic_choreographed_scene>(iIndex);
    }

    static CSceneEntityAlias_logic_choreographed_scene* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
