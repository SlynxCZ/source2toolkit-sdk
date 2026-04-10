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

#include "CLogicalEntity.h"

class CSoundStackSave : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundStackSave);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszStackName);

public:
    static CSoundStackSave* New(const char* className)
    {
        return CBaseEntity::New<CSoundStackSave>(className);
    }

    static CSoundStackSave* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundStackSave>(iIndex);
    }

    static CSoundStackSave* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
