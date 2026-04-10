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

#include "CBaseButton.h"

class CPhysicalButton : public CBaseButton
{
public:
    DECLARE_SCHEMA_CLASS(CPhysicalButton);


public:
    static CPhysicalButton* New(const char* className)
    {
        return CBaseEntity::New<CPhysicalButton>(className);
    }

    static CPhysicalButton* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPhysicalButton>(iIndex);
    }

    static CPhysicalButton* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
