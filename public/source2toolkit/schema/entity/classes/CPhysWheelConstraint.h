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

class CPhysWheelConstraint : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysWheelConstraint);

    SCHEMA_FIELD(float, m_flSuspensionFrequency);
    SCHEMA_FIELD(float, m_flSuspensionDampingRatio);
    SCHEMA_FIELD(float, m_flSuspensionHeightOffset);
    SCHEMA_FIELD(bool, m_bEnableSuspensionLimit);
    SCHEMA_FIELD(float, m_flMinSuspensionOffset);
    SCHEMA_FIELD(float, m_flMaxSuspensionOffset);
    SCHEMA_FIELD(bool, m_bEnableSteeringLimit);
    SCHEMA_FIELD(float, m_flMinSteeringAngle);
    SCHEMA_FIELD(float, m_flMaxSteeringAngle);
    SCHEMA_FIELD(float, m_flSteeringAxisFriction);
    SCHEMA_FIELD(float, m_flSpinAxisFriction);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hSteeringMimicsEntity);

public:
    static CPhysWheelConstraint* New(const char* className)
    {
        return CBaseEntity::New<CPhysWheelConstraint>(className);
    }

    static CPhysWheelConstraint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysWheelConstraint>(iIndex);
    }

    static CPhysWheelConstraint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
