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

#include "CServerOnlyModelEntity.h"

class CFogVolume : public CServerOnlyModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFogVolume);

    SCHEMA_FIELD(CUtlSymbolLarge, m_fogName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_postProcessName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_colorCorrectionName);
    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(bool, m_bInFogVolumesList);

public:
    static CFogVolume* New(const char* className)
    {
        return CBaseEntity::New<CFogVolume>(className);
    }

    static CFogVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFogVolume>(iIndex);
    }

    static CFogVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
