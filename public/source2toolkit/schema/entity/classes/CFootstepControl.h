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

#include "CBaseTrigger.h"

class CFootstepControl : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CFootstepControl);

    SCHEMA_FIELD(CUtlSymbolLarge, m_source);
    SCHEMA_FIELD(CUtlSymbolLarge, m_destination);

public:
    static CFootstepControl* New(const char* className)
    {
        return CBaseEntity::New<CFootstepControl>(className);
    }

    static CFootstepControl* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFootstepControl>(iIndex);
    }

    static CFootstepControl* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
