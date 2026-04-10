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

class CPulseGameBlackboard : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPulseGameBlackboard);

    SCHEMA_FIELD(CUtlString, m_strGraphName);
    SCHEMA_FIELD(CUtlString, m_strStateBlob);

public:
    static CPulseGameBlackboard* New(const char* className)
    {
        return CBaseEntity::New<CPulseGameBlackboard>(className);
    }

    static CPulseGameBlackboard* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPulseGameBlackboard>(iIndex);
    }

    static CPulseGameBlackboard* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
