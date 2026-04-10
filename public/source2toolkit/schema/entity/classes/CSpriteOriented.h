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

class CSpriteOriented : public CSprite
{
public:
    DECLARE_SCHEMA_CLASS(CSpriteOriented);


public:
    static CSpriteOriented* New(const char* className)
    {
        return CBaseEntity::New<CSpriteOriented>(className);
    }

    static CSpriteOriented* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSpriteOriented>(iIndex);
    }

    static CSpriteOriented* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
