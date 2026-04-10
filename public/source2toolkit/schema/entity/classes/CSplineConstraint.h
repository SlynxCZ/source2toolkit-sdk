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

#include "CPhysConstraint.h"

class CBaseEntity;

class CSplineConstraint : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CSplineConstraint);

    SCHEMA_FIELD(Vector, m_vAnchorOffsetRestore);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hSplineEntity);
    SCHEMA_FIELD(bool, m_bEnableLateralConstraint);
    SCHEMA_FIELD(bool, m_bEnableVerticalConstraint);
    SCHEMA_FIELD(bool, m_bEnableAngularConstraint);
    SCHEMA_FIELD(bool, m_bEnableLimit);
    SCHEMA_FIELD(bool, m_bFireEventsOnPath);
    SCHEMA_FIELD(float, m_flLinearFrequency);
    SCHEMA_FIELD(float, m_flLinarDampingRatio);
    SCHEMA_FIELD(float, m_flJointFriction);
    SCHEMA_FIELD(float, m_flTransitionTime);
    SCHEMA_FIELD(Vector, m_vPreSolveAnchorPos);
    SCHEMA_FIELD(float, m_StartTransitionTime);
    SCHEMA_FIELD(Vector, m_vTangentSpaceAnchorAtTransitionStart);

public:
    static CSplineConstraint* New(const char* className)
    {
        return CBaseEntity::New<CSplineConstraint>(className);
    }

    static CSplineConstraint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSplineConstraint>(iIndex);
    }

    static CSplineConstraint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
