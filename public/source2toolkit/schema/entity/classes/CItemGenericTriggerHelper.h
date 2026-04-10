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

#include "CBaseModelEntity.h"

class CItemGeneric;

class CItemGenericTriggerHelper : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CItemGenericTriggerHelper);

    SCHEMA_FIELD(CHandle<CItemGeneric>, m_hParentItem);

public:
    static CItemGenericTriggerHelper* New(const char* className)
    {
        return CBaseEntity::New<CItemGenericTriggerHelper>(className);
    }

    static CItemGenericTriggerHelper* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemGenericTriggerHelper>(iIndex);
    }

    static CItemGenericTriggerHelper* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
