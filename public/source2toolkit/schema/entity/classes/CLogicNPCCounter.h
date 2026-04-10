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

#include "CBaseEntity.h"

class CLogicNPCCounter : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicNPCCounter);

    SCHEMA_FIELD(CEntityIOOutput, m_OnMinCountAll);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMaxCountAll);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMinCount_1);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMaxCount_1);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMinCount_2);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMaxCount_2);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMinCount_3);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMaxCount_3);
    SCHEMA_FIELD(CEntityHandle, m_hSource);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszSourceEntityName);
    SCHEMA_FIELD(float, m_flDistanceMax);
    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(int32_t, m_nMinCountAll);
    SCHEMA_FIELD(int32_t, m_nMaxCountAll);
    SCHEMA_FIELD(int32_t, m_nMinFactorAll);
    SCHEMA_FIELD(int32_t, m_nMaxFactorAll);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszNPCClassname_1);
    SCHEMA_FIELD(int32_t, m_nNPCState_1);
    SCHEMA_FIELD(bool, m_bInvertState_1);
    SCHEMA_FIELD(int32_t, m_nMinCount_1);
    SCHEMA_FIELD(int32_t, m_nMaxCount_1);
    SCHEMA_FIELD(int32_t, m_nMinFactor_1);
    SCHEMA_FIELD(int32_t, m_nMaxFactor_1);
    SCHEMA_FIELD(float, m_flDefaultDist_1);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszNPCClassname_2);
    SCHEMA_FIELD(int32_t, m_nNPCState_2);
    SCHEMA_FIELD(bool, m_bInvertState_2);
    SCHEMA_FIELD(int32_t, m_nMinCount_2);
    SCHEMA_FIELD(int32_t, m_nMaxCount_2);
    SCHEMA_FIELD(int32_t, m_nMinFactor_2);
    SCHEMA_FIELD(int32_t, m_nMaxFactor_2);
    SCHEMA_FIELD(float, m_flDefaultDist_2);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszNPCClassname_3);
    SCHEMA_FIELD(int32_t, m_nNPCState_3);
    SCHEMA_FIELD(bool, m_bInvertState_3);
    SCHEMA_FIELD(int32_t, m_nMinCount_3);
    SCHEMA_FIELD(int32_t, m_nMaxCount_3);
    SCHEMA_FIELD(int32_t, m_nMinFactor_3);
    SCHEMA_FIELD(int32_t, m_nMaxFactor_3);
    SCHEMA_FIELD(float, m_flDefaultDist_3);

public:
    static CLogicNPCCounter* New(const char* className)
    {
        return CBaseEntity::New<CLogicNPCCounter>(className);
    }

    static CLogicNPCCounter* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicNPCCounter>(iIndex);
    }

    static CLogicNPCCounter* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
