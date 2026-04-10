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

class CPhysFixed : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysFixed);

    SCHEMA_FIELD(float, m_flLinearFrequency);
    SCHEMA_FIELD(float, m_flLinearDampingRatio);
    SCHEMA_FIELD(float, m_flAngularFrequency);
    SCHEMA_FIELD(float, m_flAngularDampingRatio);
    SCHEMA_FIELD(bool, m_bEnableLinearConstraint);
    SCHEMA_FIELD(bool, m_bEnableAngularConstraint);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sBoneName1);
    SCHEMA_FIELD(CUtlSymbolLarge, m_sBoneName2);

public:
    static CPhysFixed* New(const char* className)
    {
        return CBaseEntity::New<CPhysFixed>(className);
    }

    static CPhysFixed* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysFixed>(iIndex);
    }

    static CPhysFixed* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
