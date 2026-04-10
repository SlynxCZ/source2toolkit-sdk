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

#include "CTriggerHurt.h"

class CScriptTriggerHurt : public CTriggerHurt
{
public:
    DECLARE_SCHEMA_CLASS(CScriptTriggerHurt);

    SCHEMA_FIELD(Vector, m_vExtent);

public:
    static CScriptTriggerHurt* New(const char* className)
    {
        return CBaseEntity::New<CScriptTriggerHurt>(className);
    }

    static CScriptTriggerHurt* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CScriptTriggerHurt>(iIndex);
    }

    static CScriptTriggerHurt* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
