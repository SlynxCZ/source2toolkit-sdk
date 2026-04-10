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

#include "CFuncTrackTrain.h"

class CFuncTankTrain : public CFuncTrackTrain
{
public:
    DECLARE_SCHEMA_CLASS(CFuncTankTrain);

    SCHEMA_FIELD(CEntityIOOutput, m_OnDeath);

public:
    static CFuncTankTrain* New(const char* className)
    {
        return CBaseEntity::New<CFuncTankTrain>(className);
    }

    static CFuncTankTrain* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncTankTrain>(iIndex);
    }

    static CFuncTankTrain* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
