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

#include "CEnvSoundscape.h"

class CEnvSoundscapeAlias_snd_soundscape : public CEnvSoundscape
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSoundscapeAlias_snd_soundscape);


public:
    static CEnvSoundscapeAlias_snd_soundscape* New(const char* className)
    {
        return CBaseEntity::New<CEnvSoundscapeAlias_snd_soundscape>(className);
    }

    static CEnvSoundscapeAlias_snd_soundscape* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSoundscapeAlias_snd_soundscape>(iIndex);
    }

    static CEnvSoundscapeAlias_snd_soundscape* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
