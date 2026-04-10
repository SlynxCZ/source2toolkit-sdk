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

#include "CEnvSoundscapeProxy.h"

class CEnvSoundscapeProxyAlias_snd_soundscape_proxy : public CEnvSoundscapeProxy
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSoundscapeProxyAlias_snd_soundscape_proxy);


public:
    static CEnvSoundscapeProxyAlias_snd_soundscape_proxy* New(const char* className)
    {
        return CBaseEntity::New<CEnvSoundscapeProxyAlias_snd_soundscape_proxy>(className);
    }

    static CEnvSoundscapeProxyAlias_snd_soundscape_proxy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSoundscapeProxyAlias_snd_soundscape_proxy>(iIndex);
    }

    static CEnvSoundscapeProxyAlias_snd_soundscape_proxy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
