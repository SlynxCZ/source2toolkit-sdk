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

class CEnvSoundscapeProxy : public CEnvSoundscape
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSoundscapeProxy);

    SCHEMA_FIELD(CUtlSymbolLarge, m_MainSoundscapeName);

public:
    static CEnvSoundscapeProxy* New(const char* className)
    {
        return CBaseEntity::New<CEnvSoundscapeProxy>(className);
    }

    static CEnvSoundscapeProxy* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSoundscapeProxy>(iIndex);
    }

    static CEnvSoundscapeProxy* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
