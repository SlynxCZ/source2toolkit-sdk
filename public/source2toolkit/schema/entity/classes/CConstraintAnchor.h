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

class CConstraintAnchor : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CConstraintAnchor);

    SCHEMA_FIELD(float, m_massScale);

public:
    static CConstraintAnchor* New(const char* className)
    {
        return CBaseEntity::New<CConstraintAnchor>(className);
    }

    static CConstraintAnchor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CConstraintAnchor>(iIndex);
    }

    static CConstraintAnchor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
