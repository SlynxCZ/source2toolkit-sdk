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

#include "CFuncWall.h"

class CFuncWallToggle : public CFuncWall
{
public:
    DECLARE_SCHEMA_CLASS(CFuncWallToggle);


public:
    static CFuncWallToggle* New(const char* className)
    {
        return CBaseEntity::New<CFuncWallToggle>(className);
    }

    static CFuncWallToggle* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncWallToggle>(iIndex);
    }

    static CFuncWallToggle* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
