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

#include "CBasePlayerPawn.h"
#include "../enums/CSPlayerState.h"
#include "CTouchExpansionComponent.h"

class CCSPlayer_PingServices;
class CCSPlayerController;

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerPawnBase);

    SCHEMA_FIELD(CTouchExpansionComponent, m_CTouchExpansionComponent);
    SCHEMA_FIELD(CCSPlayer_PingServices*, m_pPingServices);
    SCHEMA_FIELD(float, m_blindUntilTime);
    SCHEMA_FIELD(float, m_blindStartTime);
    SCHEMA_FIELD(CSPlayerState, m_iPlayerState);
    SCHEMA_FIELD(bool, m_bRespawning);
    SCHEMA_FIELD(bool, m_bHasMovedSinceSpawn);
    SCHEMA_FIELD(int32_t, m_iNumSpawns);
    SCHEMA_FIELD(float, m_flIdleTimeSinceLastAction);
    SCHEMA_FIELD(float, m_fNextRadarUpdateTime);
    SCHEMA_FIELD(float, m_flFlashDuration);
    SCHEMA_FIELD(float, m_flFlashMaxAlpha);
    SCHEMA_FIELD(float, m_flProgressBarStartTime);
    SCHEMA_FIELD(int32_t, m_iProgressBarDuration);
    SCHEMA_FIELD(CHandle<CCSPlayerController>, m_hOriginalController);

public:
    static CCSPlayerPawnBase* New(const char* className)
    {
        return CBaseEntity::New<CCSPlayerPawnBase>(className);
    }

    static CCSPlayerPawnBase* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPlayerPawnBase>(iIndex);
    }

    static CCSPlayerPawnBase* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
