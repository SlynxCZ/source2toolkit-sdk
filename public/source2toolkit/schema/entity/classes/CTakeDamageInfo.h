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

#include "../enums/DamageTypes_t.h"
#include "DestructibleHitGroupToDestroy_t.h"
#include "../enums/TakeDamageFlags_t.h"

class CBaseEntity;

class CTakeDamageInfo
{
public:
    DECLARE_SCHEMA_CLASS(CTakeDamageInfo);

    SCHEMA_FIELD(Vector, m_vecDamageForce);
    SCHEMA_FIELD(Vector, m_vecDamagePosition);
    SCHEMA_FIELD(Vector, m_vecReportedPosition);
    SCHEMA_FIELD(Vector, m_vecDamageDirection);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hInflictor);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAttacker);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAbility);
    SCHEMA_FIELD(float, m_flDamage);
    SCHEMA_FIELD(float, m_flTotalledDamage);
    SCHEMA_FIELD(DamageTypes_t, m_bitsDamageType);
    SCHEMA_FIELD(int32_t, m_iDamageCustom);
    SCHEMA_FIELD(uint8_t, m_iAmmoType);
    SCHEMA_FIELD(float, m_flOriginalDamage);
    SCHEMA_FIELD(bool, m_bShouldBleed);
    SCHEMA_FIELD(bool, m_bShouldSpark);
    SCHEMA_FIELD(TakeDamageFlags_t, m_nDamageFlags);
    SCHEMA_FIELD(HitGroup_t, m_iHitGroupId);
    SCHEMA_FIELD(int32_t, m_nNumObjectsPenetrated);
    SCHEMA_FIELD(float, m_flFriendlyFireDamageReductionRatio);
    SCHEMA_FIELD(bool, m_bStoppedBullet);
    SCHEMA_FIELD(CUtlVector<DestructibleHitGroupToDestroy_t>, m_nDestructibleHitGroupsToForceDestroy);
    SCHEMA_FIELD(bool, m_bInTakeDamageFlow);
};
