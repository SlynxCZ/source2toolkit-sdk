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

#include "CPhysicsProp.h"

class CPhysicsPropRespawnable : public CPhysicsProp
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicsPropRespawnable);

    SCHEMA_FIELD(Vector, m_vOriginalSpawnOrigin);
    SCHEMA_FIELD(QAngle, m_vOriginalSpawnAngles);
    SCHEMA_FIELD(Vector, m_vOriginalMins);
    SCHEMA_FIELD(Vector, m_vOriginalMaxs);
    SCHEMA_FIELD(float, m_flRespawnDuration);

public:
    static CPhysicsPropRespawnable* New(const char* className)
    {
        return CBaseEntity::New<CPhysicsPropRespawnable>(className);
    }

    static CPhysicsPropRespawnable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicsPropRespawnable>(iIndex);
    }

    static CPhysicsPropRespawnable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
