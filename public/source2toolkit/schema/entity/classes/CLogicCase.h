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

class CLogicCase : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicCase);

    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_nCase);
    SCHEMA_FIELD(int32_t, m_nShuffleCases);
    SCHEMA_FIELD(int32_t, m_nLastShuffleCase);
    SCHEMA_FIELD_POINTER(uint8_t, m_uchShuffleCaseMap);
    SCHEMA_FIELD_POINTER(CEntityIOOutput, m_OnCase);

public:
    static CLogicCase* New(const char* className)
    {
        return CBaseEntity::New<CLogicCase>(className);
    }

    static CLogicCase* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicCase>(iIndex);
    }

    static CLogicCase* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
