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

class CSoundOpvarSetPointBase : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetPointBase);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CEntityHandle, m_hSource);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSourceEntityName);
    SCHEMA_FIELD(Vector, m_vLastPosition);
    SCHEMA_FIELD(float, m_flRefreshTime);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStackName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOperatorName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOpvarName);
    SCHEMA_FIELD(int32_t, m_iOpvarIndex);
    SCHEMA_FIELD(bool, m_bUseAutoCompare);
    SCHEMA_FIELD(bool, m_bFastRefresh);

public:
    static CSoundOpvarSetPointBase* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetPointBase>(className);
    }

    static CSoundOpvarSetPointBase* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetPointBase>(iIndex);
    }

    static CSoundOpvarSetPointBase* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
