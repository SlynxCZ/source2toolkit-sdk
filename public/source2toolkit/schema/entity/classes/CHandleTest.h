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

#include "CBaseEntity.h"

class CHandleTest : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CHandleTest);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_Handle);
    SCHEMA_FIELD(bool, m_bSendHandle);

public:
    static CHandleTest* New(const char* className)
    {
        return CBaseEntity::New<CHandleTest>(className);
    }

    static CHandleTest* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHandleTest>(iIndex);
    }

    static CHandleTest* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
