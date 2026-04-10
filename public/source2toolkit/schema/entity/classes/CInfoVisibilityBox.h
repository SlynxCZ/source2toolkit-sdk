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

class CInfoVisibilityBox : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CInfoVisibilityBox);

    SCHEMA_FIELD(int32_t, m_nMode);
    SCHEMA_FIELD(Vector, m_vBoxSize);
    SCHEMA_FIELD(bool, m_bEnabled);

public:
    static CInfoVisibilityBox* New(const char* className)
    {
        return CBaseEntity::New<CInfoVisibilityBox>(className);
    }

    static CInfoVisibilityBox* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CInfoVisibilityBox>(iIndex);
    }

    static CInfoVisibilityBox* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
