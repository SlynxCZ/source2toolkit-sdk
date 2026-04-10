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

class CTankTargetChange : public CPointEntity
{
public:
    DECLARE_SCHEMA_CLASS(CTankTargetChange);

    SCHEMA_FIELD(CUtlSymbolLarge, m_newTargetName);

public:
    static CTankTargetChange* New(const char* className)
    {
        return CBaseEntity::New<CTankTargetChange>(className);
    }

    static CTankTargetChange* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CTankTargetChange>(iIndex);
    }

    static CTankTargetChange* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
