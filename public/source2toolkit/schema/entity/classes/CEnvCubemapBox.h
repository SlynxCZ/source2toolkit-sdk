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

#include "CEnvCubemap.h"

class CEnvCubemapBox : public CEnvCubemap
{
public:
    DECLARE_SCHEMA_CLASS(CEnvCubemapBox);


public:
    static CEnvCubemapBox* New(const char* className)
    {
        return CBaseEntity::New<CEnvCubemapBox>(className);
    }

    static CEnvCubemapBox* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CEnvCubemapBox>(iIndex);
    }

    static CEnvCubemapBox* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
