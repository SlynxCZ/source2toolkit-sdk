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

#include "CSPerRoundStats_t.h"

class CSMatchStats_t : public CSPerRoundStats_t
{
public:
    DECLARE_SCHEMA_CLASS(CSMatchStats_t);

    SCHEMA_FIELD(int32_t, m_iEnemy5Ks);
    SCHEMA_FIELD(int32_t, m_iEnemy4Ks);
    SCHEMA_FIELD(int32_t, m_iEnemy3Ks);
    SCHEMA_FIELD(int32_t, m_iEnemyKnifeKills);
    SCHEMA_FIELD(int32_t, m_iEnemyTaserKills);
    SCHEMA_FIELD(int32_t, m_iEnemy2Ks);
    SCHEMA_FIELD(int32_t, m_iUtility_Count);
    SCHEMA_FIELD(int32_t, m_iUtility_Successes);
    SCHEMA_FIELD(int32_t, m_iUtility_Enemies);
    SCHEMA_FIELD(int32_t, m_iFlash_Count);
    SCHEMA_FIELD(int32_t, m_iFlash_Successes);
    SCHEMA_FIELD(float, m_flHealthPointsRemovedTotal);
    SCHEMA_FIELD(float, m_flHealthPointsDealtTotal);
    SCHEMA_FIELD(int32_t, m_nShotsFiredTotal);
    SCHEMA_FIELD(int32_t, m_nShotsOnTargetTotal);
    SCHEMA_FIELD(int32_t, m_i1v1Count);
    SCHEMA_FIELD(int32_t, m_i1v1Wins);
    SCHEMA_FIELD(int32_t, m_i1v2Count);
    SCHEMA_FIELD(int32_t, m_i1v2Wins);
    SCHEMA_FIELD(int32_t, m_iEntryCount);
    SCHEMA_FIELD(int32_t, m_iEntryWins);
};
