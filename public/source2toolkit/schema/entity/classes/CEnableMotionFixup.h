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

class CEnableMotionFixup : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CEnableMotionFixup);


public:
    static CEnableMotionFixup* New(const char* className)
    {
        return CBaseEntity::New<CEnableMotionFixup>(className);
    }

    static CEnableMotionFixup* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnableMotionFixup>(iIndex);
    }

    static CEnableMotionFixup* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
