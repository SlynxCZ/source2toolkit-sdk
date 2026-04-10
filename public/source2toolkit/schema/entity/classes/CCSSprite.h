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

class CCSSprite : public CSprite
{
public:
    DECLARE_SCHEMA_CLASS(CCSSprite);


public:
    static CCSSprite* New(const char* className)
    {
        return CBaseEntity::New<CCSSprite>(className);
    }

    static CCSSprite* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSSprite>(iIndex);
    }

    static CCSSprite* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
