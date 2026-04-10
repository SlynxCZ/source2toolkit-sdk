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

#include "CPointEntity.h"

class CPhysImpact : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysImpact);

    SCHEMA_FIELD(float, m_damage);
    SCHEMA_FIELD(float, m_distance);
    SCHEMA_FIELD(CUtlSymbolLarge, m_directionEntityName);

public:
    static CPhysImpact* New(const char* className)
    {
        return CBaseEntity::New<CPhysImpact>(className);
    }

    static CPhysImpact* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysImpact>(iIndex);
    }

    static CPhysImpact* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
