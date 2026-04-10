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

#include "CPointEntity.h"

class CInfoInteraction : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoInteraction);

    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_strSlotEntityName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_strInteractVData);
    SCHEMA_FIELD(float, m_flInteractRadius);

public:
    static CInfoInteraction* New(const char* className)
    {
        return CBaseEntity::New<CInfoInteraction>(className);
    }

    static CInfoInteraction* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoInteraction>(iIndex);
    }

    static CInfoInteraction* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
