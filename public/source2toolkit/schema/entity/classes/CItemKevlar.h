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

#include "CItem.h"

class CItemKevlar : public CItem
{
public:
    DECLARE_SCHEMA_CLASS(CItemKevlar);


public:
    static CItemKevlar* New(const char* className)
    {
        return CBaseEntity::New<CItemKevlar>(className);
    }

    static CItemKevlar* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CItemKevlar>(iIndex);
    }

    static CItemKevlar* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
