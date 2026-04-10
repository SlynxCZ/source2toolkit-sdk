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

#include "CSprite.h"

class CSpriteAlias_env_glow : public CSprite
{
public:
    DECLARE_SCHEMA_CLASS(CSpriteAlias_env_glow);


public:
    static CSpriteAlias_env_glow* New(const char* className)
    {
        return CBaseEntity::New<CSpriteAlias_env_glow>(className);
    }

    static CSpriteAlias_env_glow* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSpriteAlias_env_glow>(iIndex);
    }

    static CSpriteAlias_env_glow* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
