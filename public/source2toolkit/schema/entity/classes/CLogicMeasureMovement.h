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

class CLogicMeasureMovement : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicMeasureMovement);

    SCHEMA_FIELD(CUtlSymbolLarge, m_strMeasureTarget);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strMeasureReference);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strTargetReference);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hMeasureTarget);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hMeasureReference);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTarget);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hTargetReference);
    SCHEMA_FIELD(float, m_flScale);
    SCHEMA_FIELD(int32_t, m_nMeasureType);

public:
    static CLogicMeasureMovement* New(const char* className)
    {
        return CBaseEntity::New<CLogicMeasureMovement>(className);
    }

    static CLogicMeasureMovement* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicMeasureMovement>(iIndex);
    }

    static CLogicMeasureMovement* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
