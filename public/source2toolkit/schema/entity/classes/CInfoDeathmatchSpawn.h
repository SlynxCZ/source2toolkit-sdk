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

class CInfoDeathmatchSpawn : public SpawnPoint
{
public:
    DECLARE_SCHEMA_CLASS(CInfoDeathmatchSpawn);


public:
    static CInfoDeathmatchSpawn* New(const char* className)
    {
        return CBaseEntity::New<CInfoDeathmatchSpawn>(className);
    }

    static CInfoDeathmatchSpawn* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoDeathmatchSpawn>(iIndex);
    }

    static CInfoDeathmatchSpawn* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
