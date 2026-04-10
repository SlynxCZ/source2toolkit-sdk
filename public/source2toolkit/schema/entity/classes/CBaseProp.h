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

#include "CBaseAnimGraph.h"

class CBaseProp : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CBaseProp);

    SCHEMA_FIELD(bool, m_bModelOverrodeBlockLOS);
    SCHEMA_FIELD(int32_t, m_iShapeType);
    SCHEMA_FIELD(bool, m_bConformToCollisionBounds);
    SCHEMA_FIELD(CTransform, m_mPreferredCatchTransform);

public:
    static CBaseProp* New(const char* className)
    {
        return CBaseEntity::New<CBaseProp>(className);
    }

    static CBaseProp* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseProp>(iIndex);
    }

    static CBaseProp* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
