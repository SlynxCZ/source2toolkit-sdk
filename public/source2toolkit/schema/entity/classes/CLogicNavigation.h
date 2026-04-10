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

#include "CLogicalEntity.h"
#include "../enums/navproperties_t.h"

class CLogicNavigation : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicNavigation);

    SCHEMA_FIELD(bool, m_isOn);
    SCHEMA_FIELD(navproperties_t, m_navProperty);

public:
    static CLogicNavigation* New(const char* className)
    {
        return CBaseEntity::New<CLogicNavigation>(className);
    }

    static CLogicNavigation* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicNavigation>(iIndex);
    }

    static CLogicNavigation* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
