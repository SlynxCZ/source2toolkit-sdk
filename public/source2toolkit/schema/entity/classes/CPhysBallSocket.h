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

class CPhysBallSocket : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysBallSocket);

    SCHEMA_FIELD(float, m_flJointFriction);
    SCHEMA_FIELD(bool, m_bEnableSwingLimit);
    SCHEMA_FIELD(float, m_flSwingLimit);
    SCHEMA_FIELD(bool, m_bEnableTwistLimit);
    SCHEMA_FIELD(float, m_flMinTwistAngle);
    SCHEMA_FIELD(float, m_flMaxTwistAngle);

public:
    static CPhysBallSocket* New(const char* className)
    {
        return CBaseEntity::New<CPhysBallSocket>(className);
    }

    static CPhysBallSocket* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysBallSocket>(iIndex);
    }

    static CPhysBallSocket* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
