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

class CRagdollConstraint : public CPhysConstraint
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollConstraint);

    SCHEMA_FIELD(float, m_xmin);
    SCHEMA_FIELD(float, m_xmax);
    SCHEMA_FIELD(float, m_ymin);
    SCHEMA_FIELD(float, m_ymax);
    SCHEMA_FIELD(float, m_zmin);
    SCHEMA_FIELD(float, m_zmax);
    SCHEMA_FIELD(float, m_xfriction);
    SCHEMA_FIELD(float, m_yfriction);
    SCHEMA_FIELD(float, m_zfriction);

public:
    static CRagdollConstraint* New(const char* className)
    {
        return CBaseEntity::New<CRagdollConstraint>(className);
    }

    static CRagdollConstraint* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollConstraint>(iIndex);
    }

    static CRagdollConstraint* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
