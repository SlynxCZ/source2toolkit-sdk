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

class CTriggerTeleport : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerTeleport);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iLandmark);
    SCHEMA_FIELD(bool, m_bUseLandmarkAngles);
    SCHEMA_FIELD(bool, m_bMirrorPlayer);
    SCHEMA_FIELD(bool, m_bCheckDestIfClearForPlayer);

public:
    static CTriggerTeleport* New(const char* className)
    {
        return CBaseEntity::New<CTriggerTeleport>(className);
    }

    static CTriggerTeleport* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerTeleport>(iIndex);
    }

    static CTriggerTeleport* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
