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

#include "CAttributeContainer.h"
#include "CBaseAnimGraph.h"
#include "EntitySpottedState_t.h"

class CCSPlayerPawn;

class CPlantedC4 : public CBaseAnimGraph
{
public:
    DECLARE_SCHEMA_CLASS(CPlantedC4);

    SCHEMA_FIELD(bool, m_bBombTicking);
    SCHEMA_FIELD(float, m_flC4Blow);
    SCHEMA_FIELD(int32_t, m_nBombSite);
    SCHEMA_FIELD(int32_t, m_nSourceSoundscapeHash);
    SCHEMA_FIELD(bool, m_bAbortDetonationBecauseWorldIsFrozen);
    SCHEMA_FIELD(CAttributeContainer, m_AttributeManager);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBombDefused);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBombBeginDefuse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnBombDefuseAborted);
    SCHEMA_FIELD(bool, m_bCannotBeDefused);
    SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState);
    SCHEMA_FIELD(int32_t, m_nSpotRules);
    SCHEMA_FIELD(bool, m_bHasExploded);
    SCHEMA_FIELD(bool, m_bBombDefused);
    SCHEMA_FIELD(bool, m_bTrainingPlacedByPlayer);
    SCHEMA_FIELD(float, m_flTimerLength);
    SCHEMA_FIELD(bool, m_bBeingDefused);
    SCHEMA_FIELD(float, m_fLastDefuseTime);
    SCHEMA_FIELD(float, m_flDefuseLength);
    SCHEMA_FIELD(float, m_flDefuseCountDown);
    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_hBombDefuser);
    SCHEMA_FIELD(int32_t, m_iProgressBarTime);
    SCHEMA_FIELD(bool, m_bVoiceAlertFired);
    SCHEMA_FIELD_POINTER(bool, m_bVoiceAlertPlayed);
    SCHEMA_FIELD(float, m_flNextBotBeepTime);
    SCHEMA_FIELD(QAngle, m_angCatchUpToPlayerEye);
    SCHEMA_FIELD(float, m_flLastSpinDetectionTime);

public:
    static CPlantedC4* New(const char* className)
    {
        return CBaseEntity::New<CPlantedC4>(className);
    }

    static CPlantedC4* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPlantedC4>(iIndex);
    }

    static CPlantedC4* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
