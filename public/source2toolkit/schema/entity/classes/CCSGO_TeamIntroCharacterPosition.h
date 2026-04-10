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

#include "CCSGO_TeamPreviewCharacterPosition.h"

class CCSGO_TeamIntroCharacterPosition : public CCSGO_TeamPreviewCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamIntroCharacterPosition);


public:
    static CCSGO_TeamIntroCharacterPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamIntroCharacterPosition>(className);
    }

    static CCSGO_TeamIntroCharacterPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamIntroCharacterPosition>(iIndex);
    }

    static CCSGO_TeamIntroCharacterPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
