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

class CPhysThruster : public CPhysForce
{
public:
    DECLARE_SCHEMA_CLASS(CPhysThruster);

    SCHEMA_FIELD(Vector, m_localOrigin);

public:
    static CPhysThruster* New(const char* className)
    {
        return CBaseEntity::New<CPhysThruster>(className);
    }

    static CPhysThruster* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysThruster>(iIndex);
    }

    static CPhysThruster* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
