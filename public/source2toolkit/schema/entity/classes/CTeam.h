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

class CBasePlayerController;
class CBasePlayerPawn;

class CTeam : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTeam);

    SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerController>>, m_aPlayerControllers);
    SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerPawn>>, m_aPlayers);
    SCHEMA_FIELD(int32_t, m_iScore);
    SCHEMA_FIELD_POINTER(char, m_szTeamname);

public:
    static CTeam* New(const char* className)
    {
        return CBaseEntity::New<CTeam>(className);
    }

    static CTeam* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTeam>(iIndex);
    }

    static CTeam* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
