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

class CPointChildModifier : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPointChildModifier);

    SCHEMA_FIELD(bool, m_bOrphanInsteadOfDeletingChildrenOnRemove);

public:
    static CPointChildModifier* New(const char* className)
    {
        return CBaseEntity::New<CPointChildModifier>(className);
    }

    static CPointChildModifier* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPointChildModifier>(iIndex);
    }

    static CPointChildModifier* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
