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

#include "CBaseTrigger.h"

class CTriggerDetectExplosion : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerDetectExplosion);

    SCHEMA_FIELD(CEntityIOOutput, m_OnDetectedExplosion);

public:
    static CTriggerDetectExplosion* New(const char* className)
    {
        return CBaseEntity::New<CTriggerDetectExplosion>(className);
    }

    static CTriggerDetectExplosion* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerDetectExplosion>(iIndex);
    }

    static CTriggerDetectExplosion* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
