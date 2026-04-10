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

class CSoundEventSphereEntity : public CSoundEventEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventSphereEntity);

    SCHEMA_FIELD(float, m_flRadius);

public:
    static CSoundEventSphereEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventSphereEntity>(className);
    }

    static CSoundEventSphereEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventSphereEntity>(iIndex);
    }

    static CSoundEventSphereEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
