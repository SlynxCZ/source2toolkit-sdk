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

class CSoundEventParameter : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundEventParameter);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszParamName);
    SCHEMA_FIELD(float, m_flFloatValue);

public:
    static CSoundEventParameter* New(const char* className)
    {
        return CBaseEntity::New<CSoundEventParameter>(className);
    }

    static CSoundEventParameter* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundEventParameter>(iIndex);
    }

    static CSoundEventParameter* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
