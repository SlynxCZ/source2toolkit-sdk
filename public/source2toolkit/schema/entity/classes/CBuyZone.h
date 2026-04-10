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

#include "CBaseTrigger.h"

class CBuyZone : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CBuyZone);

    SCHEMA_FIELD(int32_t, m_LegacyTeamNum);

public:
    static CBuyZone* New(const char* className)
    {
        return CBaseEntity::New<CBuyZone>(className);
    }

    static CBuyZone* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBuyZone>(iIndex);
    }

    static CBuyZone* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
