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

class CPathWithDynamicNodes;

class CPathNode : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CPathNode);

    SCHEMA_FIELD(Vector, m_vInTangentLocal);
    SCHEMA_FIELD(Vector, m_vOutTangentLocal);
    SCHEMA_FIELD(CUtlString, m_strParentPathUniqueID);
    SCHEMA_FIELD(CUtlString, m_strPathNodeParameter);
    SCHEMA_FIELD(CTransform, m_xWSPrevParent);
    SCHEMA_FIELD(CHandle<CPathWithDynamicNodes>, m_hPath);

public:
    static CPathNode* New(const char* className)
    {
        return CBaseEntity::New<CPathNode>(className);
    }

    static CPathNode* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathNode>(iIndex);
    }

    static CPathNode* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
