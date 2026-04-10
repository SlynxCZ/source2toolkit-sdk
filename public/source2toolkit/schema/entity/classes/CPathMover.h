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

#include "CPathWithDynamicNodes.h"

class CFuncMover;
class CPathMoverEntitySpawner;

class CPathMover : public CPathWithDynamicNodes
{
public:
    DECLARE_SCHEMA_CLASS(CPathMover);

    SCHEMA_FIELD(CUtlVector<CHandle<CFuncMover>>, m_vecMovers);
    SCHEMA_FIELD(CHandle<CPathMoverEntitySpawner>, m_hMoverSpawner);
    SCHEMA_FIELD(CUtlSymbolLarge, m_iszMoverSpawnerName);

public:
    static CPathMover* New(const char* className)
    {
        return CBaseEntity::New<CPathMover>(className);
    }

    static CPathMover* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathMover>(iIndex);
    }

    static CPathMover* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
