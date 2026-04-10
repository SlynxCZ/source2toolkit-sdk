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

class CTriggerDetectBulletFire : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerDetectBulletFire);

    SCHEMA_FIELD(bool, m_bPlayerFireOnly);
    SCHEMA_FIELD(CEntityIOOutput, m_OnDetectedBulletFire);

public:
    static CTriggerDetectBulletFire* New(const char* className)
    {
        return CBaseEntity::New<CTriggerDetectBulletFire>(className);
    }

    static CTriggerDetectBulletFire* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerDetectBulletFire>(iIndex);
    }

    static CTriggerDetectBulletFire* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
