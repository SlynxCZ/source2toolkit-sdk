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

#include "CPropDoorRotating.h"

class CPropDoorRotatingBreakable : public CPropDoorRotating
{
public:
    DECLARE_SCHEMA_CLASS(CPropDoorRotatingBreakable);

    SCHEMA_FIELD(bool, m_bBreakable);
    SCHEMA_FIELD(bool, m_isAbleToCloseAreaPortals);
    SCHEMA_FIELD(int32_t, m_currentDamageState);
    SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>, m_damageStates);

public:
    static CPropDoorRotatingBreakable* New(const char* className)
    {
        return CBaseEntity::New<CPropDoorRotatingBreakable>(className);
    }

    static CPropDoorRotatingBreakable* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPropDoorRotatingBreakable>(iIndex);
    }

    static CPropDoorRotatingBreakable* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
