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

class CInfoPlayerTerrorist : public SpawnPoint
{
public:
    DECLARE_SCHEMA_CLASS(CInfoPlayerTerrorist);


public:
    static CInfoPlayerTerrorist* New(const char* className)
    {
        return CBaseEntity::New<CInfoPlayerTerrorist>(className);
    }

    static CInfoPlayerTerrorist* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoPlayerTerrorist>(iIndex);
    }

    static CInfoPlayerTerrorist* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
