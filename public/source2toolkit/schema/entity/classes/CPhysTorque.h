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

#include "CPhysForce.h"

class CPhysTorque : public CPhysForce
{
public:
    DECLARE_SCHEMA_CLASS(CPhysTorque);

    SCHEMA_FIELD(Vector, m_axis);

public:
    static CPhysTorque* New(const char* className)
    {
        return CBaseEntity::New<CPhysTorque>(className);
    }

    static CPhysTorque* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysTorque>(iIndex);
    }

    static CPhysTorque* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
