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

class CTonemapTrigger : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTonemapTrigger);

    SCHEMA_FIELD(CUtlSymbolLarge, m_tonemapControllerName);
    SCHEMA_FIELD(CEntityHandle, m_hTonemapController);

public:
    static CTonemapTrigger* New(const char* className)
    {
        return CBaseEntity::New<CTonemapTrigger>(className);
    }

    static CTonemapTrigger* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTonemapTrigger>(iIndex);
    }

    static CTonemapTrigger* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
