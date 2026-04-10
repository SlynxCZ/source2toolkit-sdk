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

#include "CBaseTrigger.h"

class CTriggerPhysics : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerPhysics);

    SCHEMA_FIELD(float, m_gravityScale);
    SCHEMA_FIELD(float, m_linearLimit);
    SCHEMA_FIELD(float, m_linearDamping);
    SCHEMA_FIELD(float, m_angularLimit);
    SCHEMA_FIELD(float, m_angularDamping);
    SCHEMA_FIELD(float, m_linearForce);
    SCHEMA_FIELD(float, m_flFrequency);
    SCHEMA_FIELD(float, m_flDampingRatio);
    SCHEMA_FIELD(Vector, m_vecLinearForcePointAt);
    SCHEMA_FIELD(bool, m_bCollapseToForcePoint);
    SCHEMA_FIELD(Vector, m_vecLinearForcePointAtWorld);
    SCHEMA_FIELD(Vector, m_vecLinearForceDirection);
    SCHEMA_FIELD(bool, m_bConvertToDebrisWhenPossible);

public:
    static CTriggerPhysics* New(const char* className)
    {
        return CBaseEntity::New<CTriggerPhysics>(className);
    }

    static CTriggerPhysics* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerPhysics>(iIndex);
    }

    static CTriggerPhysics* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
