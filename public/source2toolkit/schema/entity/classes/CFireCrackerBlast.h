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

#include "CInferno.h"

class CFireCrackerBlast : public CInferno
{
public:
    DECLARE_SCHEMA_CLASS(CFireCrackerBlast);


public:
    static CFireCrackerBlast* New(const char* className)
    {
        return CBaseEntity::New<CFireCrackerBlast>(className);
    }

    static CFireCrackerBlast* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFireCrackerBlast>(iIndex);
    }

    static CFireCrackerBlast* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
