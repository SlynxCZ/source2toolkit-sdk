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

class CCSPlayerPawn;

class CPlayerPing : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPlayerPing);

    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_hPlayer);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hPingedEntity);
    SCHEMA_FIELD(int32_t, m_iType);
    SCHEMA_FIELD(bool, m_bUrgent);
    SCHEMA_FIELD_POINTER(char, m_szPlaceName);

public:
    static CPlayerPing* New(const char* className)
    {
        return CBaseEntity::New<CPlayerPing>(className);
    }

    static CPlayerPing* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPlayerPing>(iIndex);
    }

    static CPlayerPing* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
