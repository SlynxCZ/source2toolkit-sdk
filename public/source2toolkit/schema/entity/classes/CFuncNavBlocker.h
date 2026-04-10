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

class CFuncNavBlocker : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFuncNavBlocker);

    SCHEMA_FIELD(bool, m_bDisabled);
    SCHEMA_FIELD(int32_t, m_nBlockedTeamNumber);

public:
    static CFuncNavBlocker* New(const char* className)
    {
        return CBaseEntity::New<CFuncNavBlocker>(className);
    }

    static CFuncNavBlocker* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFuncNavBlocker>(iIndex);
    }

    static CFuncNavBlocker* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
