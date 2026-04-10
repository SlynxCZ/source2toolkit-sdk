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

#include "CCSPlayerPawnBase.h"

class CCSObserverPawn : public CCSPlayerPawnBase
{
public:
    DECLARE_SCHEMA_CLASS(CCSObserverPawn);


public:
    static CCSObserverPawn* New(const char* className)
    {
        return CBaseEntity::New<CCSObserverPawn>(className);
    }

    static CCSObserverPawn* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CCSObserverPawn>(iIndex);
    }

    static CCSObserverPawn* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
