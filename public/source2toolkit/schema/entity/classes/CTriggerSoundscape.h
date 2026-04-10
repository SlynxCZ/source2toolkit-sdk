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

class CBasePlayerPawn;
class CEnvSoundscapeTriggerable;

class CTriggerSoundscape : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerSoundscape);

    SCHEMA_FIELD(CHandle<CEnvSoundscapeTriggerable>, m_hSoundscape);
    SCHEMA_FIELD(CUtlSymbolLarge, m_SoundscapeName);
    SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerPawn>>, m_spectators);

public:
    static CTriggerSoundscape* New(const char* className)
    {
        return CBaseEntity::New<CTriggerSoundscape>(className);
    }

    static CTriggerSoundscape* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerSoundscape>(iIndex);
    }

    static CTriggerSoundscape* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
