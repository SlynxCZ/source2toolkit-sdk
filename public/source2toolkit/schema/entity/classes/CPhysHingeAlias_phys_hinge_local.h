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

#include "CPhysHinge.h"

class CPhysHingeAlias_phys_hinge_local : public CPhysHinge
{
public:
    DECLARE_SCHEMA_CLASS(CPhysHingeAlias_phys_hinge_local);


public:
    static CPhysHingeAlias_phys_hinge_local* New(const char* className)
    {
        return CBaseEntity::New<CPhysHingeAlias_phys_hinge_local>(className);
    }

    static CPhysHingeAlias_phys_hinge_local* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysHingeAlias_phys_hinge_local>(iIndex);
    }

    static CPhysHingeAlias_phys_hinge_local* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
