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

#include "CBaseEntity.h"

class CEnvSoundscape : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSoundscape);

    SCHEMA_FIELD(CEntityIOOutput, m_OnPlay);
    SCHEMA_FIELD(float, m_flRadius);
    SCHEMA_FIELD(CUtlSymbolLarge, m_soundEventName);
    SCHEMA_FIELD(bool, m_bOverrideWithEvent);
    SCHEMA_FIELD(int32_t, m_soundscapeIndex);
    SCHEMA_FIELD(int32_t, m_soundscapeEntityListId);
    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_positionNames);
    SCHEMA_FIELD(CHandle<CEnvSoundscape>, m_hProxySoundscape);
    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(CUtlSymbolLarge, m_soundscapeName);
    SCHEMA_FIELD(uint32_t, m_soundEventHash);

public:
    static CEnvSoundscape* New(const char* className)
    {
        return CBaseEntity::New<CEnvSoundscape>(className);
    }

    static CEnvSoundscape* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSoundscape>(iIndex);
    }

    static CEnvSoundscape* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
