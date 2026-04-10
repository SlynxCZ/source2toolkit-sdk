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

#include "CEconEntity.h"

class CEconWearable : public CEconEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEconWearable);

    SCHEMA_FIELD(int32_t, m_nForceSkin);
    SCHEMA_FIELD(bool, m_bAlwaysAllow);

public:
    static CEconWearable* New(const char* className)
    {
        return CBaseEntity::New<CEconWearable>(className);
    }

    static CEconWearable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEconWearable>(iIndex);
    }

    static CEconWearable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
