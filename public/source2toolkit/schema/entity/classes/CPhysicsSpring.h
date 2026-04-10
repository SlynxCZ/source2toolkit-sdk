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

class CPhysicsSpring : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicsSpring);

    SCHEMA_FIELD(float, m_flFrequency);
    SCHEMA_FIELD(float, m_flDampingRatio);
    SCHEMA_FIELD(float, m_flRestLength);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttachStart);
    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttachEnd);
    SCHEMA_FIELD(Vector, m_start);
    SCHEMA_FIELD(Vector, m_end);
    SCHEMA_FIELD(uint32_t, m_teleportTick);

public:
    static CPhysicsSpring* New(const char* className)
    {
        return CBaseEntity::New<CPhysicsSpring>(className);
    }

    static CPhysicsSpring* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicsSpring>(iIndex);
    }

    static CPhysicsSpring* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
