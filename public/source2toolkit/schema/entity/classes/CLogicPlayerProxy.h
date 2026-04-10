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

class CLogicPlayerProxy : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicPlayerProxy);

    SCHEMA_FIELD(CEntityIOOutput, m_PlayerHasAmmo);
    SCHEMA_FIELD(CEntityIOOutput, m_PlayerHasNoAmmo);
    SCHEMA_FIELD(CEntityIOOutput, m_PlayerDied);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hPlayer);

public:
    static CLogicPlayerProxy* New(const char* className)
    {
        return CBaseEntity::New<CLogicPlayerProxy>(className);
    }

    static CLogicPlayerProxy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicPlayerProxy>(iIndex);
    }

    static CLogicPlayerProxy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
