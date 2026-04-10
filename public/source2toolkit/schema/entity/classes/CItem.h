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

class CItem : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CItem);

    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerTouch);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerPickup);
    SCHEMA_FIELD(bool, m_bActivateWhenAtRest);
    SCHEMA_FIELD(CEntityIOOutput, m_OnCacheInteraction);
    SCHEMA_FIELD(CEntityIOOutput, m_OnGlovePulled);
    SCHEMA_FIELD(Vector, m_vOriginalSpawnOrigin);
    SCHEMA_FIELD(QAngle, m_vOriginalSpawnAngles);
    SCHEMA_FIELD(bool, m_bPhysStartAsleep);

public:
    static CItem* New(const char* className)
    {
        return CBaseEntity::New<CItem>(className);
    }

    static CItem* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItem>(iIndex);
    }

    static CItem* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
