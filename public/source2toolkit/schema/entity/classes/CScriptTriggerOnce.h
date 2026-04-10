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

#include "CTriggerOnce.h"

class CScriptTriggerOnce : public CTriggerOnce
{
public:
    DECLARE_SCHEMA_CLASS(CScriptTriggerOnce);

    SCHEMA_FIELD(Vector, m_vExtent);

public:
    static CScriptTriggerOnce* New(const char* className)
    {
        return CBaseEntity::New<CScriptTriggerOnce>(className);
    }

    static CScriptTriggerOnce* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CScriptTriggerOnce>(iIndex);
    }

    static CScriptTriggerOnce* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
