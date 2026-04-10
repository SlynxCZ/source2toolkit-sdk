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

#include "CDynamicProp.h"

class CFuncRetakeBarrier : public CDynamicProp
{
public:
    DECLARE_SCHEMA_CLASS(CFuncRetakeBarrier);


public:
    static CFuncRetakeBarrier* New(const char* className)
    {
        return CBaseEntity::New<CFuncRetakeBarrier>(className);
    }

    static CFuncRetakeBarrier* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncRetakeBarrier>(iIndex);
    }

    static CFuncRetakeBarrier* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
