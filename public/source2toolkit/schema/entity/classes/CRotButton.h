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

class CRotButton : public CBaseButton
{
public:
    DECLARE_SCHEMA_CLASS(CRotButton);


public:
    static CRotButton* New(const char* className)
    {
        return CBaseEntity::New<CRotButton>(className);
    }

    static CRotButton* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CRotButton>(iIndex);
    }

    static CRotButton* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
