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

class CCSGO_TeamSelectTerroristPosition : public CCSGO_TeamSelectCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamSelectTerroristPosition);


public:
    static CCSGO_TeamSelectTerroristPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamSelectTerroristPosition>(className);
    }

    static CCSGO_TeamSelectTerroristPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamSelectTerroristPosition>(iIndex);
    }

    static CCSGO_TeamSelectTerroristPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
