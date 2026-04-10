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

class CLogicBranchList : public CLogicalEntity
{
public:
    DECLARE_SCHEMA_CLASS(CLogicBranchList);

    SCHEMA_FIELD_POINTER(CUtlSymbolLarge, m_nLogicBranchNames);
    SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_LogicBranchList);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAllTrue);
    SCHEMA_FIELD(CEntityIOOutput, m_OnAllFalse);
    SCHEMA_FIELD(CEntityIOOutput, m_OnMixed);

public:
    static CLogicBranchList* New(const char* className)
    {
        return CBaseEntity::New<CLogicBranchList>(className);
    }

    static CLogicBranchList* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CLogicBranchList>(iIndex);
    }

    static CLogicBranchList* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
