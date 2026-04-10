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
#include "../enums/RotatorTargetSpace_t.h"

class CRotatorTarget : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CRotatorTarget);

    SCHEMA_FIELD(CEntityIOOutput, m_OnArrivedAt);
    SCHEMA_FIELD(RotatorTargetSpace_t, m_eSpace);

public:
    static CRotatorTarget* New(const char* className)
    {
        return CBaseEntity::New<CRotatorTarget>(className);
    }

    static CRotatorTarget* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRotatorTarget>(iIndex);
    }

    static CRotatorTarget* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
