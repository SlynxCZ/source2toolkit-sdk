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

#include "CCSGO_TeamSelectCharacterPosition.h"

class CCSGO_TeamSelectCounterTerroristPosition : public CCSGO_TeamSelectCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamSelectCounterTerroristPosition);


public:
    static CCSGO_TeamSelectCounterTerroristPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamSelectCounterTerroristPosition>(className);
    }

    static CCSGO_TeamSelectCounterTerroristPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamSelectCounterTerroristPosition>(iIndex);
    }

    static CCSGO_TeamSelectCounterTerroristPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
