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

class CGameGibManager : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CGameGibManager);

    SCHEMA_FIELD(bool, m_bAllowNewGibs);
    SCHEMA_FIELD(int32_t, m_iCurrentMaxPieces);
    SCHEMA_FIELD(int32_t, m_iMaxPieces);
    SCHEMA_FIELD(int32_t, m_iLastFrame);

public:
    static CGameGibManager* New(const char* className)
    {
        return CBaseEntity::New<CGameGibManager>(className);
    }

    static CGameGibManager* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CGameGibManager>(iIndex);
    }

    static CGameGibManager* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
