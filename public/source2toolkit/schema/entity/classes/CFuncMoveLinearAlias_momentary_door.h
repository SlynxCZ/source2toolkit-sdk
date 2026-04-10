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

#include "CFuncMoveLinear.h"

class CFuncMoveLinearAlias_momentary_door : public CFuncMoveLinear
{
public:
    DECLARE_SCHEMA_CLASS(CFuncMoveLinearAlias_momentary_door);


public:
    static CFuncMoveLinearAlias_momentary_door* New(const char* className)
    {
        return CBaseEntity::New<CFuncMoveLinearAlias_momentary_door>(className);
    }

    static CFuncMoveLinearAlias_momentary_door* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncMoveLinearAlias_momentary_door>(iIndex);
    }

    static CFuncMoveLinearAlias_momentary_door* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
