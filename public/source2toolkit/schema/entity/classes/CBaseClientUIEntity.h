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

class CBaseClientUIEntity : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CBaseClientUIEntity);

    SCHEMA_FIELD(bool, m_bEnabled);
    SCHEMA_FIELD(CUtlSymbolLarge, m_DialogXMLName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_PanelClassName);
    SCHEMA_FIELD(CUtlSymbolLarge, m_PanelID);

public:
    static CBaseClientUIEntity* New(const char* className)
    {
        return CBaseEntity::New<CBaseClientUIEntity>(className);
    }

    static CBaseClientUIEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBaseClientUIEntity>(iIndex);
    }

    static CBaseClientUIEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
