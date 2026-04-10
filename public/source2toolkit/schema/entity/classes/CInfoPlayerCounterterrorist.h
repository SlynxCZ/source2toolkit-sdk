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

#include "SpawnPoint.h"

class CInfoPlayerCounterterrorist : public SpawnPoint
{
public:
    DECLARE_SCHEMA_CLASS(CInfoPlayerCounterterrorist);


public:
    static CInfoPlayerCounterterrorist* New(const char* className)
    {
        return CBaseEntity::New<CInfoPlayerCounterterrorist>(className);
    }

    static CInfoPlayerCounterterrorist* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoPlayerCounterterrorist>(iIndex);
    }

    static CInfoPlayerCounterterrorist* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
