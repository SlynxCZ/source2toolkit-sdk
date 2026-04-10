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

class CInfoInstructorHintTarget : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoInstructorHintTarget);


public:
    static CInfoInstructorHintTarget* New(const char* className)
    {
        return CBaseEntity::New<CInfoInstructorHintTarget>(className);
    }

    static CInfoInstructorHintTarget* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoInstructorHintTarget>(iIndex);
    }

    static CInfoInstructorHintTarget* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
