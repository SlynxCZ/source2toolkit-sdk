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

class CPrecipitationBlocker : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPrecipitationBlocker);


public:
    static CPrecipitationBlocker* New(const char* className)
    {
        return CBaseEntity::New<CPrecipitationBlocker>(className);
    }

    static CPrecipitationBlocker* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPrecipitationBlocker>(iIndex);
    }

    static CPrecipitationBlocker* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
