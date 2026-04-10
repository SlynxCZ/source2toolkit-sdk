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

#include "CLogicalEntity.h"

class CBaseEntity;

class CMultiSource : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CMultiSource);

    SCHEMA_FIELD_POINTER(CHandle<CBaseEntity>, m_rgEntities);
    SCHEMA_FIELD_POINTER(int32_t, m_rgTriggered);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTrigger);
    SCHEMA_FIELD(int32_t, m_iTotal);
    SCHEMA_FIELD(CUtlSymbolLarge, m_globalstate);

public:
    static CMultiSource* New(const char* className)
    {
        return CBaseEntity::New<CMultiSource>(className);
    }

    static CMultiSource* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMultiSource>(iIndex);
    }

    static CMultiSource* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
