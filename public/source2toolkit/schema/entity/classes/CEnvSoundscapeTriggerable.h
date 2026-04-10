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

class CEnvSoundscapeTriggerable : public CEnvSoundscape
{
public:
    DECLARE_SCHEMA_CLASS(CEnvSoundscapeTriggerable);


public:
    static CEnvSoundscapeTriggerable* New(const char* className)
    {
        return CBaseEntity::New<CEnvSoundscapeTriggerable>(className);
    }

    static CEnvSoundscapeTriggerable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvSoundscapeTriggerable>(iIndex);
    }

    static CEnvSoundscapeTriggerable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
