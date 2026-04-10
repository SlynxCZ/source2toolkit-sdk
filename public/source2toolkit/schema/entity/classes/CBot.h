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

class CCSPlayerController;
class CCSPlayerPawn;

class CBot
{
public:
    DECLARE_SCHEMA_CLASS(CBot);

    SCHEMA_FIELD(CCSPlayerController*, m_pController);
    SCHEMA_FIELD(CCSPlayerPawn*, m_pPlayer);
    SCHEMA_FIELD(bool, m_bHasSpawned);
    SCHEMA_FIELD(uint32_t, m_id);
    SCHEMA_FIELD(bool, m_isRunning);
    SCHEMA_FIELD(bool, m_isCrouching);
    SCHEMA_FIELD(float, m_forwardSpeed);
    SCHEMA_FIELD(float, m_leftSpeed);
    SCHEMA_FIELD(float, m_verticalSpeed);
    SCHEMA_FIELD(uint64_t, m_buttonFlags);
    SCHEMA_FIELD(float, m_jumpTimestamp);
    SCHEMA_FIELD(Vector, m_viewForward);
    SCHEMA_FIELD(int32_t, m_postureStackIndex);
};
