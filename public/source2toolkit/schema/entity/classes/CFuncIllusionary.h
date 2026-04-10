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

#include "CBaseModelEntity.h"

class CFuncIllusionary : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncIllusionary);


public:
    static CFuncIllusionary* New(const char* className)
    {
        return CBaseEntity::New<CFuncIllusionary>(className);
    }

    static CFuncIllusionary* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncIllusionary>(iIndex);
    }

    static CFuncIllusionary* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
