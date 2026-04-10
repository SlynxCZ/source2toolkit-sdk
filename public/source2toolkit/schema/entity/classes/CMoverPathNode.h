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

#include "CPathNode.h"

class CMoverPathNode : public CPathNode
{
public:
    DECLARE_SCHEMA_CLASS(CMoverPathNode);


public:
    static CMoverPathNode* New(const char* className)
    {
        return CBaseEntity::New<CMoverPathNode>(className);
    }

    static CMoverPathNode* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CMoverPathNode>(iIndex);
    }

    static CMoverPathNode* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
