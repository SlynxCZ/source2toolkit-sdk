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

#include "CPointEntity.h"

class CPointBroadcastClientCommand : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointBroadcastClientCommand);


public:
    static CPointBroadcastClientCommand* New(const char* className)
    {
        return CBaseEntity::New<CPointBroadcastClientCommand>(className);
    }

    static CPointBroadcastClientCommand* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointBroadcastClientCommand>(iIndex);
    }

    static CPointBroadcastClientCommand* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
