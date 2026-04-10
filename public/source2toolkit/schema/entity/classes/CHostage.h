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

#include "CountdownTimer.h"
#include "EntitySpottedState_t.h"
#include "CHostageExpresserShim.h"

class CBaseEntity;
class CCSPlayerPawn;
class CCSPlayerPawnBase;

class CHostage : public CHostageExpresserShim
{
public:
    DECLARE_SCHEMA_CLASS(CHostage);

    SCHEMA_FIELD(CEntityIOOutput, m_OnHostageBeginGrab);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFirstPickedUp);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDroppedNotRescued);
    SCHEMA_FIELD(CEntityIOOutput, m_OnRescued);
    SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState);
    SCHEMA_FIELD(int32_t, m_nSpotRules);
    SCHEMA_FIELD(uint32_t, m_uiHostageSpawnExclusionGroupMask);
    SCHEMA_FIELD(uint32_t, m_nHostageSpawnRandomFactor);
    SCHEMA_FIELD(bool, m_bRemove);
    SCHEMA_FIELD(Vector, m_vel);
    SCHEMA_FIELD(bool, m_isRescued);
    SCHEMA_FIELD(bool, m_jumpedThisFrame);
    SCHEMA_FIELD(int32_t, m_nHostageState);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_leader);
    SCHEMA_FIELD(CHandle<CCSPlayerPawnBase>, m_lastLeader);
    SCHEMA_FIELD(CountdownTimer, m_reuseTimer);
    SCHEMA_FIELD(bool, m_hasBeenUsed);
    SCHEMA_FIELD(Vector, m_accel);
    SCHEMA_FIELD(bool, m_isRunning);
    SCHEMA_FIELD(bool, m_isCrouching);
    SCHEMA_FIELD(CountdownTimer, m_jumpTimer);
    SCHEMA_FIELD(bool, m_isWaitingForLeader);
    SCHEMA_FIELD(CountdownTimer, m_repathTimer);
    SCHEMA_FIELD(CountdownTimer, m_inhibitDoorTimer);
    SCHEMA_FIELD(CountdownTimer, m_inhibitObstacleAvoidanceTimer);
    SCHEMA_FIELD(CountdownTimer, m_wiggleTimer);
    SCHEMA_FIELD(bool, m_isAdjusted);
    SCHEMA_FIELD(bool, m_bHandsHaveBeenCut);
    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_hHostageGrabber);
    SCHEMA_FIELD(float, m_fLastGrabTime);
    SCHEMA_FIELD(Vector, m_vecPositionWhenStartedDroppingToGround);
    SCHEMA_FIELD(Vector, m_vecGrabbedPos);
    SCHEMA_FIELD(float, m_flRescueStartTime);
    SCHEMA_FIELD(float, m_flGrabSuccessTime);
    SCHEMA_FIELD(float, m_flDropStartTime);
    SCHEMA_FIELD(int32_t, m_nApproachRewardPayouts);
    SCHEMA_FIELD(int32_t, m_nPickupEventCount);
    SCHEMA_FIELD(Vector, m_vecSpawnGroundPos);
    SCHEMA_FIELD(Vector, m_vecHostageResetPosition);

public:
    static CHostage* New(const char* className)
    {
        return CBaseEntity::New<CHostage>(className);
    }

    static CHostage* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CHostage>(iIndex);
    }

    static CHostage* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
