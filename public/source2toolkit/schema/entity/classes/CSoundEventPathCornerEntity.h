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

#include "CSoundEventEntity.h"

class CSoundEventPathCornerEntity : public CSoundEventEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventPathCornerEntity);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszPathCorner);
    SCHEMA_FIELD(int32_t, m_iCountMax);
    SCHEMA_FIELD(float, m_flDistanceMax);
    SCHEMA_FIELD(float, m_flDistMaxSqr);
    SCHEMA_FIELD(float, m_flDotProductMax);
    SCHEMA_FIELD(bool, m_bPlaying);

public:
    static CSoundEventPathCornerEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventPathCornerEntity>(className);
    }

    static CSoundEventPathCornerEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventPathCornerEntity>(iIndex);
    }

    static CSoundEventPathCornerEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
