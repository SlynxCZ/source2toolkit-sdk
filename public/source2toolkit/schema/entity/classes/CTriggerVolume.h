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

#include "CBaseModelEntity.h"

class CBaseFilter;

class CTriggerVolume : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTriggerVolume);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterName);
    SCHEMA_FIELD(CHandle<CBaseFilter>, m_hFilter);

public:
    static CTriggerVolume* New(const char* className)
    {
        return CBaseEntity::New<CTriggerVolume>(className);
    }

    static CTriggerVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTriggerVolume>(iIndex);
    }

    static CTriggerVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
