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
#include "CPathQueryComponent.h"

class CPathSimple : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathSimple);

    SCHEMA_FIELD(CPathQueryComponent, m_CPathQueryComponent);
    SCHEMA_FIELD(CUtlString, m_pathString);
    SCHEMA_FIELD(bool, m_bClosedLoop);

public:
    static CPathSimple* New(const char* className)
    {
        return CBaseEntity::New<CPathSimple>(className);
    }

    static CPathSimple* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathSimple>(iIndex);
    }

    static CPathSimple* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
