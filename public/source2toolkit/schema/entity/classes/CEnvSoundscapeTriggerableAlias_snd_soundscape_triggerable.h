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

#include "CEnvSoundscapeTriggerable.h"

class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable : public CEnvSoundscapeTriggerable
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable);


public:
    static CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable* New(const char* className)
    {
        return CBaseEntity::New<CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable>(className);
    }

    static CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable>(iIndex);
    }

    static CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
