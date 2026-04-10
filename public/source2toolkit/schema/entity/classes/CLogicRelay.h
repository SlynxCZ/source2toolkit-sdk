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

class CLogicRelay : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicRelay);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(bool, m_bWaitForRefire);
    SCHEMA_FIELD(bool, m_bTriggerOnce);
    SCHEMA_FIELD(bool, m_bFastRetrigger);
    SCHEMA_FIELD(bool, m_bPassthoughCaller);

public:
    static CLogicRelay* New(const char* className)
    {
        return CBaseEntity::New<CLogicRelay>(className);
    }

    static CLogicRelay* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicRelay>(iIndex);
    }

    static CLogicRelay* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
