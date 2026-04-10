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

class CSoundEventEntityAlias_snd_event_point : public CSoundEventEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventEntityAlias_snd_event_point);


public:
    static CSoundEventEntityAlias_snd_event_point* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventEntityAlias_snd_event_point>(className);
    }

    static CSoundEventEntityAlias_snd_event_point* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventEntityAlias_snd_event_point>(iIndex);
    }

    static CSoundEventEntityAlias_snd_event_point* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
