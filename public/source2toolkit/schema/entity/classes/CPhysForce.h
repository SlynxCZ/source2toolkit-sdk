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

#include "CConstantForceController.h"
#include "CPointEntity.h"

class CBaseEntity;

class CPhysForce : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPhysForce);

    SCHEMA_FIELD(CUtlSymbolLarge, m_nameAttach);
    SCHEMA_FIELD(float, m_force);
    SCHEMA_FIELD(float, m_forceTime);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_attachedObject);
    SCHEMA_FIELD(bool, m_wasRestored);
    SCHEMA_FIELD(CConstantForceController, m_integrator);

public:
    static CPhysForce* New(const char* className)
    {
        return CBaseEntity::New<CPhysForce>(className);
    }

    static CPhysForce* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysForce>(iIndex);
    }

    static CPhysForce* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
