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

class CCSPlayerModernJump
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerModernJump);

    SCHEMA_FIELD(int32_t, m_nLastActualJumpPressTick);
    SCHEMA_FIELD(float, m_flLastActualJumpPressFrac);
    SCHEMA_FIELD(int32_t, m_nLastUsableJumpPressTick);
    SCHEMA_FIELD(float, m_flLastUsableJumpPressFrac);
    SCHEMA_FIELD(int32_t, m_nLastLandedTick);
    SCHEMA_FIELD(float, m_flLastLandedFrac);
    SCHEMA_FIELD(float, m_flLastLandedVelocityX);
    SCHEMA_FIELD(float, m_flLastLandedVelocityY);
    SCHEMA_FIELD(float, m_flLastLandedVelocityZ);
};
