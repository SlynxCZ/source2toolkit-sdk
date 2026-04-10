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

#include "CTriggerPush.h"

class CScriptTriggerPush : public CTriggerPush
{
public:
    DECLARE_SCHEMA_CLASS(CScriptTriggerPush);

    SCHEMA_FIELD(Vector, m_vExtent);

public:
    static CScriptTriggerPush* New(const char* className)
    {
        return CBaseEntity::New<CScriptTriggerPush>(className);
    }

    static CScriptTriggerPush* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CScriptTriggerPush>(iIndex);
    }

    static CScriptTriggerPush* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
