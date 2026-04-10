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

#include "CTriggerMultiple.h"
#include "DynamicVolumeDef_t.h"

class CDynamicNavConnectionsVolume : public CTriggerMultiple
{
public:
    DECLARE_SCHEMA_CLASS(CDynamicNavConnectionsVolume);

    SCHEMA_FIELD(CUtlSymbolLarge, m_iszConnectionTarget);
    SCHEMA_FIELD(CUtlVector<DynamicVolumeDef_t>, m_vecConnections);
    SCHEMA_FIELD(CGlobalSymbol, m_sTransitionType);
    SCHEMA_FIELD(bool, m_bConnectionsEnabled);
    SCHEMA_FIELD(float, m_flTargetAreaSearchRadius);
    SCHEMA_FIELD(float, m_flUpdateDistance);
    SCHEMA_FIELD(float, m_flMaxConnectionDistance);

public:
    static CDynamicNavConnectionsVolume* New(const char* className)
    {
        return CBaseEntity::New<CDynamicNavConnectionsVolume>(className);
    }

    static CDynamicNavConnectionsVolume* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CDynamicNavConnectionsVolume>(iIndex);
    }

    static CDynamicNavConnectionsVolume* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
