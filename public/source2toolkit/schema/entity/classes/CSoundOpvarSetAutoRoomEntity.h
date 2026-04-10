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

#include "AutoRoomDoorwayPairs_t.h"
#include "CSoundOpvarSetPointEntity.h"
#include "SoundOpvarTraceResult_t.h"

class CSoundOpvarSetAutoRoomEntity : public CSoundOpvarSetPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetAutoRoomEntity);

    SCHEMA_FIELD(CUtlVector<SoundOpvarTraceResult_t>, m_traceResults);
    SCHEMA_FIELD(CUtlVector<AutoRoomDoorwayPairs_t>, m_doorwayPairs);
    SCHEMA_FIELD(float, m_flSize);
    SCHEMA_FIELD(float, m_flHeightTolerance);
    SCHEMA_FIELD(float, m_flSizeSqr);

public:
    static CSoundOpvarSetAutoRoomEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetAutoRoomEntity>(className);
    }

    static CSoundOpvarSetAutoRoomEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetAutoRoomEntity>(iIndex);
    }

    static CSoundOpvarSetAutoRoomEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
