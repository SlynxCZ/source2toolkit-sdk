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

#include "CPathSimple.h"

class CPathNode;

class CPathWithDynamicNodes : public CPathSimple
{
public:
    DECLARE_SCHEMA_CLASS(CPathWithDynamicNodes);

    SCHEMA_FIELD(CUtlVector<CHandle<CPathNode>>, m_vecPathNodes);
    SCHEMA_FIELD(CTransform, m_xInitialPathWorldToLocal);

public:
    static CPathWithDynamicNodes* New(const char* className)
    {
        return CBaseEntity::New<CPathWithDynamicNodes>(className);
    }

    static CPathWithDynamicNodes* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathWithDynamicNodes>(iIndex);
    }

    static CPathWithDynamicNodes* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
