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

#include "CLogicalEntity.h"

class CBaseEntity;

class CPhysicsEntitySolver : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicsEntitySolver);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hMovingEntity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hPhysicsBlocker);
    SCHEMA_FIELD(float, m_separationDuration);
    SCHEMA_FIELD(float, m_cancelTime);

public:
    static CPhysicsEntitySolver* New(const char* className)
    {
        return CBaseEntity::New<CPhysicsEntitySolver>(className);
    }

    static CPhysicsEntitySolver* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicsEntitySolver>(iIndex);
    }

    static CPhysicsEntitySolver* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
