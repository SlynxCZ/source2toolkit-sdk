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

#include "CBasePlatTrain.h"

class CBaseEntity;

class CFuncTrain : public CBasePlatTrain
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTrain);

    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hCurrentTarget);
    SCHEMA_FIELD(bool, m_activated);
    SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEnemy);
    SCHEMA_FIELD(float, m_flBlockDamage);
    SCHEMA_FIELD(float, m_flNextBlockTime);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszLastTarget);

public:
    static CFuncTrain* New(const char* className)
    {
        return CBaseEntity::New<CFuncTrain>(className);
    }

    static CFuncTrain* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTrain>(iIndex);
    }

    static CFuncTrain* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
