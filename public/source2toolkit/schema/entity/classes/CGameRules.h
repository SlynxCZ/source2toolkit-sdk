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


class CGameRules
{
public:
    DECLARE_SCHEMA_CLASS(CGameRules);

    SCHEMA_FIELD(CEntityInstance*, __m_pChainEntity);
    SCHEMA_FIELD_POINTER(char, m_szQuestName);
    SCHEMA_FIELD(int32_t, m_nQuestPhase);
    SCHEMA_FIELD(uint32_t, m_nLastMatchTime);
    SCHEMA_FIELD(uint64_t, m_nLastMatchTime_MatchID64);
    SCHEMA_FIELD(int32_t, m_nTotalPausedTicks);
    SCHEMA_FIELD(int32_t, m_nPauseStartTick);
    SCHEMA_FIELD(bool, m_bGamePaused);
};
