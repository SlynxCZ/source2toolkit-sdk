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

class CCitadelSoundOpvarSetOBB : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCitadelSoundOpvarSetOBB);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStackName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOperatorName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszOpvarName);
    SCHEMA_FIELD(Vector, m_vDistanceInnerMins);
    SCHEMA_FIELD(Vector, m_vDistanceInnerMaxs);
    SCHEMA_FIELD(Vector, m_vDistanceOuterMins);
    SCHEMA_FIELD(Vector, m_vDistanceOuterMaxs);
    SCHEMA_FIELD(int32_t, m_nAABBDirection);

public:
    static CCitadelSoundOpvarSetOBB* New(const char* className)
    {
        return CBaseEntity::New<CCitadelSoundOpvarSetOBB>(className);
    }

    static CCitadelSoundOpvarSetOBB* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCitadelSoundOpvarSetOBB>(iIndex);
    }

    static CCitadelSoundOpvarSetOBB* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
