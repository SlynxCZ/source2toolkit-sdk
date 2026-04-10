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

#include "CMarkupVolumeTagged.h"
#include "../enums/NavScopeFlags_t.h"

class CMarkupVolumeTagged_Nav : public CMarkupVolumeTagged
{
public:
    DECLARE_SCHEMA_CLASS(CMarkupVolumeTagged_Nav);

    SCHEMA_FIELD(NavScopeFlags_t, m_nScopes);

public:
    static CMarkupVolumeTagged_Nav* New(const char* className)
    {
        return CBaseEntity::New<CMarkupVolumeTagged_Nav>(className);
    }

    static CMarkupVolumeTagged_Nav* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMarkupVolumeTagged_Nav>(iIndex);
    }

    static CMarkupVolumeTagged_Nav* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
