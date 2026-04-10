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

class CBaseEntity;

class CLogicBranch : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicBranch);

    SCHEMA_FIELD(bool, m_bInValue);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_Listeners);
    SCHEMA_FIELD(CEntityIOOutput, m_OnTrue);
    SCHEMA_FIELD(CEntityIOOutput, m_OnFalse);

public:
    static CLogicBranch* New(const char* className)
    {
        return CBaseEntity::New<CLogicBranch>(className);
    }

    static CLogicBranch* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicBranch>(iIndex);
    }

    static CLogicBranch* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
