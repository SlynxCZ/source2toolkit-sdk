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

class CCSPlayerPawn;

class CRetakeGameRules
{
public:
    DECLARE_SCHEMA_CLASS(CRetakeGameRules);

    SCHEMA_FIELD(int32_t, m_nMatchSeed);
    SCHEMA_FIELD(bool, m_bBlockersPresent);
    SCHEMA_FIELD(bool, m_bRoundInProgress);
    SCHEMA_FIELD(int32_t, m_iFirstSecondHalfRound);
    SCHEMA_FIELD(int32_t, m_iBombSite);
    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_hBombPlanter);
};
