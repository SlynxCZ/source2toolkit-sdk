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

#include "CBaseModelEntity.h"

class CFuncVehicleClip : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncVehicleClip);


public:
    static CFuncVehicleClip* New(const char* className)
    {
        return CBaseEntity::New<CFuncVehicleClip>(className);
    }

    static CFuncVehicleClip* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncVehicleClip>(iIndex);
    }

    static CFuncVehicleClip* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
