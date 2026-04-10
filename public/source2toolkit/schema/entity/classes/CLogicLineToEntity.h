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

class CLogicLineToEntity : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicLineToEntity);

    SCHEMA_FIELD(CUtlSymbolLarge, m_SourceName);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_StartEntity);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_EndEntity);

public:
    static CLogicLineToEntity* New(const char* className)
    {
        return CBaseEntity::New<CLogicLineToEntity>(className);
    }

    static CLogicLineToEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicLineToEntity>(iIndex);
    }

    static CLogicLineToEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
