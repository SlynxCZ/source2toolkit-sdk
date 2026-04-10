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

#include "CBaseModelEntity.h"

class CFuncNavObstruction : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncNavObstruction);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(bool, m_bUseAsyncObstacleUpdate);

public:
    static CFuncNavObstruction* New(const char* className)
    {
        return CBaseEntity::New<CFuncNavObstruction>(className);
    }

    static CFuncNavObstruction* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncNavObstruction>(iIndex);
    }

    static CFuncNavObstruction* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
