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

class CCSGO_TeamSelectCharacterPosition : public CCSGO_TeamPreviewCharacterPosition
{
public:
    DECLARE_SCHEMA_CLASS(CCSGO_TeamSelectCharacterPosition);


public:
    static CCSGO_TeamSelectCharacterPosition* New(const char* className)
    {
        return CBaseEntity::New<CCSGO_TeamSelectCharacterPosition>(className);
    }

    static CCSGO_TeamSelectCharacterPosition* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSGO_TeamSelectCharacterPosition>(iIndex);
    }

    static CCSGO_TeamSelectCharacterPosition* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
