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

#include "CBaseTrigger.h"
#include "fogparams_t.h"

class CFogTrigger : public CBaseTrigger
{
public:
    DECLARE_SCHEMA_CLASS(CFogTrigger);

    SCHEMA_FIELD(fogparams_t, m_fog);

public:
    static CFogTrigger* New(const char* className)
    {
        return CBaseEntity::New<CFogTrigger>(className);
    }

    static CFogTrigger* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFogTrigger>(iIndex);
    }

    static CFogTrigger* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
