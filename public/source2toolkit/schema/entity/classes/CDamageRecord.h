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

#include "../enums/EKillTypes_t.h"

class CCSPlayerController;
class CCSPlayerPawn;

class CDamageRecord
{
public:
    DECLARE_SCHEMA_CLASS(CDamageRecord);

    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_PlayerDamager);
    SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_PlayerRecipient);
    SCHEMA_FIELD(CHandle<CCSPlayerController>, m_hPlayerControllerDamager);
    SCHEMA_FIELD(CHandle<CCSPlayerController>, m_hPlayerControllerRecipient);
    SCHEMA_FIELD(CUtlString, m_szPlayerDamagerName);
    SCHEMA_FIELD(CUtlString, m_szPlayerRecipientName);
    SCHEMA_FIELD(uint64_t, m_DamagerXuid);
    SCHEMA_FIELD(uint64_t, m_RecipientXuid);
    SCHEMA_FIELD(float, m_flBulletsDamage);
    SCHEMA_FIELD(float, m_flDamage);
    SCHEMA_FIELD(float, m_flActualHealthRemoved);
    SCHEMA_FIELD(int32_t, m_iNumHits);
    SCHEMA_FIELD(int32_t, m_iLastBulletUpdate);
    SCHEMA_FIELD(bool, m_bIsOtherEnemy);
    SCHEMA_FIELD(EKillTypes_t, m_killType);
};
