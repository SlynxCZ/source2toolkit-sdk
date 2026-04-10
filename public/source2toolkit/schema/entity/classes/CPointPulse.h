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

class CPointPulse : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointPulse);


public:
    static CPointPulse* New(const char* className)
    {
        return CBaseEntity::New<CPointPulse>(className);
    }

    static CPointPulse* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointPulse>(iIndex);
    }

    static CPointPulse* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
