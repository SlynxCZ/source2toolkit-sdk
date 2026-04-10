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

#include "CFuncLadder.h"

class CFuncLadderAlias_func_useableladder : public CFuncLadder
{
public:
    DECLARE_SCHEMA_CLASS(CFuncLadderAlias_func_useableladder);


public:
    static CFuncLadderAlias_func_useableladder* New(const char* className)
    {
        return CBaseEntity::New<CFuncLadderAlias_func_useableladder>(className);
    }

    static CFuncLadderAlias_func_useableladder* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncLadderAlias_func_useableladder>(iIndex);
    }

    static CFuncLadderAlias_func_useableladder* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
