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

#include "CTriggerMultiple.h"

class CScriptTriggerMultiple : public CTriggerMultiple
{
public:
    DECLARE_SCHEMA_CLASS(CScriptTriggerMultiple);

    SCHEMA_FIELD(Vector, m_vExtent);

public:
    static CScriptTriggerMultiple* New(const char* className)
    {
        return CBaseEntity::New<CScriptTriggerMultiple>(className);
    }

    static CScriptTriggerMultiple* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CScriptTriggerMultiple>(iIndex);
    }

    static CScriptTriggerMultiple* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
