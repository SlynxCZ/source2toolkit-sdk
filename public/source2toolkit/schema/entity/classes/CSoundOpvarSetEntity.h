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

class CSoundOpvarSetEntity : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetEntity);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStackName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOperatorName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOpvarName);
    SCHEMA_FIELD(int32_t, m_nOpvarType);
    SCHEMA_FIELD(int32_t, m_nOpvarIndex);
    SCHEMA_FIELD(float, m_flOpvarValue);
    SCHEMA_FIELD(CUtlSymbolLarge, m_OpvarValueString);
    SCHEMA_FIELD(bool, m_bSetOnSpawn);

public:
    static CSoundOpvarSetEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetEntity>(className);
    }

    static CSoundOpvarSetEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetEntity>(iIndex);
    }

    static CSoundOpvarSetEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
