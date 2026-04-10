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

#include "CRagdollProp.h"

class CRagdollPropAlias_physics_prop_ragdoll : public CRagdollProp
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollPropAlias_physics_prop_ragdoll);


public:
    static CRagdollPropAlias_physics_prop_ragdoll* New(const char* className)
    {
        return CBaseEntity::New<CRagdollPropAlias_physics_prop_ragdoll>(className);
    }

    static CRagdollPropAlias_physics_prop_ragdoll* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollPropAlias_physics_prop_ragdoll>(iIndex);
    }

    static CRagdollPropAlias_physics_prop_ragdoll* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
