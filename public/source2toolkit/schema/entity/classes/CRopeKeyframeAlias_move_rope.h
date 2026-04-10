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

#include "CRopeKeyframe.h"

class CRopeKeyframeAlias_move_rope : public CRopeKeyframe
{
public:
    DECLARE_SCHEMA_CLASS(CRopeKeyframeAlias_move_rope);


public:
    static CRopeKeyframeAlias_move_rope* New(const char* className)
    {
        return CBaseEntity::New<CRopeKeyframeAlias_move_rope>(className);
    }

    static CRopeKeyframeAlias_move_rope* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRopeKeyframeAlias_move_rope>(iIndex);
    }

    static CRopeKeyframeAlias_move_rope* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
