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

class CCSPlayerResource : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CCSPlayerResource);

    SCHEMA_FIELD_POINTER(bool, m_bHostageAlive);
    SCHEMA_FIELD_POINTER(bool, m_isHostageFollowingSomeone);
    SCHEMA_FIELD_POINTER(CEntityIndex, m_iHostageEntityIDs);
    SCHEMA_FIELD(Vector, m_bombsiteCenterA);
    SCHEMA_FIELD(Vector, m_bombsiteCenterB);
    SCHEMA_FIELD_POINTER(int32_t, m_hostageRescueX);
    SCHEMA_FIELD_POINTER(int32_t, m_hostageRescueY);
    SCHEMA_FIELD_POINTER(int32_t, m_hostageRescueZ);
    SCHEMA_FIELD(bool, m_bEndMatchNextMapAllVoted);
    SCHEMA_FIELD(bool, m_foundGoalPositions);

public:
    static CCSPlayerResource* New(const char* className)
    {
        return CBaseEntity::New<CCSPlayerResource>(className);
    }

    static CCSPlayerResource* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSPlayerResource>(iIndex);
    }

    static CCSPlayerResource* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
