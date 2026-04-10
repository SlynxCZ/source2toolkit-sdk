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

#include "CRuleBrushEntity.h"

class CGamePlayerZone : public CRuleBrushEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGamePlayerZone);

    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerInZone);
    SCHEMA_FIELD(CEntityIOOutput, m_OnPlayerOutZone);

public:
    static CGamePlayerZone* New(const char* className)
    {
        return CBaseEntity::New<CGamePlayerZone>(className);
    }

    static CGamePlayerZone* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGamePlayerZone>(iIndex);
    }

    static CGamePlayerZone* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
