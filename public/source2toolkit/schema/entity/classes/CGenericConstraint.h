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
#include "../enums/JointMotion_t.h"

class CGenericConstraint : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CGenericConstraint);

    SCHEMA_FIELD(JointMotion_t, m_nLinearMotionX);
    SCHEMA_FIELD(JointMotion_t, m_nLinearMotionY);
    SCHEMA_FIELD(JointMotion_t, m_nLinearMotionZ);
    SCHEMA_FIELD(float, m_flLinearFrequencyX);
    SCHEMA_FIELD(float, m_flLinearFrequencyY);
    SCHEMA_FIELD(float, m_flLinearFrequencyZ);
    SCHEMA_FIELD(float, m_flLinearDampingRatioX);
    SCHEMA_FIELD(float, m_flLinearDampingRatioY);
    SCHEMA_FIELD(float, m_flLinearDampingRatioZ);
    SCHEMA_FIELD(float, m_flMaxLinearImpulseX);
    SCHEMA_FIELD(float, m_flMaxLinearImpulseY);
    SCHEMA_FIELD(float, m_flMaxLinearImpulseZ);
    SCHEMA_FIELD(float, m_flBreakAfterTimeX);
    SCHEMA_FIELD(float, m_flBreakAfterTimeY);
    SCHEMA_FIELD(float, m_flBreakAfterTimeZ);
    SCHEMA_FIELD(float, m_flBreakAfterTimeStartTimeX);
    SCHEMA_FIELD(float, m_flBreakAfterTimeStartTimeY);
    SCHEMA_FIELD(float, m_flBreakAfterTimeStartTimeZ);
    SCHEMA_FIELD(float, m_flBreakAfterTimeThresholdX);
    SCHEMA_FIELD(float, m_flBreakAfterTimeThresholdY);
    SCHEMA_FIELD(float, m_flBreakAfterTimeThresholdZ);
    SCHEMA_FIELD(float, m_flNotifyForceX);
    SCHEMA_FIELD(float, m_flNotifyForceY);
    SCHEMA_FIELD(float, m_flNotifyForceZ);
    SCHEMA_FIELD(float, m_flNotifyForceMinTimeX);
    SCHEMA_FIELD(float, m_flNotifyForceMinTimeY);
    SCHEMA_FIELD(float, m_flNotifyForceMinTimeZ);
    SCHEMA_FIELD(float, m_flNotifyForceLastTimeX);
    SCHEMA_FIELD(float, m_flNotifyForceLastTimeY);
    SCHEMA_FIELD(float, m_flNotifyForceLastTimeZ);
    SCHEMA_FIELD(bool, m_bAxisNotifiedX);
    SCHEMA_FIELD(bool, m_bAxisNotifiedY);
    SCHEMA_FIELD(bool, m_bAxisNotifiedZ);
    SCHEMA_FIELD(JointMotion_t, m_nAngularMotionX);
    SCHEMA_FIELD(JointMotion_t, m_nAngularMotionY);
    SCHEMA_FIELD(JointMotion_t, m_nAngularMotionZ);
    SCHEMA_FIELD(float, m_flAngularFrequencyX);
    SCHEMA_FIELD(float, m_flAngularFrequencyY);
    SCHEMA_FIELD(float, m_flAngularFrequencyZ);
    SCHEMA_FIELD(float, m_flAngularDampingRatioX);
    SCHEMA_FIELD(float, m_flAngularDampingRatioY);
    SCHEMA_FIELD(float, m_flAngularDampingRatioZ);
    SCHEMA_FIELD(float, m_flMaxAngularImpulseX);
    SCHEMA_FIELD(float, m_flMaxAngularImpulseY);
    SCHEMA_FIELD(float, m_flMaxAngularImpulseZ);
    SCHEMA_FIELD(CEntityIOOutput, m_NotifyForceReachedX);
    SCHEMA_FIELD(CEntityIOOutput, m_NotifyForceReachedY);
    SCHEMA_FIELD(CEntityIOOutput, m_NotifyForceReachedZ);

public:
    static CGenericConstraint* New(const char* className)
    {
        return CBaseEntity::New<CGenericConstraint>(className);
    }

    static CGenericConstraint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGenericConstraint>(iIndex);
    }

    static CGenericConstraint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
