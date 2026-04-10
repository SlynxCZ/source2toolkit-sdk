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

#include "CLogicAutosave.h"

class CLogicActiveAutosave : public CLogicAutosave
{
public:
    DECLARE_SCHEMA_CLASS(CLogicActiveAutosave);

    SCHEMA_FIELD(int32_t, m_TriggerHitPoints);
    SCHEMA_FIELD(float, m_flTimeToTrigger);
    SCHEMA_FIELD(float, m_flStartTime);
    SCHEMA_FIELD(float, m_flDangerousTime);

public:
    static CLogicActiveAutosave* New(const char* className)
    {
        return CBaseEntity::New<CLogicActiveAutosave>(className);
    }

    static CLogicActiveAutosave* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicActiveAutosave>(iIndex);
    }

    static CLogicActiveAutosave* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
