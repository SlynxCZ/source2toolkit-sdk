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

#include "CBaseEntity.h"

class CFuncPropRespawnZone : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncPropRespawnZone);


public:
    static CFuncPropRespawnZone* New(const char* className)
    {
        return CBaseEntity::New<CFuncPropRespawnZone>(className);
    }

    static CFuncPropRespawnZone* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncPropRespawnZone>(iIndex);
    }

    static CFuncPropRespawnZone* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
