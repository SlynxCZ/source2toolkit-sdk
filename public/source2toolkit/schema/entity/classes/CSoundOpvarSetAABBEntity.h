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

#include "CSoundOpvarSetPointEntity.h"

class CSoundOpvarSetAABBEntity : public CSoundOpvarSetPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetAABBEntity);

    SCHEMA_FIELD(Vector, m_vDistanceInnerMins);
    SCHEMA_FIELD(Vector, m_vDistanceInnerMaxs);
    SCHEMA_FIELD(Vector, m_vDistanceOuterMins);
    SCHEMA_FIELD(Vector, m_vDistanceOuterMaxs);
    SCHEMA_FIELD(int32_t, m_nAABBDirection);
    SCHEMA_FIELD(Vector, m_vInnerMins);
    SCHEMA_FIELD(Vector, m_vInnerMaxs);
    SCHEMA_FIELD(Vector, m_vOuterMins);
    SCHEMA_FIELD(Vector, m_vOuterMaxs);

public:
    static CSoundOpvarSetAABBEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetAABBEntity>(className);
    }

    static CSoundOpvarSetAABBEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetAABBEntity>(iIndex);
    }

    static CSoundOpvarSetAABBEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
