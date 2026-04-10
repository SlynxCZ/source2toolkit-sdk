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

#include "CFuncTrackChange.h"

class CFuncTrackAuto : public CFuncTrackChange
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTrackAuto);


public:
    static CFuncTrackAuto* New(const char* className)
    {
        return CBaseEntity::New<CFuncTrackAuto>(className);
    }

    static CFuncTrackAuto* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTrackAuto>(iIndex);
    }

    static CFuncTrackAuto* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
