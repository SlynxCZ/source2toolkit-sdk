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

#include "constraint_hingeparams_t.h"
#include "ConstraintSoundInfo.h"
#include "CPhysConstraint.h"

class CPhysHinge : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysHinge);

    SCHEMA_FIELD(ConstraintSoundInfo, m_soundInfo);
    SCHEMA_FIELD(CEntityIOOutput, m_NotifyMinLimitReached);
    SCHEMA_FIELD(CEntityIOOutput, m_NotifyMaxLimitReached);
    SCHEMA_FIELD(bool, m_bAtMinLimit);
    SCHEMA_FIELD(bool, m_bAtMaxLimit);
    SCHEMA_FIELD(constraint_hingeparams_t, m_hinge);
    SCHEMA_FIELD(float, m_hingeFriction);
    SCHEMA_FIELD(float, m_systemLoadScale);
    SCHEMA_FIELD(bool, m_bIsAxisLocal);
    SCHEMA_FIELD(float, m_flMinRotation);
    SCHEMA_FIELD(float, m_flMaxRotation);
    SCHEMA_FIELD(float, m_flInitialRotation);
    SCHEMA_FIELD(float, m_flMotorFrequency);
    SCHEMA_FIELD(float, m_flMotorDampingRatio);
    SCHEMA_FIELD(float, m_flAngleSpeed);
    SCHEMA_FIELD(float, m_flAngleSpeedThreshold);
    SCHEMA_FIELD(float, m_flLimitsDebugVisRotation);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStartMoving);
    SCHEMA_FIELD(CEntityIOOutput, m_OnStopMoving);

public:
    static CPhysHinge* New(const char* className)
    {
        return CBaseEntity::New<CPhysHinge>(className);
    }

    static CPhysHinge* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysHinge>(iIndex);
    }

    static CPhysHinge* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
