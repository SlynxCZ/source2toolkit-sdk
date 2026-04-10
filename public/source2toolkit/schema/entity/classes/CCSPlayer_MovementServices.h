#pragma once
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

#include "CCSPlayerLegacyJump.h"
#include "CCSPlayerModernJump.h"
#include "CPlayer_MovementServices_Humanoid.h"

class CCSPlayer_MovementServices : public CPlayer_MovementServices_Humanoid
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayer_MovementServices);

    SCHEMA_FIELD(Vector, m_vecLadderNormal);
    SCHEMA_FIELD(int32_t, m_nLadderSurfacePropIndex);
    SCHEMA_FIELD(bool, m_bDucked);
    SCHEMA_FIELD(float, m_flDuckAmount);
    SCHEMA_FIELD(float, m_flDuckSpeed);
    SCHEMA_FIELD(bool, m_bDuckOverride);
    SCHEMA_FIELD(bool, m_bDesiresDuck);
    SCHEMA_FIELD(bool, m_bDucking);
    SCHEMA_FIELD(float, m_flDuckOffset);
    SCHEMA_FIELD(uint32_t, m_nDuckTimeMsecs);
    SCHEMA_FIELD(uint32_t, m_nDuckJumpTimeMsecs);
    SCHEMA_FIELD(uint32_t, m_nJumpTimeMsecs);
    SCHEMA_FIELD(float, m_flLastDuckTime);
    SCHEMA_FIELD(Vector2D, m_vecLastPositionAtFullCrouchSpeed);
    SCHEMA_FIELD(bool, m_duckUntilOnGround);
    SCHEMA_FIELD(bool, m_bHasWalkMovedSinceLastJump);
    SCHEMA_FIELD(bool, m_bInStuckTest);
    SCHEMA_FIELD(int32_t, m_nTraceCount);
    SCHEMA_FIELD(int32_t, m_StuckLast);
    SCHEMA_FIELD(bool, m_bSpeedCropped);
    SCHEMA_FIELD(int32_t, m_nOldWaterLevel);
    SCHEMA_FIELD(float, m_flWaterEntryTime);
    SCHEMA_FIELD(Vector, m_vecForward);
    SCHEMA_FIELD(Vector, m_vecLeft);
    SCHEMA_FIELD(Vector, m_vecUp);
    SCHEMA_FIELD(int32_t, m_nGameCodeHasMovedPlayerAfterCommand);
    SCHEMA_FIELD(bool, m_bMadeFootstepNoise);
    SCHEMA_FIELD(int32_t, m_iFootsteps);
    SCHEMA_FIELD(float, m_fStashGrenadeParameterWhen);
    SCHEMA_FIELD(uint64_t, m_nButtonDownMaskPrev);
    SCHEMA_FIELD(float, m_flOffsetTickCompleteTime);
    SCHEMA_FIELD(float, m_flOffsetTickStashedSpeed);
    SCHEMA_FIELD(float, m_flStamina);
    SCHEMA_FIELD(float, m_flHeightAtJumpStart);
    SCHEMA_FIELD(float, m_flMaxJumpHeightThisJump);
    SCHEMA_FIELD(float, m_flMaxJumpHeightLastJump);
    SCHEMA_FIELD(float, m_flStaminaAtJumpStart);
    SCHEMA_FIELD(float, m_flVelMulAtJumpStart);
    SCHEMA_FIELD(float, m_flAccumulatedJumpError);
    SCHEMA_FIELD(CCSPlayerLegacyJump, m_LegacyJump);
    SCHEMA_FIELD(CCSPlayerModernJump, m_ModernJump);
    SCHEMA_FIELD(int32_t, m_nLastJumpTick);
    SCHEMA_FIELD(float, m_flLastJumpFrac);
    SCHEMA_FIELD(float, m_flLastJumpVelocityZ);
    SCHEMA_FIELD(bool, m_bJumpApexPending);
    SCHEMA_FIELD(float, m_flTicksSinceLastSurfingDetected);
    SCHEMA_FIELD(bool, m_bWasSurfing);
    SCHEMA_FIELD(Vector, m_vecInputRotated);
};
