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

#include "CCSGO_WingmanIntroCharacterPosition.h"

class CCSGO_WingmanIntroCounterTerroristPosition : public CCSGO_WingmanIntroCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_WingmanIntroCounterTerroristPosition);


public:
    static CCSGO_WingmanIntroCounterTerroristPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_WingmanIntroCounterTerroristPosition>(className);
    }

    static CCSGO_WingmanIntroCounterTerroristPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_WingmanIntroCounterTerroristPosition>(iIndex);
    }

    static CCSGO_WingmanIntroCounterTerroristPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
