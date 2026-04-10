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

class CCSGO_TeamIntroTerroristPosition : public CCSGO_TeamIntroCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamIntroTerroristPosition);


public:
    static CCSGO_TeamIntroTerroristPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamIntroTerroristPosition>(className);
    }

    static CCSGO_TeamIntroTerroristPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamIntroTerroristPosition>(iIndex);
    }

    static CCSGO_TeamIntroTerroristPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
