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

class CCommentaryViewPosition : public CSprite
{
public:
    DECLARE_SCHEMA_CLASS(CCommentaryViewPosition);


public:
    static CCommentaryViewPosition* New(const char* className)
    {
        return CBaseEntity::New<CCommentaryViewPosition>(className);
    }

    static CCommentaryViewPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCommentaryViewPosition>(iIndex);
    }

    static CCommentaryViewPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
