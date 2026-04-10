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

#include "CModelPointEntity.h"

class CShower : public CModelPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CShower);


public:
    static CShower* New(const char* className)
    {
        return CBaseEntity::New<CShower>(className);
    }

    static CShower* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CShower>(iIndex);
    }

    static CShower* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
