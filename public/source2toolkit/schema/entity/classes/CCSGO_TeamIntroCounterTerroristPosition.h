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

#include "CCSGO_TeamIntroCharacterPosition.h"

class CCSGO_TeamIntroCounterTerroristPosition : public CCSGO_TeamIntroCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamIntroCounterTerroristPosition);


public:
    static CCSGO_TeamIntroCounterTerroristPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamIntroCounterTerroristPosition>(className);
    }

    static CCSGO_TeamIntroCounterTerroristPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamIntroCounterTerroristPosition>(iIndex);
    }

    static CCSGO_TeamIntroCounterTerroristPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
