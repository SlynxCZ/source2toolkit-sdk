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

#include "CBaseToggle.h"

class CBasePlatTrain : public CBaseToggle
{
public:
    DECLARE_SCHEMA_CLASS(CBasePlatTrain);

    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseMoving);
    SCHEMA_FIELD(CUtlSymbolLarge, m_NoiseArrived);
    SCHEMA_FIELD(float, m_volume);
    SCHEMA_FIELD(float, m_flTWidth);
    SCHEMA_FIELD(float, m_flTLength);

public:
    static CBasePlatTrain* New(const char* className)
    {
        return CBaseEntity::New<CBasePlatTrain>(className);
    }

    static CBasePlatTrain* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CBasePlatTrain>(iIndex);
    }

    static CBasePlatTrain* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
