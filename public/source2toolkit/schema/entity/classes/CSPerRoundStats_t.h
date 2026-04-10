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

class CSPerRoundStats_t
{
public:
    DECLARE_SCHEMA_CLASS(CSPerRoundStats_t);

    SCHEMA_FIELD(int32_t, m_iKills);
    SCHEMA_FIELD(int32_t, m_iDeaths);
    SCHEMA_FIELD(int32_t, m_iAssists);
    SCHEMA_FIELD(int32_t, m_iDamage);
    SCHEMA_FIELD(int32_t, m_iEquipmentValue);
    SCHEMA_FIELD(int32_t, m_iMoneySaved);
    SCHEMA_FIELD(int32_t, m_iKillReward);
    SCHEMA_FIELD(int32_t, m_iLiveTime);
    SCHEMA_FIELD(int32_t, m_iHeadShotKills);
    SCHEMA_FIELD(int32_t, m_iObjective);
    SCHEMA_FIELD(int32_t, m_iCashEarned);
    SCHEMA_FIELD(int32_t, m_iUtilityDamage);
    SCHEMA_FIELD(int32_t, m_iEnemiesFlashed);
};
