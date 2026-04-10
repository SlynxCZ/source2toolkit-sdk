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

class CSoundEventAABBEntity : public CSoundEventEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventAABBEntity);

    SCHEMA_FIELD(Vector, m_vMins);
    SCHEMA_FIELD(Vector, m_vMaxs);

public:
    static CSoundEventAABBEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventAABBEntity>(className);
    }

    static CSoundEventAABBEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventAABBEntity>(iIndex);
    }

    static CSoundEventAABBEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
