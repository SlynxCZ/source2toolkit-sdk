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

#include "CBaseFilter.h"

class CFilterMassGreater : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterMassGreater);

    SCHEMA_FIELD(float, m_fFilterMass);

public:
    static CFilterMassGreater* New(const char* className)
    {
        return CBaseEntity::New<CFilterMassGreater>(className);
    }

    static CFilterMassGreater* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterMassGreater>(iIndex);
    }

    static CFilterMassGreater* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
