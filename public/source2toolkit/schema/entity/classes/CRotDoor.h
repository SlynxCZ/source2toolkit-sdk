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

#include "CBaseDoor.h"

class CRotDoor : public CBaseDoor
{
public:
    DECLARE_SCHEMA_CLASS(CRotDoor);

    SCHEMA_FIELD(bool, m_bSolidBsp);

public:
    static CRotDoor* New(const char* className)
    {
        return CBaseEntity::New<CRotDoor>(className);
    }

    static CRotDoor* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRotDoor>(iIndex);
    }

    static CRotDoor* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
