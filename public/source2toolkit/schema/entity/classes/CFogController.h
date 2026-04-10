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
#include "fogparams_t.h"

class CFogController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS(CFogController);

    SCHEMA_FIELD(fogparams_t, m_fog);
    SCHEMA_FIELD(bool, m_bUseAngles);
    SCHEMA_FIELD(int32_t, m_iChangedVariables);

public:
    static CFogController* New(const char* className)
    {
        return CBaseEntity::New<CFogController>(className);
    }

    static CFogController* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CFogController>(iIndex);
    }

    static CFogController* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
