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

class CFilterTeam : public CBaseFilter
{
public:
    DECLARE_SCHEMA_CLASS(CFilterTeam);

    SCHEMA_FIELD(int32_t, m_iFilterTeam);

public:
    static CFilterTeam* New(const char* className)
    {
        return CBaseEntity::New<CFilterTeam>(className);
    }

    static CFilterTeam* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFilterTeam>(iIndex);
    }

    static CFilterTeam* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
