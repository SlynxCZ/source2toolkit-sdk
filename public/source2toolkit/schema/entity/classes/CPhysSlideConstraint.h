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

#include "ConstraintSoundInfo.h"
#include "CPhysConstraint.h"

class CPhysSlideConstraint : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysSlideConstraint);

    SCHEMA_FIELD(Vector, m_axisEnd);
    SCHEMA_FIELD(float, m_slideFriction);
    SCHEMA_FIELD(float, m_systemLoadScale);
    SCHEMA_FIELD(float, m_initialOffset);
    SCHEMA_FIELD(bool, m_bEnableLinearConstraint);
    SCHEMA_FIELD(bool, m_bEnableAngularConstraint);
    SCHEMA_FIELD(float, m_flMotorFrequency);
    SCHEMA_FIELD(float, m_flMotorDampingRatio);
    SCHEMA_FIELD(bool, m_bUseEntityPivot);
    SCHEMA_FIELD(ConstraintSoundInfo, m_soundInfo);

public:
    static CPhysSlideConstraint* New(const char* className)
    {
        return CBaseEntity::New<CPhysSlideConstraint>(className);
    }

    static CPhysSlideConstraint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysSlideConstraint>(iIndex);
    }

    static CPhysSlideConstraint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
