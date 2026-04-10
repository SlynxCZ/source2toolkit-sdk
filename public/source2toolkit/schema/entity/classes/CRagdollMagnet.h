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

class CRagdollMagnet : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRagdollMagnet);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(float, m_radius);
    SCHEMA_FIELD(float, m_force);
    SCHEMA_FIELD(Vector, m_axis);

public:
    static CRagdollMagnet* New(const char* className)
    {
        return CBaseEntity::New<CRagdollMagnet>(className);
    }

    static CRagdollMagnet* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRagdollMagnet>(iIndex);
    }

    static CRagdollMagnet* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
