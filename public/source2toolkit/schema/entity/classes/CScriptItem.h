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

#include "CItem.h"

class CScriptItem : public CItem
{
public:
    DECLARE_SCHEMA_CLASS(CScriptItem);

    SCHEMA_FIELD(MoveType_t, m_MoveTypeOverride);

public:
    static CScriptItem* New(const char* className)
    {
        return CBaseEntity::New<CScriptItem>(className);
    }

    static CScriptItem* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CScriptItem>(iIndex);
    }

    static CScriptItem* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
