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

class CPhysLength : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CPhysLength);

    SCHEMA_FIELD_POINTER(Vector, m_offset);
    SCHEMA_FIELD(Vector, m_vecAttach);
    SCHEMA_FIELD(float, m_addLength);
    SCHEMA_FIELD(float, m_minLength);
    SCHEMA_FIELD(float, m_totalLength);

public:
    static CPhysLength* New(const char* className)
    {
        return CBaseEntity::New<CPhysLength>(className);
    }

    static CPhysLength* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysLength>(iIndex);
    }

    static CPhysLength* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
