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

#include "CMarkupVolumeWithRef.h"
#include "../enums/NavScopeFlags_t.h"

class CMarkupVolumeTagged_NavGame : public CMarkupVolumeWithRef
{
public:
    DECLARE_SCHEMA_CLASS(CMarkupVolumeTagged_NavGame);

    SCHEMA_FIELD(NavScopeFlags_t, m_nScopes);
    SCHEMA_FIELD(bool, m_bFloodFillAttribute);
    SCHEMA_FIELD(bool, m_bSplitNavSpace);

public:
    static CMarkupVolumeTagged_NavGame* New(const char* className)
    {
        return CBaseEntity::New<CMarkupVolumeTagged_NavGame>(className);
    }

    static CMarkupVolumeTagged_NavGame* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMarkupVolumeTagged_NavGame>(iIndex);
    }

    static CMarkupVolumeTagged_NavGame* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
