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

#include "CSoundOpvarSetPointBase.h"

class CSoundOpvarSetOBBWindEntity : public CSoundOpvarSetPointBase
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetOBBWindEntity);

    SCHEMA_FIELD(Vector, m_vMins);
    SCHEMA_FIELD(Vector, m_vMaxs);
    SCHEMA_FIELD(Vector, m_vDistanceMins);
    SCHEMA_FIELD(Vector, m_vDistanceMaxs);
    SCHEMA_FIELD(float, m_flWindMin);
    SCHEMA_FIELD(float, m_flWindMax);
    SCHEMA_FIELD(float, m_flWindMapMin);
    SCHEMA_FIELD(float, m_flWindMapMax);

public:
    static CSoundOpvarSetOBBWindEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetOBBWindEntity>(className);
    }

    static CSoundOpvarSetOBBWindEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetOBBWindEntity>(iIndex);
    }

    static CSoundOpvarSetOBBWindEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
