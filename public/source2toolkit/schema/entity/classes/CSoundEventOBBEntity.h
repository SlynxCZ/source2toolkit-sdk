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

class CSoundEventOBBEntity : public CSoundEventEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventOBBEntity);

    SCHEMA_FIELD(Vector, m_vMins);
    SCHEMA_FIELD(Vector, m_vMaxs);

public:
    static CSoundEventOBBEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventOBBEntity>(className);
    }

    static CSoundEventOBBEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventOBBEntity>(iIndex);
    }

    static CSoundEventOBBEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
