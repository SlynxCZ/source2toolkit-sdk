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

#include "CBaseEntity.h"

class CPhysicsWire : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicsWire);

    SCHEMA_FIELD(int32_t, m_nDensity);

public:
    static CPhysicsWire* New(const char* className)
    {
        return CBaseEntity::New<CPhysicsWire>(className);
    }

    static CPhysicsWire* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicsWire>(iIndex);
    }

    static CPhysicsWire* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
