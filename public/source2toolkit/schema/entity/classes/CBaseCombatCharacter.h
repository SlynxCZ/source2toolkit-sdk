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

#include "CBaseFlex.h"
#include "CMovementStatsProperty.h"
#include "../enums/Hull_t.h"
#include "RelationshipOverride_t.h"

class CEconWearable;

class CBaseCombatCharacter : public CBaseFlex
{
public:
    DECLARE_SCHEMA_CLASS(CBaseCombatCharacter);

    SCHEMA_FIELD(bool, m_bForceServerRagdoll);
    SCHEMA_FIELD(CUtlVector<CHandle<CEconWearable>>, m_hMyWearables);
    SCHEMA_FIELD(float, m_impactEnergyScale);
    SCHEMA_FIELD(bool, m_bApplyStressDamage);
    SCHEMA_FIELD(bool, m_bDeathEventsDispatched);
    SCHEMA_FIELD(CUtlVector<RelationshipOverride_t>*, m_pVecRelationships);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strRelationships);
    SCHEMA_FIELD(Hull_t, m_eHull);
    SCHEMA_FIELD(uint32_t, m_nNavHullIdx);
    SCHEMA_FIELD(CMovementStatsProperty, m_movementStats);

public:
    static CBaseCombatCharacter* New(const char* className)
    {
        return CBaseEntity::New<CBaseCombatCharacter>(className);
    }

    static CBaseCombatCharacter* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseCombatCharacter>(iIndex);
    }

    static CBaseCombatCharacter* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
