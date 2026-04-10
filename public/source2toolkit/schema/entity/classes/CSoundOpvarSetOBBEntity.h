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

#include "CSoundOpvarSetAABBEntity.h"

class CSoundOpvarSetOBBEntity : public CSoundOpvarSetAABBEntity
{
public:
    DECLARE_SCHEMA_CLASS(CSoundOpvarSetOBBEntity);


public:
    static CSoundOpvarSetOBBEntity* New(const char* className)
    {
        return CBaseEntity::New<CSoundOpvarSetOBBEntity>(className);
    }

    static CSoundOpvarSetOBBEntity* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CSoundOpvarSetOBBEntity>(iIndex);
    }

    static CSoundOpvarSetOBBEntity* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
