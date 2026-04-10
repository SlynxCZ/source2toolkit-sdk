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

#include "CBaseEntity.h"

class CInfoLadderDismount : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoLadderDismount);


public:
    static CInfoLadderDismount* New(const char* className)
    {
        return CBaseEntity::New<CInfoLadderDismount>(className);
    }

    static CInfoLadderDismount* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoLadderDismount>(iIndex);
    }

    static CInfoLadderDismount* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
