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

class CPhysPulley : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysPulley);

    SCHEMA_FIELD(Vector, m_position2);
    SCHEMA_FIELD_POINTER(Vector, m_offset);
    SCHEMA_FIELD(float, m_addLength);
    SCHEMA_FIELD(float, m_gearRatio);

public:
    static CPhysPulley* New(const char* className)
    {
        return CBaseEntity::New<CPhysPulley>(className);
    }

    static CPhysPulley* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysPulley>(iIndex);
    }

    static CPhysPulley* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
