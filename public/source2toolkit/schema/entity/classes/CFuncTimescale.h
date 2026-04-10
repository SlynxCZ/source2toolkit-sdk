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

class CFuncTimescale : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTimescale);

    SCHEMA_FIELD(float, m_flDesiredTimescale);
    SCHEMA_FIELD(float, m_flAcceleration);
    SCHEMA_FIELD(float, m_flMinBlendRate);
    SCHEMA_FIELD(float, m_flBlendDeltaMultiplier);
    SCHEMA_FIELD(bool, m_isStarted);

public:
    static CFuncTimescale* New(const char* className)
    {
        return CBaseEntity::New<CFuncTimescale>(className);
    }

    static CFuncTimescale* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTimescale>(iIndex);
    }

    static CFuncTimescale* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
