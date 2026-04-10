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

#include "CBaseAnimGraph.h"

class CWaterBullet : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CWaterBullet);


public:
    static CWaterBullet* New(const char* className)
    {
        return CBaseEntity::New<CWaterBullet>(className);
    }

    static CWaterBullet* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CWaterBullet>(iIndex);
    }

    static CWaterBullet* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
